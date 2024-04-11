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


const int N = 255;
int a[N][N];
int maxr[N], maxc[N];

bool cmpR(int x, int y)
{
    return a[x][maxc[x]] > a[y][maxc[y]];
}

bool cmpC(int x, int y)
{
    return a[maxr[x]][x] > a[maxc[y]][y];
}

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &a[i][j]);
            if (a[i][j] > a[i][maxc[i]])
                maxc[i] = j;
            if (a[i][j] > a[maxr[j]][j])
                maxr[j] = i;
        }

    vector <int> rest;
    vector <pair <int, pair <int, int>>> v; 

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (maxr[j] == i && maxc[i] == j)
            {
                v.emplace_back(a[i][j], make_pair(1, 1));
            }
            else if (maxr[j] == i)
            {
                v.emplace_back(a[i][j], make_pair(0, 1));
            }
            else if (maxc[i] == j)
            {
                v.emplace_back(a[i][j], make_pair(1, 0));
            }
            else
            {
                rest.push_back(a[i][j]);
            }
    sort(v.begin(), v.end());
    sort(rest.begin(), rest.end());
    reverse(rest.begin(), rest.end());

    int ci = 0, cj = 0;
    memset(a, -1, sizeof a);
    for (int it = 0; it < (int) v.size(); it++)
    {
        a[ci][cj] = v[it].first;
        if (v[it].second.first)
        {
            for (int j = m - 1; j > cj; j--)
            {
                a[ci][j] = rest.back();
                rest.pop_back();
            }
        }
        if (v[it].second.second)
        {
            for (int i = n - 1; i > ci; i--)
            {
                a[i][cj] = rest.back();
                rest.pop_back();
            }
        }
        ci += v[it].second.first;
        cj += v[it].second.second;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }

	return 0;
}