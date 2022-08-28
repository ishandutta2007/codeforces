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

int let(char c)
{
    if (c == 'S')
        return 0;
    if (c == 'R')
        return 1;
    if (c == 'P')
        return 2;
    throw;
}

const int N = (int) 2e5 + 100;
int qu[N][2], _a[N], a[N];
char str[N];
int fn[N];
set <int> pos0, pos2;


void tree_add(int pos, int x)
{
    pos++;
    for (; pos < N; pos = (pos | (pos - 1)) + 1)
        fn[pos] += x;
}


int pref_sum(int pos)
{
    pos++;
    int ans = 0;
    for (; pos > 0; pos = (pos & (pos - 1)))
        ans += fn[pos];
    return ans;
}

int tree_sum(int l, int r)
{
    return pref_sum(r) - pref_sum(l - 1);
}


void addVal(int i, int x)
{
    if (x == 0)
        pos0.insert(i);
    else if (x == 2)
        pos2.insert(i);
    else
        tree_add(i, 1);
}

void subVal(int i, int x)
{
    if (x == 0)
        pos0.erase(i);
    else if (x == 2)
        pos2.erase(i);
    else
        tree_add(i, -1);
}

int ans[N];
void solve(int n, int q)
{
    //eprintf("-- solve --\n");
    memset(fn, 0, sizeof fn);
    pos0.clear();
    pos2.clear();

    for (int i = 0; i < n; i++)
        addVal(i, a[i]);
       
    for (int i = 0; i <= q; i++)
    {
#ifdef LOCAL
        //eprintf(">> i = %d\n", i);
        //for (int j = 0; j < n; j++)
        //    eprintf("%d ", a[j]); eprintf("\n");
#endif

        vector <pair<int, int>> badSeg;
        if (!pos2.empty())
        {
            if (pos0.empty())
            {
                badSeg.emplace_back(0, n - 1);
            }
            else
            {
                if (*pos0.begin() > *pos2.begin())
                    badSeg.emplace_back(*pos2.begin(), *pos0.begin() - 1);
                if (*pos0.rbegin() < *pos2.rbegin())
                    badSeg.emplace_back(*pos0.rbegin() + 1, *pos2.rbegin());
            }
        }
        sort(badSeg.begin(), badSeg.end());
        if (badSeg.size() == 2)
        {
            if (badSeg[1].first <= badSeg[0].second)
            {
                badSeg[0] = make_pair(badSeg[0].first, max(badSeg[0].second, badSeg[1].second));
                badSeg.pop_back();
            }
        }
        int cur = n - (int) pos0.size() - (int) pos2.size();
        for (auto p : badSeg)
            cur -= tree_sum(p.first, p.second);
        ans[i] += cur;

        if (i == q) continue;
    
        int pos = qu[i][0];
        subVal(pos, a[pos]);
        a[pos] = qu[i][1];
        addVal(pos, a[pos]);
    }
}

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int n, q;
    scanf("%d%d", &n, &q);
    scanf("%s", str);
    for (int i = 0; i < n; i++)
        _a[i] = let(str[i]);
    
    for (int i = 0; i < q; i++)
    {
        int x;
        char ch[2];
        scanf("%d%s", &x, ch);
        qu[i][0] = x - 1;
        qu[i][1] = let(ch[0]);
    }

    for (int it = 0; it < 3; it++)
    {
        for (int i = 0; i < n; i++)
            a[i] = (_a[i] + it) % 3;
        solve(n, q);
        for (int i = 0; i < q; i++)
            qu[i][1] = (qu[i][1] + 1) % 3;
    }

    for (int i = 0; i <= q; i++)
        printf("%d\n", ans[i]);


	return 0;
}