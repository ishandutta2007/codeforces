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


const int inf = 1000 * 1000 * 1000;

struct edge
{
    int fr, to, f, c, cost, rev;
    edge() {}
    edge(int _fr, int _to, int _f, int _c, int _cost, int _rev)
    {
        fr = _fr;
        to = _to;
        f = _f;
        c = _c;
        cost = _cost;
        rev = _rev;
    }
};

vector<edge> e;

int main()
{
    ios_base::sync_with_stdio(0);
    
    string want;
    cin >> want;
    
    int n = 2, k = want.length();
    int fin = 1;
    int start = 0;
    int v[k];
    
    for (int i = 0; i < k; ++i)
    {
        int sz = e.size();
        v[i] = n;
        e.push_back(edge(n, fin, 0, 1, 0, sz + 1));
        e.push_back(edge(fin, n, 0, 0, 0, sz));
        ++n;
    }
    
    int cnt;
    cin >> cnt;
    
    for (int i = 0; i < cnt; ++i)
    {
        int cost = i + 1;
        string s;
        cin >> s;
        
        int down = n;
        ++n;
        int a;
        cin >> a;
        
        int sz = e.size();
        e.push_back(edge(start, down, 0, a, 0, sz + 1));
        e.push_back(edge(down, start, 0, 0, 0, sz));
        
        int now[s.length()];
        
        for (int j = 0; j < s.length(); ++j)
            now[j]=n++;
            
        for (int j = 0; j < s.length(); ++j)
        {
                sz = e.size();
                e.push_back(edge(down, now[j], 0, 1, cost, sz + 1));
                e.push_back(edge(now[j], down, 0, 0, -cost, sz));
        }
        
        for (int j = 0; j < s.length(); ++j)
        {
            for (int t = 0; t < k; ++t)
            {
                if (want[t] != s[j])
                    continue;
                sz = e.size();
                e.push_back(edge(now[j], v[t], 0, 1, 0, sz + 1));
                e.push_back(edge(v[t], now[j], 0, 0, 0, sz));
                ++n;
            }
        }
    }
    
    int curflow = 0, curcost = 0;
    for (;;)
    {
        if (k == curflow)
            break;

        vector<int> d(n, inf);
        vector<int> p(n, -1);
        vector<int> pid(n, -1);
        d[0] = 0;

        for (int i = 0; i < n; ++i)
        {
            bool any = false;
            for (int j = 0; j < e.size(); ++j)
                if (e[j].c - e[j].f > 0)
                {
                    int f = e[j].fr, to = e[j].to;
                    if (d[to] > d[f] + e[j].cost)
                    {
                        any = true;
                        d[to] = d[f] + e[j].cost;
                        p[to] = f;
                        pid[to] = j;
                    }
                }
            if (!any)
                break;
        }

        if (d[fin] == inf)
            break;

        vector<int> path;
        for (int i = fin; i != 0; i = p[i])
            path.push_back(i);
        path.push_back(0);
        reverse(path.begin(), path.end());
        
        for (int i = 0; i < path.size() - 1; ++i)
        {
            int id = pid[path[i + 1]];
            e[id].f++;
            e[e[id].rev].f--;
        }

        curcost += d[fin];
        ++curflow;
    }
    
    if (curflow < k)
        curcost = -1;
    cout << curcost << endl;
    
    return 0;
}