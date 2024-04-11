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




struct Seg
{
    int l, r, val;
    Seg() : l(), r(), val() {}
    Seg(int _l, int _r, int _val) : l(_l), r(_r), val(_val) {}

    void eprint()
    {
        eprintf("[%d, %d] + %d\n", l, r, val);
    }
};

struct State
{
    int cnt;
    vector <pair<int, long long>> groups; // mn, sum

    State() : cnt(), groups() {}

    void add(int val)
    {
        cnt++;
        auto pos = lower_bound(groups.begin(), groups.end(), make_pair(val, 0LL));
        groups.insert(pos, make_pair(val, val * 1LL));
        int sz = 0;
        long long sum = 0;
        
        for (int i = 0; i < (int) groups.size(); i++)
        {
            if (groups[i].first <= 2 * sum)
                groups[sz - 1].second += groups[i].second;
            else
                groups[sz++] = groups[i];

            sum += groups[i].second;
        }
        groups.resize(sz);
    }

    int ans()
    {
        return cnt - (int) groups.size();
    }
};

const int N = (int) 5e5 + 100;
int ans[N];

void solve(int l, int r, vector <Seg> &segs, State st)
{
    int sz = 0;
    for (auto seg : segs)
    {
        if (seg.l <= l && seg.r >= r)
            st.add(seg.val);
        else
            segs[sz++] = seg;
    }
    segs.resize(sz);

    if (l == r)
    {
        ans[l] = st.ans();
        return;
    }

    int m = (l + r) / 2;
    vector <Seg> sl, sr;

    for (auto seg : segs)
    {
        if (seg.l <= m)
            sl.push_back(seg);
        if (seg.r >= m + 1)
            sr.push_back(seg);
    }
    solve(l, m, sl, st);
    solve(m + 1, r, sr, st);
}

map <int, vector <int>> m;
int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int q;
    scanf("%d", &q);

    vector <Seg> qs;
    for (int i = 0; i < q; i++)
    {
        char ch[2];
        int x;
        scanf("%s%d", ch, &x);
        if (ch[0] == '+')
        {
            if (!m.count(x))
                m[x] = {};
            m[x].push_back(i);
        }
        else
        {
            int st = 0;
            if (!m.count(x))
                m[x] = {};
            if (!m[x].empty())
            {
                st = m[x].back();
                m[x].pop_back();
            }
            qs.emplace_back(st, i - 1, x);
        }
    }
    for (auto p : m)
        for (int st : p.second)
            qs.emplace_back(st, q - 1, p.first);

    //for (auto seg : qs)
    //    seg.eprint();

    solve(0, q - 1, qs, State());
    for (int i = 0; i < q; i++)
        printf("%d\n", ans[i]);

	return 0;
}