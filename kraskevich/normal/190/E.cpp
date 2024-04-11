#include <iostream>
#include <set>
#include <algorithm>
#include <queue>
#include <stdlib.h>
using namespace std;

#define pii pair<int, int>
vector<int> cur, u;
set<pii> e;
queue<int> q;

pii MP(int a, int b)
{
    if(a < b)
        swap(a, b);
    return pii(a, b);
}

void dfs(int a)
{
    while(!q.empty())
        q.pop();
    q.push(a);
    while(!q.empty())
    {
        int v = q.front();
        q.pop();
        cur.push_back(v);
        for(int i = 0; i < u.size(); ++i)
        {
            if(!e.count(MP(v, u[i])))
            {
                q.push(u[i]);
                swap(u.back(), u[i]);
                u.pop_back();
                --i;
            }
       }
   }
}

vector<vector<int> > comp;

int main()
{
    srand(137);
    ios_base::sync_with_stdio(0);
    
    int n, m;
    cin >> n >> m;
    
    for(int i = 0; i < m; ++i)
    {
       int u, v;
       cin >> u >> v;
       --u, --v;
       e.insert(MP(u, v));
    }
   
    for(int i = 0; i < n; ++i)
        u.push_back(i);
    random_shuffle(u.begin(), u.end());
   
    while(u.size() > 0)
    {
        cur.clear();
        int v = u.back();
        u.pop_back();
        dfs(v);
        comp.push_back(cur);
    }
    
    
    cout << comp.size() << endl;
    for(int i = 0; i < comp.size(); ++i)
    {
        cout << comp[i].size() << " ";
        for(int j = 0; j < comp[i].size(); ++j)
            cout << comp[i][j] + 1 << " ";
       cout << endl;
    }
    
    return 0;
}