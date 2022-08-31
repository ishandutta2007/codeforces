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

const int DX[4] = {-1, 0, 0, 1};
const int DY[4] = {0, -1, 1, 0};

const int INF = (int) 1e9;
const int N = 1005;
char f[N][N];
int dist[N][N];

int n, m;

bool inF(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < m;
}

const int SZ = N * N;
pair <int, int> qu[SZ];


int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int q;
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 0; i < n; i++)
        scanf("%s", f[i]);

    int r = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            dist[i][j] = INF;
            for (int d = 0; d < 4; d++)
            {
                int ni = i + DX[d];
                int nj = j + DY[d];
                if (!inF(ni, nj) || f[ni][nj] != f[i][j])
                    continue;
                dist[i][j] = 0;
            }
            if (dist[i][j] == 0)
            {
                qu[r++] = make_pair(i, j);
            }
        }

    for (int l = 0; l < r; l++)
    {
        int x = qu[l].first;
        int y = qu[l].second;

        for (int d = 0; d < 4; d++)
        {
            int nx = x + DX[d];
            int ny = y + DY[d];
            if (!inF(nx, ny) || dist[nx][ny] != INF)
                continue;
            dist[nx][ny] = dist[x][y] + 1;
            qu[r++] = make_pair(nx, ny);
        }
    }

    for (int it = 0; it < q; it++)
    {
        int x, y;
        long long p;
        scanf("%d%d%lld", &x, &y, &p);
        x--;
        y--;
        //eprintf(">>%d\n", dist[x][y]);

        long long sw = max(0LL, p - dist[x][y]);
        if (dist[x][y] == INF)
            sw = 0;
        sw %= 2;

        printf("%lld\n", (f[x][y] - '0') ^ sw);
    }


	return 0;
}