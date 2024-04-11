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


const int N = (int) 1e6 + 100;
long long ans[N];


int main(int,  char **)
{
#ifdef LOCAL
	//freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    set <pair <long long, int>> ev;

    int n, pp;
    scanf("%d%d", &n, &pp);
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        ev.insert(make_pair(x, -1 - i));
    }

    set <int> wait;
    set <int> inq;
    int busy = 0;
    long long curt = 0;

    while (!ev.empty())
    {
        auto p = *ev.begin();
        ev.erase(ev.begin());
        curt = p.first;

        eprintf("%lld %d\n", p.first, p.second);

        if (p.second < 0)
        {
            wait.insert(-p.second - 1);
        }
        else
        {
            busy = 0;
            inq.erase(p.second);
        }

        if (!ev.empty() && ev.begin()->first == curt)
            continue;

        if (!wait.empty())
        {
            int id = *wait.begin();
            eprintf("curt = %lld, id = %d\n", curt, id);
            if (inq.empty() || id < *inq.begin())
            {
                eprintf("!!\n");
                wait.erase(id);
                inq.insert(id);
            }
        }
    
        if (!busy && !inq.empty())
        {
            int id = *inq.rbegin();
            //wait.erase(wait.begin());
            //eprintf("id = %d\n", id);
            ans[id] = curt;
            busy = 1;
            ev.insert(make_pair(curt + pp, id));
        }

    }


    for (int i = 0; i < n; i++)
        printf("%lld ", ans[i] + pp);
    printf("\n");


	return 0;
}