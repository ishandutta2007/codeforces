#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int N = 100 * 1000 + 1;
vector<int> g[N];

int main()
{
    ios_base::sync_with_stdio(0);
    
    int n;
    cin >> n;
    
    int m;
    cin >> m;
    
    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    int a[n];
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    
    int b[n];
    for (int i = 0; i < n; ++i)
        b[i] = 0;
    
    queue<int> bad;
    vector<int> pressed;
    for (int i = 0; i < n; ++i)
        if (a[i] == b[i])
            bad.push(i);
    
    while (bad.size())
    {
        int v = bad.front();
        bad.pop();
        
        if (b[v] != a[v])
            continue;
            
        pressed.push_back(v);
        ++b[v];
        for (int i = 0; i < g[v].size(); ++i)
        {
            int to = g[v][i];
            ++b[to];
            if (b[to] == a[to])
                bad.push(to);
        }
    }
    
    cout << pressed.size() << endl;
    for (int i = 0; i < pressed.size(); ++i)
        cout << pressed[i] + 1 << " ";
        
       
    //cin >> n;
        
    return 0;
}