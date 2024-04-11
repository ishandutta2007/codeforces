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


vector <int> g, r[2];

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
        char ch[2];
        int x;
        scanf("%d%s",  &x, ch);
        if (ch[0] == 'G')
            g.push_back(x);
        else if (ch[0] == 'R')
            r[0].push_back(x);
        else
            r[1].push_back(x);
    }
//    sort(g.begin(), g.end() );
//    for (int t = 0; t < 2; t++)
//        sort(r[t].begin(), r[t].end() );

    if (r[0].empty() && r[1].empty() )
    {
        printf("%d\n", *g.rbegin() - *g.begin() );
        return 0;
    }

    long long ans = 0;
    int pr[2] = {0, 0};
    for (int i = 0; i <= (int) g.size(); i++)
    {
        int npr[2] = {pr[0], pr[1]};

        for (int t = 0; t < 2; t++)
            while (npr[t] < (int) r[t].size() && (i == (int) g.size() || r[t][npr[t]] <= g[i] ) )
                npr[t]++;
        long long mgr[2] = {0, 0};

        if (i == 0 && i == (int) g.size() )
        {
            for (int t = 0; t < 2; t++)
                if (npr[t] != pr[t] )
                    ans += r[t][npr[t] - 1] - r[t][pr[t] ];
        }
        else if (i == 0)
        {
            for (int t = 0; t < 2; t++)
                if (npr[t] != pr[t] )
                    ans += g[i] - r[t][pr[t] ];
        }
        else if (i == (int) g.size() )
        {
            for (int t = 0; t < 2; t++)
                if (npr[t] != pr[t] )
                    ans += r[t][npr[t] - 1] - g[i - 1];
        }
        else
        {
            for (int t = 0; t < 2; t++)
            {
                if (pr[t] == npr[t] )
                {
                    mgr[t] = -1;
                    continue;
                }
                mgr[t] = max(mgr[t], (long long) r[t][pr[t] ] - g[i - 1] );
                mgr[t] = max(mgr[t], (long long) g[i] - r[t][npr[t] - 1] );
                
                for (int j = pr[t]; j + 1 < npr[t]; j++)
                    mgr[t] = max(mgr[t], (long long) r[t][j + 1] - r[t][j] );
            }

            long long gap = g[i] - g[i - 1];
            long long cur = 2 * gap;

            eprintf("gap = %lld\n", gap);

            if (mgr[0] == -1 && mgr[1] == -1)
                cur = gap;
            else if (mgr[0] == -1)
                cur = 2 * gap - mgr[1];
            else if (mgr[1] == -1)
                cur = 2 * gap - mgr[0];
            else
                cur = min(cur, 3 * gap - mgr[0] - mgr[1] );
       
            eprintf("cur = %lld\n", cur);
            ans += cur;
        }

        pr[0] = npr[0];
        pr[1] = npr[1];
    }
    printf("%lld\n", ans);




	return 0;
}