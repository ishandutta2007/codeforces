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


const int N = (int)1e5 + 100;
int l[N][2], r[N][2];


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
        for (int t = 0; t < 2; t++)
            scanf("%d%d", &l[i][t], &r[i][t]);
    }

    for (int t = 0; t < 2; t++)
    {
        eprintf("----\n");
        vector <pair <int, pair <int, int>>> ev;

        for (int i = 0; i < n; i++)
        {
            ev.emplace_back(l[i][t], make_pair(0, i)); // open
            ev.emplace_back(r[i][t], make_pair(1, i)); // close
        }
        sort(ev.begin(), ev.end());

        multiset <int> ls, rs;

        int ltp = ev[0].second.first;
        int lt = ev[0].first;
        for (int i = 0; i <= (int) ev.size(); i++)
        {
            if (i == (int) ev.size() || ev[i].first != lt || ev[i].second.first != ltp)
            {
                if (!ls.empty() && *ls.rbegin() > *rs.begin())
                {
                    printf("NO\n");
                    return 0;
                }
            }
            if (i == (int) ev.size())
                break;
            auto p = ev[i];
            lt = p.first;
            ltp = p.second.first;
            int tp = p.second.first;
            int id = p.second.second;

            eprintf("%d %d %d\n", p.first, tp, id);
            if (tp == 0)
            {
                ls.insert(l[id][t ^ 1]);
                rs.insert(r[id][t ^ 1]);
            }
            else
            {
                ls.erase(ls.find(l[id][t ^ 1]));
                rs.erase(rs.find(r[id][t ^ 1]));
            }
        }
    }
    printf("YES\n");

	return 0;
}