#include <iostream>
#include <map>
#include <vector>
using namespace std;

long long d[300][300];

int main()
{
    ios_base::sync_with_stdio(0);
    
    int n;
    cin >> n;
    
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            cin >> d[i][j];
    
    for(int k = 0; k < n; ++k)
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
        
    int m;
    cin >> m;
    
    for(int t = 0; t < m; ++t)
    {
        int a, b, c;
        cin >> a >> b >> c;
        --a, --b;
        if(d[a][b] > c)
        {
            d[a][b] = d[b][a] = c;
            for(int i = 0; i < n; ++i)
                for(int j = 0; j < n; ++j)
                {
                    d[i][j] = min(d[i][j], d[i][a] + d[b][j] + d[a][b]);
                    d[i][j] = min(d[i][j], d[i][b] + d[a][j] + d[a][b]);
                }
        }
        
        long long s = 0;
        for(int i = 0; i < n; ++i)
            for(int j = i + 1; j < n; ++j)
                s += d[i][j];
        
        cout << s << " ";
    }
    
    cin >> n;
    
    return 0;
}