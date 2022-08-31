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


const int K = 12;
const int N = (1 << K);
const int N3 = 550550;
int cnt[N];
int deg3[K];
int cnt3[N3];
map <char, vector<int>> ops;

void init()
{
    deg3[0] = 1;
    for (int i = 1; i < K; i++)
        deg3[i] = deg3[i - 1] * 3;
    ops['X'] = {0, 2};
    ops['x'] = {1};
    ops['o'] = {1, 2};
    ops['O'] = {0};
    ops['a'] = {2};
    ops['A'] = {0, 1};
}

void add(int a, int b, int x)
{
    if (x == 0) return;
    int v = 0;
    for (int i = 0; i < K; i++)
    {
        int c = ((a >> i) & 1) + ((b >> i) & 1);
        v += deg3[i] * c;
    }
//    eprintf("cnt3[%d] += %d\n", v, x);
    cnt3[v] += x;
}

char str[K + 1];
vector <int> op[K];
int w, ans;

void gen(int pos, int val)
{
    if (pos == w)
    {
//        eprintf("at : %d\n", val);
        ans += cnt3[val];
        return;
    }
    for (int x : op[pos])
        gen(pos + 1, val + deg3[pos] * x);
}

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
    init();

    int n, m;
    scanf("%d%d%d", &w, &n, &m);
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        cnt[x]++;
    }
    for (int i = 0; i < N; i++)
    {
        add(i, i, cnt[i] * cnt[i]);
        for (int j = i + 1; j < N; j++)
            add(i, j, 2 * cnt[i] * cnt[j]);
    }
    for (int it = 0; it < m; it++)
    {
        for (int i = 0; i < K; i++)
            op[i].clear();
        scanf("%s", str);
        reverse(str, str + w);
        ans = 0;
        for (int i = 0; i < w; i++)
        {
            op[i] = ops[str[i]];
//            eprintf("%c %d %d\n", str[i], (int) ops[str[i]].size(), (int) op[i].size());
        }
        gen(0, 0);
        printf("%d\n", ans);
    }


	return 0;
}