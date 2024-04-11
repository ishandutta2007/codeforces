#ifndef LOCAL
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")
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


const int K = 3;
const int T = 1005;
int x[K], y[K];

vector <pair <int, int>> pts;
void addPts(int x1, int y1, int x2, int y2)
{
    while (x1 != x2)
    {
        pts.emplace_back(x1, y1);
        if (x1 < x2) x1++;
        else x1--;
    }
    while (y1 != y2)
    {
        pts.emplace_back(x1, y1);
        if (y1 < y2)
            y1++;
        else
            y1--;
    }
    pts.emplace_back(x1, y1);
}

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    for (int i = 0; i < 3; i++)
        scanf("%d%d", &x[i], &y[i]);

    int bst = T * T;
    int bx = -1, by = -1;
    for (int i = 0; i <= T; i++)
        for (int j = 0; j <= T; j++)
        {
            int cur = 1;
            for (int h = 0; h < 3; h++)
            {
                int d = abs(i - x[h]) + abs(j - y[h]);
                cur += d;
            }
            if (cur < bst)
            {
                bst = cur;
                bx = i;
                by = j;
            }
        }

    for (int h = 0; h < 3; h++)
        addPts(bx, by, x[h], y[h]);
    sort(pts.begin(), pts.end());
    pts.resize(unique(pts.begin(), pts.end()) - pts.begin());
    if ((int) pts.size() != bst)
    {
        eprintf("%d %d\n", (int) pts.size(), bst);
        throw;
    }
    printf("%d\n", bst);
    for (auto p : pts)
        printf("%d %d\n", p.first, p.second);

	return 0;
}