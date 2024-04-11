#include <iostream>
using namespace std;

long long f[200][200][20][20];
const long long mod = (long long)1e8;

int main()
{
    ios_base::sync_with_stdio(0);
    
    int n1, n2, k1, k2;
    cin >> n1 >> n2 >> k1 >> k2;
    
    for(int i = 0; i < 200; ++i)
            for(int j = 0; j < 200; ++j)
                    for(int l = 0; l < 20; ++l)
                            for(int t = 0; t < 20; ++t)
                                    f[i][j][l][t] = 0;
    f[0][0][0][0] = 1;
    
    for(int s1 = 0; s1 <= n1; ++s1)
            for(int s2 = 0; s2 <= n2; ++s2)
                    for(int j1 = 0; j1 <= k1; ++j1)
                            for(int j2 = 0; j2 <= k2; ++j2)   
                            {
                                    if(j1 != k1)
                                          f[s1 + 1][s2][j1 + 1][0] += f[s1][s2][j1][j2], f[s1 + 1][s2][j1 + 1][0] %= mod;
                                    if(j2 != k2)
                                          f[s1][s2 + 1][0][j2 + 1] += f[s1][s2][j1][j2], f[s1][s2 + 1][0][j2 + 1] %= mod;
                            }
    
    long long ans = 0;
    for(int i = 0; i <= k1; ++i)
            for(int j = 0; j <= k2; ++j)
                    ans += f[n1][n2][i][j], ans %= mod;
    
    cout << ans;
    
    cin >> n1;
    
    return 0;
}