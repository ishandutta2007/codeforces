#ifndef LOCAL
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#endif

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


const int INF = (int) 2e9;
const int N = 85;
int d[N][N];

pair <int, int> d2[N][N][N];
int ptr2[N][N];
int sz2[N][N];
int taken[N];

int n, k;
int need;

int ans = INF;
int st[N];

void gen(int cit)
{
    if (cit == need)
    {
        if (ptr2[st[0]][st[1]] == sz2[st[0]][st[1]])
            return;
        st[need] = st[0];
        int cur = 0;
        for (int i = 0; i < need; i++)
            cur += d2[st[i]][st[i + 1]][ptr2[st[i]][st[i + 1]]].first;
        if (cur < ans)
            ans = cur;
        return;
    }
    int sh[8];
    for (int i = 0; i < n; i++)
    {
        memset(sh, 0, sizeof sh);
        st[cit] = i;
        taken[i]++;
        st[cit + 1] = 0;
        for (int j = 0; j <= cit; j++)
        {
            int a = st[j], b = st[j + 1];
            while (taken[d2[a][b][ptr2[a][b]].second])
            {
                ptr2[a][b]++;
                sh[j]++;
            }
        }
        gen(cit + 1);
        st[cit + 1] = 0;
        for (int j = 0; j <= cit; j++)
        {
            int a = st[j], b = st[j + 1];
            ptr2[a][b] -= sh[j];
        }
        taken[i]--;
    }
}

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &d[i][j]);

    for (int a = 0; a < n; a++)
        for (int b = 0; b < n; b++)
        {
            for (int c = 1; c < n; c++) // 0 always taken
            {
                if (c == a || c == b)
                    continue;
                int cur = d[a][c] + d[c][b];
                d2[a][b][sz2[a][b]++] = make_pair(cur, c);
            }
            sort(d2[a][b], d2[a][b] + sz2[a][b]);
        }
    for (int a = 0; a < n; a++)
        for (int b = 0; b < n; b++)
            d2[a][b][sz2[a][b]] = make_pair(-1, -1);
    need = k / 2;
    gen(1);

    printf("%d\n", ans);

	return 0;
}