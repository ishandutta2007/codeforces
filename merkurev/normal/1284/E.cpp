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


struct Point
{
    long long x, y;
    
    Point() : x(), y() {}
    
    Point(long long _x, long long _y) : x(_x), y(_y) {}

    Point operator + (const Point &A) const
    {
        return Point(x + A.x, y + A.y);
    }
    Point operator - (const Point &A) const
    {
        return Point(x - A.x, y - A.y);
    }
    long long operator % (const Point &A) const
    {
        return x * A.x + y * A.y;
    }
    long long operator * (const Point &A) const
    {
        return x * A.y - y * A.x;
    }

    void read()
    {
        scanf("%lld%lld", &x, &y);
    }

};


int side(Point P)
{
    if (P.x > 0 || (P.x == 0 && P.y < 0))
        return 0;
    return 1;
}

bool cmpAng(const pair <Point, pair <int, int>> &p1, const pair <Point, pair <int, int>> &p2)
{
    if (side(p1.first) != side(p2.first))
        return side(p1.first) < side(p2.first);
    return p1.first * p2.first < 0;
}


const int N = 3000;
int pos[N];
int posR[N];
Point P[N];

long long f(long long x)
{
    return x * (x - 1) * (x - 2) / 6;
}

int up[N][N];

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        P[i].read();
    }

    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        vector <pair <Point, pair <int, int>>> vs;
        for (int j = 0; j < n; j++)
        {
            if (i == j) continue;
            Point v = P[j] - P[i];
            vs.emplace_back(v, make_pair(j, 1));
            vs.emplace_back(Point() - v, make_pair(j, -1));
        }
        sort(vs.begin(), vs.end(), cmpAng);

        int it = 0;
        for (int j = 0; j < (int) vs.size(); j++)
        {
            if (vs[j].second.second == 1)
            {
                it++;
                pos[vs[j].second.first] = it;
            }
            else
                posR[vs[j].second.first] = it;
        }
        for (int j = 0; j < n; j++)
        {
            if (i == j) continue;

            up[i][j] = posR[j] - pos[j];
            if (up[i][j] < 0)
                up[i][j] += n - 1;
        
            ans += f(up[i][j]);
        }
    }
    ans = -ans;
    long long nl = n;
    ans += nl * (nl - 1) * (nl - 2) * (nl - 3) * (nl - 4) / 24;

    printf("%lld\n", ans);



	return 0;
}