#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;    

#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    
    string s;
    
    cin >> s;
    
    int n = s.length();
    ll f[n][10];
    
    for(int i = 0; i < n; ++i)
            for(int j = 0; j < 10; ++j)        
                    f[i][j] = 0;
    for(int i = 0; i < 10; ++i)
            f[0][i] = 1;
    for(int i = 1; i < n; ++i)
            for(int d = 0; d < 10; ++d)
            {
                    int cur = d + s[i] - '0';
                    if(cur % 2 == 0)
                           f[i][cur / 2] += f[i - 1][d];
                    else
                    {
                        f[i][cur / 2] += f[i - 1][d];
                        f[i][cur / 2 + 1] += f[i - 1][d];
                    }
            }
    
    bool ok = true;
    
    for(int i = 1; i < n; ++i)
    {
            int cur = s[i] - '0', prev = s[i - 1] - '0';
            if(cur != (cur + prev) / 2 && cur != (cur + prev) / 2 + (cur + prev) % 2)
                   ok = false;
    }
    
    ll ans = 0;
    
    for(int i = 0; i < 10; ++i)
            ans += f[n - 1][i];
    
    cout << ans - (ok ? 1 : 0) << endl;
    
    cin >> n;
    
    return 0;
}