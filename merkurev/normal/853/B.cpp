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

struct Fly
{
    int day, s, t, cost;
    Fly() : day(), s(), t(), cost() {}

    void read()
    {
        scanf("%d%d%d%d", &day, &s, &t, &cost);
    }
    bool operator < (const Fly &A) const
    {
        return day < A.day;
    }
};

const int N = (int) 1e6 + 100;
Fly fly[N];
long long curCost[N], sCost[N], fCost[N];
long long INF = (long long) 5e11 + 100;


int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < m; i++)
    {
        fly[i].read();
    }
    sort(fly, fly + m);
    vector <Fly> toCapital, fromCapital;
    for (int i = 0; i < m; i++)
        if (fly[i].s == fly[i].t) continue;
        else if (fly[i].s == 0) fromCapital.push_back(fly[i] );
        else toCapital.push_back(fly[i] );


    for (int i = 0; i < N; i++)
        sCost[i] = fCost[i] = INF;

    int ptr = 0;
    long long sumCost = 0;
    for (int i = 1; i <= n; i++)
    {
        curCost[i] = INF;
        sumCost += curCost[i];
    }

    for (int day = 0; day < N; day++)
    {
        while (ptr < (int) toCapital.size() && toCapital[ptr].day == day)
        {
            Fly f = toCapital[ptr++];

            if (f.cost < curCost[f.s] )
            {
                sumCost -= curCost[f.s];
                curCost[f.s] = f.cost;
                sumCost += curCost[f.s];
            }
        }
        if (day + k + 1 < N)
            sCost[day + k + 1] = sumCost;
    }
    
    reverse(fromCapital.begin(), fromCapital.end() );
    ptr = 0;
    sumCost = 0;
    for (int i = 1; i <= n; i++)
    {
        curCost[i] = INF;
        sumCost += curCost[i];
    }
    for (int day = N - 1; day >= 0; day--)
    {
        while (ptr < (int) fromCapital.size() && fromCapital[ptr].day == day)
        {
            Fly f = fromCapital[ptr++];

            if (f.cost < curCost[f.t] )
            {
                sumCost -= curCost[f.t];
                curCost[f.t] = f.cost;
                sumCost += curCost[f.t];
            }
        }
        if (day < N)
            fCost[day] = sumCost;
    }

    long long ans = INF;
    for (int i = 0; i < N; i++)
        ans = min(ans, sCost[i] + fCost[i] );
    if (ans >= INF) ans = -1;
    printf("%lld\n", ans);


	return 0;
}