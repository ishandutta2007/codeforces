#include <bitset>
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

const int N = (int) 1e4 + 1;

bitset <N> ans, st;

struct Qu
{
    int l, r, x;
    Qu(int _l, int _r, int _x) : l(_l), r(_r), x(_x) {}
};


void addDp(bitset <N> &dp, int x)
{
    dp |= (dp << x);
}

void solve(int l, int r, vector <Qu> &qu, bitset <N> &dp)
{
//    eprintf("l = %d, r = %d\n", l, r);
    if (l == r)
    {
        ans |= dp;
        return;
    }
    int m = (l + r) / 2;
    vector <Qu> lqu, rqu;
    bitset <N> ldp = dp, rdp = dp;
    for (Qu &q : qu)
    {
        if (q.l <= l && q.r >= m)
            addDp(ldp, q.x);
        else if (q.l >= l && q.l <= m)
            lqu.push_back(q);
        else if (q.r >= l && q.r <= m)
            lqu.push_back(q);

        if (q.l <= m + 1 && q.r >= r)
            addDp(rdp, q.x);
        else if (q.l >= m + 1 && q.l <= r)
            rqu.push_back(q);
        else if (q.r >= m + 1 && q.r <= r)
            rqu.push_back(q);
    }
    solve(l, m, lqu, ldp);
    solve(m + 1, r, rqu, rdp);
}

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    vector <Qu> qu;
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 0; i < q; i++)
    {
        int l, r, x;
        scanf("%d%d%d", &l, &r, &x);
        l--;
        r--;
        qu.emplace_back(l, r, x);
    }
    st[0] = 1;
    solve(0, n, qu, st);

    vector <int> answ;
    for (int i = 1; i <= n; i++)
        if (ans[i] )
            answ.push_back(i);
    printf("%d\n", (int) answ.size() );
    for (int x : answ)
        printf("%d ", x);
    printf("\n");


	return 0;
}