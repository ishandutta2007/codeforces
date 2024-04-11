#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <numeric>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long int int64;


const int MOD = (int) 1e9 + 7;
void sadd(int &a, int b)
{
    a += b;
    if (a >= MOD) a -= MOD;
}
int add(int a, int b)
{
    sadd(a, b);
    return a;
}
void ssub(int &a, int b)
{
    a -= b;
    if (a < 0) a += MOD;
}
int sub(int a, int b)
{
    ssub(a, b);
    return a;
}
int mul(int a, int b)
{
    return (a * 1LL * b) % MOD;
}
int fpow(int x, int n)
{
    if (n == 0) return 1;
    int a = fpow(x, n >> 1);
    a = mul(a, a);
    if (n & 1) a = mul(a, x);
    return a;
}



const int LOG = 19;
const int LEVEL = (1 << LOG);
const int SIZE = (LEVEL << 1);

struct Tree
{
    int sum;
    int val[SIZE];
    int ptr;

    Tree () : sum(), val(), ptr() {}

    void addVal(int pos, int x)
    {
#ifdef LOCAL
        if (pos < ptr - 1) throw;
#endif
        sadd(val[pos], x);
        sadd(sum, x);
        ptr = min(ptr, pos);
    }

    void setZero(int l, int r)
    {
        if (l != 0) throw;
        while(ptr <= r)
        {
            ssub(sum, val[ptr] );
            val[ptr] = 0;
            ptr++;
        }
    }

    int getSum()
    {
        return sum;
    }

} tree[2];


int n[2];
vector <int> pts;
vector <pair <int, int> > segs[2];
vector <pair <int, int> > hends[LEVEL];

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
    
    int k;
    scanf("%d%d%d", &k, &n[0], &n[1]);
    for (int t = 0; t < 2; t++)
    {
        for (int i = 0; i < n[t]; i++)
        {
            int l, r;
            scanf("%d%d", &l, &r);
            l--;
            r--;
            segs[t].emplace_back(l, r + 1);
            pts.push_back(l);
            pts.push_back(r + 1);
        }
    }
    pts.push_back(-1);
    pts.push_back(0);
    pts.push_back(k);
    sort(pts.begin(), pts.end() );
    pts.resize(unique(pts.begin(), pts.end() ) - pts.begin() );

    for (int t = 0; t < 2; t++)
    {
        for (auto &p : segs[t] )
        {
            p.first = lower_bound(pts.begin(), pts.end(), p.first) - pts.begin();
            p.second = lower_bound(pts.begin(), pts.end(), p.second) - pts.begin();

            hends[p.second].emplace_back(t, p.first);
        }
    }
   
    tree[0].addVal(0, 1);
    int T = (int) pts.size();
    pts.push_back(k); // one more time

    for (int i = 1; i < T; i++)
    {
        int sz = pts[i + 1] - pts[i];
        int two = sub(fpow(2, sz), 2);

        for (auto p : hends[i] )
        {
            int t = p.first;
            int st = p.second;
            tree[t ^ 1].setZero(0, st - 1);
        }
        int x[2];
        for (int t = 0; t < 2; t++)
            x[t] = tree[t ^ 1].getSum();
        if (i > 0)
        {
            for (int t = 0; t < 2; t++)
                tree[t].addVal(i - 1, x[t] );
        }
        tree[0].addVal(i, mul(two, add(x[0], x[1] ) ) );
    }
    int ans = add(tree[0].getSum(), tree[1].getSum() );
    printf("%d\n", ans);

	return 0;
}