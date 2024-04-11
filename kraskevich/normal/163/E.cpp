#include <cstdio>
#include <algorithm>
#include <map>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <set>
#include <string>

using namespace std;

#define MP make_pair
#define pii pair<int, int>
#define F first
#define S second

const int inf = (int)1e9;


class fenwick
{
    vector<int> t;
    
    public:
        void init(int n)
        {
            t.assign(n, 0);
        }
        
        void upd(int i, int val)
        {
            for (; i < t.size(); i = (i | (i + 1)))
                t[i] += val;
        }
        
        int __sum(int i)
        {
            int res = 0;
            
            for (; i >= 0; i = (i & (i + 1)) - 1)
                res += t[i];
            
            return res;
        }
        
        int sum(int l, int r)
        {
            return __sum(r) - __sum(l - 1);
        }
};

const int N = 1000 * 1000 + 2;

vector<int> g[1000 * 1000 + 2];
fenwick up, down;
bool u[N], in[N];
int f[N], l[N];
int lst[4 * N];
int lsz = 0;

class treeColoring
{
    int n;
    
    public:
        void init(int sz)
        {
            n = sz;
            for (int i = 0; i < N; ++i)
                u[i] = in[i] = false;
            
            dfs(0);
            calc();
        }
        
        void dfs(int v)
        {
            u[v] = true;
            lst[lsz++] = v;
            
            for (int i = 0; i < g[v].size(); ++i)
            {
                int to = g[v][i];
                if (!u[to])
                {
                    dfs(to);
                    lst[lsz++] = v;
                }
            }
    
        }
        
        void calc()
        {
            for (int i = 0; i < n; ++i)
                f[i] = inf, l[i] = -inf;
            
            for (int i = 0; i < lsz; ++i)
                f[lst[i]] = min(f[lst[i]], i), l[lst[i]] = max(l[lst[i]], i);
            
            up.init(lsz);
            down.init(lsz);
        }
        
        void del(pii e)
        {
            int v = e.S;
            
            if (!in[v])
                return;
                
            in[v] = false;
            
            up.upd(f[v] - 1, -1);
            swap(e.F, e.S);
            down.upd(l[v], 1);
        }
        
        void add(pii e)
        {
            int v = e.S;
            
            if (in[v])
                return;
            
            in[v] = true;
            
            up.upd(f[v] - 1, 1);
            swap(e.F, e.S);
            down.upd(l[v], -1);
        }
        
        int getCnt(int v)
        {
            return up.sum(0, f[v] - 1) + down.sum(0, f[v] - 1);
        }
};



map<char, int> go[N], nx[N];
int p[N], suf[N];
char pch[N];
int sz = 1;
int num[N];

class BOR
{
    public:
        void init()
        {
            for (int i = 0; i < N; ++i)
                suf[i] = -1;
            suf[0] = 0;
            p[0] = 0;
            sz = 1;
        }
        
        void add(string s, int id)
        {
            int v = 0;
            for (int i = 0; i < s.length(); ++i)
            {
                if (!nx[v].count(s[i]))
                {
                    p[sz] = v;
                    pch[sz] = s[i];
                    nx[v].insert(MP(s[i], sz++));
                }
                v = nx[v][s[i]];

            }
            
            num[id] = v;
        }
        
        int GO(int v, char c)
        {
            if (go[v].count(c))
                return go[v][c];
            
            if (nx[v].count(c))
                return nx[v][c];
            
            if (!v)
                return 0;
                
            go[v].insert(MP(c, GO(SUF(v), c)));
            
            return go[v][c];
        }
        
        int SUF(int v)
        {
            if (suf[v] >= 0)
                return suf[v];
            
            if (v == 0 || p[v] == 0)
                suf[v] = 0;
            else
                suf[v] = GO(SUF(p[v]), pch[v]);
            
            return suf[v];
        }
};

BOR bor;
treeColoring tc;

long long sum(string s)
{
    int v = 0;
    long long ans = 0;
    
    for (int i = 0; i < s.length(); ++i)
    {
        v = bor.GO(v, s[i]);
        if (v)
            ans += tc.getCnt(v);
    }
    
    return ans;
}
            

int main()
{
    ios_base::sync_with_stdio(0);
    
    int m, n;
    cin >> m >> n;
    
    bor.init();
    
    for (int i = 0; i < n; ++i)
    {
        string s;
        cin >> s;
        
        bor.add(s, i + 1);
    }
    
    for (int i = 1; i < sz; ++i)
        g[bor.SUF(i)].push_back(i);
    
    tc.init(sz);
    
    for (int i = 1; i <= n; ++i)
        tc.add(pii(suf[num[i]], num[i]));
    
    for (int i = 0; i < m; ++i)
    {
        char c;
        cin >> c;
        
        if (c == '+')
        {
            int a;
            cin >> a;
            
            tc.add(pii(suf[num[a]], num[a]));
        }
        if (c == '-')
        {
            int a;
            cin >> a;
            
            tc.del(pii(suf[num[a]], num[a]));
        }
        if (c == '?')
        {
            string s;
            cin >> s;
            
            cout << sum(s) << "\n";
        }
        
    }
    
    
    return 0;
}