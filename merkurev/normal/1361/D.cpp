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
#include <queue>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long int int64;

const double INF = 1e100;

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

double sqr(double x)
{
    return x * x;
}

map <pair <int, int>, vector <double>> m;

const int N = (int) 5e5 + 100;
vector <double> v[N];
int cnt[N];

int k;

double getReward(int id)
{
    if (cnt[id] == (int) v[id].size())
        return -INF;
    double cd = v[id][(int) v[id].size() - 1 - cnt[id]];
    double ans = cd * ((k - cnt[id] - 1) - cnt[id]);
    return ans;
}

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int n;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        int g = gcd(abs(x), abs(y));
        if (x == 0 && y == 0)
            continue;
        pair <int, int> p = make_pair(x / g, y / g);
        double d = sqrt(sqr(x) + sqr(y));
        m[p].push_back(d);
    }
    int sz = 0;
    for (auto p : m)
    {
        v[sz] = p.second;
        sort(v[sz].begin(), v[sz].end());
        sz++;
    }
    m.clear();

    priority_queue <pair <double, int>> qu;
    for (int i = 0; i < sz; i++)
    {
        double reward = getReward(i);
        //eprintf("%d) %.5lf\n", i, reward);
        qu.push(make_pair(reward, i));
    }
    double ans = 0;
    int taken = 0;
    int lastId = -1;
    while (!qu.empty())
    {
        if (taken == k)
            break;
        auto p = qu.top();
        int id = p.second;
        qu.pop();
        if (p.first < 0)
        {
            lastId = id;
            taken++;
            break;
        }
        ans += p.first;
        cnt[id]++;
        double reward = getReward(id);
        //eprintf("%d) %.5lf\n", id, reward);
        qu.push(make_pair(reward, id));
        taken++;
    }

    if (lastId != -1)
    {
        int id = lastId;
        for (int i = k - taken - 1; i >= 0; i--)
        {
            double cd = v[id][i];
            double cans = cd * ((k - cnt[id] - 1) - cnt[id]);
            ans += cans;
            //eprintf("cans = %.5lf\n", cans);
            cnt[id]++;
        }
    }

    printf("%.10lf\n", ans);


	return 0;
}