#include<bits/stdc++.h>
using namespace std;
#define sz(a) (int)a.size()
int n, m;
const int N = 4e3;
set <int> g[N];
vector <int> res;
set <int> g2[N];
void euler(int v)
{
    while(!g2[v].empty())
    {
        int t = *g2[v].begin();
        g2[v].erase(t);
        g2[t].erase(v);
        euler(t);
    }
    res.push_back(v);
}
bool check(int v)
{
    for(int i = 0; i < n; i++)
    {
        g2[i] = g[i];
    }
    res.clear();
    euler(v);
    int cnt = 0;
    for(int i = 0; i < n; i++)
    {
        cnt += g[i].size();
    }
    for(int i= 0; i < n; i++)
    {
        g2[i]= g[i];
    }
    for(int i = 1; i< res.size(); i++)
    {
        int x = res[i - 1];
        int y = res[i];
        if(g2[x].count(y) != 1)
        {
            return 0;
        }
        g2[x].erase(y);
        g2[y].erase(x);
    }
    return cnt / 2 + 1 == res.size();
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        g[x].insert(y);
        g[y].insert(x);
    }
    for(int i = 0; i < n; i++)
    {
        set <int> pr = g[i];
        set <int> dif;
        for(auto x : pr)
        {
            if(g[x].size() % 2 == 1)
            {
                g[i].erase(x);
                g[x].erase(i);
                dif.insert(x);
            }
        }
        if(check(i))
        {
            res.push_back(-2);
            for(auto x : dif)
            {
                res.push_back(x);
                res.push_back(i);
            }
            cout << res.size() << "\n";
            for(auto v : res)
            {
                cout << v + 1 << " ";
            }
            cout << "\n";
            return 0;
        }
        for(auto x : pr)
        {
            if(g[i].count(x))
            {
                g[i].erase(x);
                g[x].erase(i);
                dif.insert(x);
            }
            else
            {
                g[i].insert(x);
                g[x].insert(i);
                dif.erase(x);
            }
            if(check(i))
            {
                res.push_back(-2);
                for(auto v : dif)
                {
                    res.push_back(v);
                    res.push_back(i);
                }
                cout << sz(res) << "\n";
                for(auto x : res)
                {
                    cout << x + 1 << " ";
                }
                cout << "\n";
                return 0;
            }
            if(g[i].count(x))
            {
                g[i].erase(x);
                g[x].erase(i);
                dif.insert(x);
            }
            else
            {
                g[i].insert(x);
                g[x].insert(i);
                dif.erase(x);
            }
        }
        for(auto v : dif)
        {
            g[v].insert(i);
            g[i].insert(v);
        }
    }
    cout << 0;
    return 0;
}