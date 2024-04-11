#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <cassert>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <list>
#include <algorithm>
#include <string>
#include <cmath>
#include <iomanip>
#include <fstream>
 
using namespace std;
 
#define MP make_pair
#define F first
#define S second
#define pii pair<int, int>
 
typedef long long i64;
typedef int _int;

#define int long long

const int inf = 2 * 1000 * 1000 * 1000 + 10;
const int N = 211111;
vector<int> g[N];
vector<int> w[N];
vector<int> d(N, inf);




struct vertex
{
    int v, d;
    
    vertex() {}
    vertex(int _v, int _d)
    {
        v = _v;
        d = _d;
    }
};

bool operator < (vertex a, vertex b)
{
    return a.d < b.d || a.d == b.d && a.v < b.v;
}




struct group
{
    int l, r;
    group() {}
    group(int _l, int _r)
    {
        l = _l;
        r = _r;
    }
};

vector<group> t[N];

int getG(int v, int ttt)
{
    if (!t[v].size())
        return -1;
        
    int l = 0, r = t[v].size() - 1;
    
    while (l < r)
    {
        int m = (l + r) / 2;
        if (t[v][m].r >= ttt)
            r = m;
        else
            l = m + 1;
    }
    
    if (t[v][l].l <= ttt && t[v][l].r >= ttt)
        return l;
    else
        return -1;
}

i64 getF(int v, int time)
{
    int l = time, r = inf;
   
    if (getG(v, l) == -1)
        return time;
    
    int now = getG(v, l);
   
    while (l < r)
    {
        int m = (l + r) / 2;
        if (getG(v, m) != now)
            r = m;
        else
            l = m + 1;
    }
    
    return l;
}   

_int main()
{
    ios_base::sync_with_stdio(0);
    
    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < m; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        
        --a;
        --b;
        
        g[a].push_back(b);
        g[b].push_back(a);
        w[a].push_back(c);
        w[b].push_back(c);
    }
    
    for (int i = 0; i < n; ++i)
    {
        int k;
        cin >> k;
        
        int l = -10, prev = -10;
        
        for (int j = 0; j < k; ++j)
        {
            i64 arr;
            cin >> arr;
            
            if (arr != prev + 1)
            {
                if (prev >= 0)
                    t[i].push_back(group(l, prev));
                l = arr;
            }
            prev = arr;
        }
        
        if (prev >= 0)
            t[i].push_back(group(l, prev));    
    }
    
    d[0] = getF(0, 0);
    set<vertex> s;
    s.insert(vertex(0, getF(0, 0)));
    
    //cout << getF(0, 0) << endl;
    
    while (!s.empty())
    {
        vertex vv = *s.begin();
        s.erase(s.begin());
        int v = vv.v;
        
        if (v == n - 1)
            break;
        
        for (int i = 0; i < g[v].size(); ++i)
        {
            int to = g[v][i];
            int add = w[v][i];
            int cand = getF(to, d[v] + add);
            
            if (to == n - 1)
                cand = d[v] + add;
            
            if (cand < d[to])
            {
                s.erase(vertex(to, d[to]));
                d[to] = cand;
                s.insert(vertex(to, d[to]));
            }   
        }
    }
    
    if (d[n - 1] == inf)
        d[n - 1] = -1;
    
    cout << d[n - 1];
    
    //cin >> n;
    
    return 0;
}