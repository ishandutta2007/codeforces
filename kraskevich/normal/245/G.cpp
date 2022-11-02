#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <deque>
#include <cassert>
 
using namespace std;
 
#define MP make_pair
#define PB push_back
#define PII pair<int, int>
#define PLL pair<long long, long long>
#define F first
#define S second
#define WAIT int w; cin >> w;
#define ALL(x) x.begin(), x.end()

const int N = 10001;
bool edge[N][N];
short same[N];
vector<int> g[N];
map<string, int> id;
int res[N];
vector<string> name;

int main()
{
    ios_base::sync_with_stdio(0);
    
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            edge[i][j] = false;
            
    int m;
    cin >> m;
    
    for (int i = 0; i < m; ++i)
    {
        string a, b;
        cin >> a >> b;
        
        if (!id.count(a))
        {
            id.insert(MP(a, name.size()));
            name.push_back(a);
        }
        if (!id.count(b))
        {
            id.insert(MP(b, name.size()));
            name.push_back(b);
        }
        
        edge[id[a]][id[b]] = edge[id[b]][id[a]] = true;
        g[id[a]].push_back(id[b]);
        g[id[b]].push_back(id[a]);
    }
    
    int n = id.size();

    
    cout << n << endl;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
            same[j] = 0;
        
        for (int tt = 0; tt < g[i].size(); ++tt)
        {
            int v = g[i][tt];
            for (int j = 0; j < g[v].size(); ++j)
                if (!edge[i][g[v][j]] && i != g[v][j])
                    ++same[g[v][j]];
        }
                    
        res[i] = 0;
        int mx = 0;
        for (int j = 0; j < n; ++j)
            if (!edge[i][j] && i != j)
                mx = max((short)mx, same[j]);
        for (int j = 0; j < n; ++j)
            if (same[j] == mx && !edge[i][j] && i != j)
                ++res[i];
        
        cout << name[i] << " " << res[i] << endl;
    }
    
    //WAIT;
    
    
   
    
    return 0;
}