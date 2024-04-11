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


const int N = (int) 2e5 + 100;
char str[N];

pair <int, int> readPoint()
{
    scanf("%s", str);
    int n = strlen(str);
    int cb = 0, cn = 0;
    for (int i = 0; i < n; i++)
        if (str[i] == 'B')
            cb++;
        else
            cn++;
    return make_pair(cb, cn);
}

vector <pair <int, int>> pts;

const int INF = (int) 1e9;

int ansb, ansn;

bool good(int d)
{
    for (int t = 0; t < 2; t++)
    {
        int down = t;
        int up = INF;
        int left = 1 - t;
        int right = INF;
        int minyx = -INF;
        int maxyx = INF;

        for (auto &p : pts)
        {
            int x = p.first, y = p.second;
    //        eprintf("x = %d, y = %d\n", x, y);
            left = max(left, x - d);
            right = min(right, x + d);
            down = max(down, y - d);
            up = min(up, y + d);
            minyx = max(minyx, y - x - d);
            maxyx = min(maxyx, y - x + d);
        }

    //    eprintf("[%d, %d] x [%d, %d] x [%d, %d]\n", left, right, down, up, minyx, maxyx);

        vector <pair <int, int>> test =
        {
            {left, down},
            {left, up},
            {right, down},
            {right, up},
            {left, maxyx + left},
            {right, maxyx + right},
            {left, minyx + left},
            {right, minyx + right},
            {up - maxyx, up},
            {down - maxyx, down},
            {up - minyx, up},
            {down - minyx, down},
        };

        for (auto &p : test)
        {
            int x = p.first, y = p.second;
            ansb = x;
            ansn = y;

            if (x >= left && x <= right && y >= down && y <= up && y - x >= minyx && y - x <= maxyx)
                return true;
        }
    }
    return false;
}


int main(int,  char **)
{
#ifdef LOCAL
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        pts.push_back(readPoint());

    int l = -1, r = (int) 1e6;
    // r - good


    while (r - l > 1)
    {
        int m = (l + r) / 2;
        if (good(m))
            r = m;
        else
            l = m;
    }
    good(r);
    printf("%d\n", r);
    int sz = 0;
    for (int i = 0; i < ansb; i++)
        str[sz++] = 'B';
    for (int i = 0; i < ansn; i++)
        str[sz++] = 'N';
    str[sz] = 0;
#ifndef LOCAL
    printf("%s\n", str);
#endif

	return 0;
}