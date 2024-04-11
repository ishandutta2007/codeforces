#include <algorithm>
#include <iostream>
#include <string.h>
#include <memory.h>
#include <sstream>
#include <fstream>
#include <cassert>
#include <cstdlib>
#include <complex>
#include <cctype>
#include <cstdio>
#include <vector>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

#define PII pair<int, int>
#define PLL pair<long long, long long>
#define F first
#define S second
#define ALL(x) x.begin(), x.end()
#define SZ(x) ((int)x.size())
#define div __div__
#define hash __hash__
#define prev __prev__
#define left __left__
#define right __right__
#define link __link__
#define next __next__

typedef vector<int> VI;
typedef vector<vector<int> > VII;
typedef long long LL;
typedef unsigned int UI;
typedef unsigned long long ULL;
typedef long double LD;


struct Automaton
{
    vector<int> len, suf;
    vector<map<char, int> > go;
    vector<bool> u;
    vector<LL> dp;
    vector<int> last;
    int p, sz;

    void clear()
    {
        go.clear();
        len.clear();
        suf.clear();
    }

    void build(string s)
    {
        int n = s.length() * 2 + 1;
        len.assign(n, 0);
        suf.assign(n, -1);
        go.resize(n);
        u.assign(n, 0);
        dp.assign(n, 0);
        last.assign(n, 0);
        for (int i = 0; i < n; i++)
            go[i].clear();
        p = 0;
        sz = 1;
        for (int i = 0; i < s.length(); i++)
            add(s[i]);
    }

    void add(char c)
    {
        int v = sz++;
        len[v] = len[p] + 1;
        for (; p >= 0 && !go[p].count(c); p = suf[p])
            go[p][c] = v;
        if (p < 0)
        {
            suf[v] = 0;
        }
        else
        {
            int to = go[p][c];
            if (len[to] == len[p] + 1)
            {
                suf[v] = to;
            }
            else
            {
                int cl = sz++;
                go[cl] = go[to];
                len[cl] = len[p] + 1;
                suf[cl] = suf[to];
                for (; p >= 0 && go[p][c] == to; p = suf[p])
                    go[p][c] = cl;
                suf[to] = suf[v] = cl;
            }
        }
        p = v;
    }

    void dfs(int v)
    {
        if (u[v])
            return;
        u[v] = true;
        if (go[v].count('$'))
            dp[v] = 1;
        for (auto x: go[v])
        {
            dfs(x.S);
            dp[v] += dp[x.S];
        }
    }

    LL solve(string q, int id)
    {
        q = q + q;
        int l = 0;
        int v = 0;
        int ql = q.length();
        int want = ql / 2;
        LL res = 0;
        for (int i = 0; i < ql; i++)
        {
            while (v >= 0 && !go[v].count(q[i]))
            {
                v = suf[v];
                if (v >= 0)
                    l = len[v];
            }
            if (v < 0)
            {
                l = 0;
                v = 0;
            }
            else
            {
                l++;
                v = go[v][q[i]];
            }
            if (l == want + 1)
            {
                l--;
                if (len[suf[v]] == l)
                    v = suf[v];
            }
            if (l == want)
            {
                if (last[v] != id)
                    res += dp[v];
                last[v] = id;
            }
        }
        return res;
    }
};

Automaton A;
string s, q;

int main()
{
    ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> s;
    s += '$';
    A.build(s);
    A.dfs(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> q;
        cout << A.solve(q, i) << "\n";
    }

    return 0;
}