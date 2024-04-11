# include <iostream>
# include <cstdio>
# include <cstring>

using namespace std;
const int Mod = 1000000007;

long long F[2][502][502], pow[502];

int main() {
    int n, m; cin >> n >> m;
    if(m > n) {
        cout << 0 << endl;
        return 0;
    }

    pow[0] = 1;
    for(int i=1; i<=n; ++i) pow[i] = pow[i-1] * 2 % Mod;

    F[1][1][1] = F[1][0][0] = 1;
    for(int i=1; i<n; ++i) {
        int t = i & 1;
        memset(F[t^1], 0, sizeof(F[0]));
        for(int j=0; j<=m; ++j)
            for(int k=0; k<=i; ++k) {
                F[t^1][j+1][i+1] += (pow[i+1] - pow[k] + Mod) % Mod * F[t][j][k];
                F[t^1][j+1][i+1] %= Mod;
                
                F[t^1][j][k] += pow[k] * F[t][j][k];
                F[t^1][j][k] %= Mod;
            }
    }

    long long ans = 0;
    for(int k=0; k<=n; ++k)
        ans = (ans + F[n&1][m][k]) % Mod;
    cout << ans << endl;

    return 0;
}