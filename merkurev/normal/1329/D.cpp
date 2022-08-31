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
const int ALP = 26;
int cnt[ALP];
vector <pair <int, int>> evs;
vector <pair <int, int>> ans;
vector <int> st;

set <int> seps;

set <pair <int, int>> neis[ALP][ALP];

void addPair(int a, int b)
{
    if (a > b)
        swap(a, b);

    int ca = str[a] - 'a';
    int cb = str[b] - 'a';

    if (ca == cb)
        return;

    neis[ca][cb].insert(make_pair(a, b));
    neis[cb][ca].insert(make_pair(a, b));
}

void solve()
{
    for (int i = 0; i < ALP; i++)
    {
        cnt[i] = 0;
    }
    seps.clear();
    st.clear();
    evs.clear();
    ans.clear();

    str[0] = 0;
    scanf("%s", str);
    int n = strlen(str);

    if (n == 0 || n >= N)
        throw;

    int lst = -1;
    for (int i = 0; i + 1 < n; i++)
        if (str[i] == str[i + 1])
        {
            if (lst != -1)
                addPair(lst, i);
            lst = i;
            seps.insert(i);
            cnt[str[i] - 'a']++;
        }


    while (true)
    {
        int bst = 0;
        for (int i = 0; i < ALP; i++)
            if (cnt[i] > cnt[bst])
                bst = i;
        if (cnt[bst] == 0)
            break;

        eprintf("bst = %d, cnt = %d\n", bst, cnt[bst]);
        bool fnd = false;

        for (int i = 0; i < ALP; i++)
        {
            if (i == bst)
                continue;
            if (neis[bst][i].empty())
                continue;

            fnd = true;
            auto p = *neis[bst][i].begin();
            int a = p.first;
            int b = p.second;

            neis[bst][i].erase(p);
            neis[i][bst].erase(p);

            seps.erase(a);
            seps.erase(b);
            
            cnt[bst]--;
            cnt[i]--;
            
            auto it = seps.lower_bound(a);
            if (it != seps.begin())
            {
                auto pit = it;
                pit--;
                int c = *pit;
                int cc = str[c] - 'a';

                neis[cc][bst].erase(make_pair(c, a));
                neis[bst][cc].erase(make_pair(c, a));
                neis[cc][i].erase(make_pair(c, a));
                neis[i][cc].erase(make_pair(c, a));

                if (it != seps.end())
                {
                    addPair(*pit, *it);
                }
            }
                
            if (it != seps.end())
            {
                int d = *it;
                int cd = str[d] - 'a';

                neis[cd][bst].erase(make_pair(b, d));
                neis[bst][cd].erase(make_pair(b, d));
                neis[cd][i].erase(make_pair(b, d));
                neis[i][cd].erase(make_pair(b, d));
            }
            
            eprintf("a = %d, b = %d\n", a, b);
            evs.emplace_back(a, 0);
            evs.emplace_back(b, 1);
            break;
        }
        if (!fnd)
            break;
    }
    
    for (int x : seps)
        evs.emplace_back(x, -1);

    sort(evs.begin(), evs.end());
    int rm = 0;

    for (auto p : evs)
    {
        if (p.second == 0)
            st.push_back(p.first - rm);
        else if (p.second == 1)
        {
            ans.emplace_back(st.back(), p.first - rm);
            rm += ans.back().second - ans.back().first;
            st.pop_back();
        }
        else
        {
            ans.emplace_back(p.first - rm, p.first - rm + 1);
            rm++;
        }
    }

    n -= rm;

    //calcVs();
    ans.emplace_back(-1, n - 1);

    eprintf("str = %s\n", str);
    printf("%d\n", (int) ans.size());
    for (auto p : ans)
        printf("%d %d\n", p.first + 2, p.second + 1);
}


int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
        solve();


	return 0;
}