#include <iostream>
#include <vector>
using namespace std;

const int N = 2000;

bool fr[N][N], en[N][N];
bool u[N];
int comp[N];

void dfs(int v, int k, int n)
{
     u[v] = true;
     comp[v] = k;
     for(int i = 0; i < n; ++i)
             if(fr[v][i] && !u[i])
                         dfs(i, k, n);
}

int main()
{
    ios_base::sync_with_stdio(0);
    
    int n, k, m;
    
    cin >> n >> k;
    
    for(int i = 0; i < n; ++i)
            u[i] = false;
    for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                    fr[i][j] = en[i][j] = false;
    
    for(int i = 0; i < k; ++i)
    {
            int a, b;
            cin >> a >> b;
            --a;
            --b;
            fr[a][b] = fr[b][a] = true;
    }
    
    cin >> m;
    
    for(int i = 0; i < m; ++i)
    {
            int a, b;
            cin >> a >> b;
            --a;
            --b;
            en[a][b] = en[b][a] = true;
    }
    
    int kf = 0;
    for(int i = 0; i < n; ++i)
            if(!u[i])
                     dfs(i, kf++, n);
    
    int ans = 0;
    
    for(int i = 0; i < kf; ++i)
    {
            int s = 0;
            for(int j = 0; j < n; ++j)
                    if(comp[j] == i)
                               ++s;
            vector<int> v;
            for(int j = 0; j < n; ++j)
                    if(comp[j] == i)
                               v.push_back(j);
            
            bool ok = true;
            for(int ii = 0; ii < v.size() && ok; ++ii)
                    for(int j = ii + 1; j < v.size() && ok; ++j)
                            if(en[v[ii]][v[j]])
                                        ok = false;
            if(ok)
                  ans = max(ans, s);
    }
    
    cout << ans;
    
    cin >> n;
    
    return 0;
}