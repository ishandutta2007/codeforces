#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef pair< int, int > pii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int main() {

    int n, m;

    cin >> n >> m;

    vec< vec< int > > a(n + 1, vec< int >(m));

    for(int i = 1;i <= n;i++) {
        string s;
        cin >> s;
        for(int j = 0;j < m;j++) {
            if(s[j] >= 'a' && s[j] <= 'z') {
                a[i][j] = 0;
            }else if(s[j] >= '0' && s[j] <= '9') {
                a[i][j] = 1;
            }else {
                a[i][j] = 2;
            }
        }
    }

//    for(int i = 1;i <= n;i++) {
//        for(int j = 0;j < m;j++) {
//            cout << a[i][j] << " ";
//        }
//        cout << "\n";
//    }

    vec< vec< int > > dp(n + 1, vec< int >(8, inf));

    dp[0][0] = 0;

    for(int i = 1;i <= n;i++) {
        for(int j = 0;j < m;j++) {
            for(int mask = 0;mask < 8;mask++) {
                if(!((1 << a[i][j]) & mask)) continue;
                dp[i][mask] = min(dp[i][mask], dp[i - 1][mask] + min(j, m - j));
                dp[i][mask] = min(dp[i][mask], dp[i - 1][mask ^ (1 << a[i][j])] + min(j, m - j));
            }
        }
    }

    cout << dp[n][7] << "\n";

    return 0;
}