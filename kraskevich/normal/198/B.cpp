#include <iostream> 
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <queue>
using namespace std;

const int N = 5 * 100000;
vector<int> g[N];
const int INF = (int)1e9;

int main()
{
    ios_base::sync_with_stdio(0);
    
    int n, k;
    cin >> n >> k;
    
    string L, R;
    cin >> L >> R;
    
    int fin = 2 * n;
    
    for(int i = 0; i < n; ++i)
    {
        if(L[i] == 'X')
            continue;
        if(i + k >= n)
            g[i].push_back(fin);
        else
            if(R[i + k] != 'X')
                g[i].push_back(n + i + k);
    }
    for(int i = 1; i < n; ++i)  
        if(L[i] != 'X' && L[i - 1] != 'X')
            g[i].push_back(i - 1), g[i - 1].push_back(i);
    if(L[n - 1] != 'X')
        g[n - 1].push_back(fin);       
    
    for(int i = 0; i < n; ++i)
    {
        if(R[i] == 'X')
            continue;
        if(i + k >= n)
            g[i + n].push_back(fin);
        else
            if(L[i + k] != 'X')
                g[i + n].push_back(i + k);
    }
    for(int i = 1; i < n; ++i)
        if(R[i] != 'X' && R[i - 1] != 'X')
            g[i + n].push_back(i + n - 1), g[i + n - 1].push_back(i + n);
    if(R[n - 1] != 'X')
        g[2 * n - 1].push_back(fin);
    
    vector<int> d(2 * n + 1, INF);
    d[0] = 0;
    
    queue<int> q;
    q.push(0);
    
    while(!q.empty())
    {
        int v = q.front();
        q.pop();
        
        if(d[v] > v % n)
            continue;
        
        for(int i = 0; i < g[v].size(); ++i)
        {
            int to = g[v][i];
            if(d[to] > d[v] + 1)
            {
                d[to] = d[v] + 1;
                q.push(to);
            }
        }
    }
    
    cout << (d[fin] <= n ? "YES" : "NO");
    
    cin >> n;
    
    return 0;
}