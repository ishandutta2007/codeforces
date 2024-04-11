#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int main() {

    ll n, m, k, x, y;

    cin >> n >> m >> k >> x >> y;

    vec< vec< ll > > a(n + 1, vec< ll >(m + 1));

    if(n == 1) {
        ll cnt = k / m;
        ll ost = k % m;
        for(int i = 1;i <= m;i++) {
            if(i <= ost) a[1][i]++;
            a[1][i] += cnt;
        }
    }else {
        if(k >= m) {
            k -= m;
            for(int i = 1;i <= m;i++) a[1][i]++;
            ll per = 2ll * (n - 1) * m;
            ll cnt = k / per;
            ll ost = k % per;

            for(int i = 1;i <= n;i++) {
                for(int j = 1;j <= m;j++) {
                    if(i == 1 || i == n) {
                        a[i][j] += cnt;
                    }else {
                        a[i][j] += 2 * cnt;
                    }
                }
            }

            int i = 2;
            int j = 1;
            int type = -1;

            for(ll iter = 0;iter < ost;iter++) {
                a[i][j]++;
                if(j < m) j++;
                else {
                    if(type == -1) {
                        if(i < n) {
                            i++;
                            j = 1;
                        }else {
                            i = n - 1;
                            j = 1;
                            type = 1;
                        }
                    }else {
                        if(i > 1) {
                            i--;
                            j = 1;
                        }else {
                            i = 2;
                            j = 1;
                            type = -1;
                        }
                    }
                }
            }
        }else {
                    for(int i = 1;i <= k;i++) a[1][i]++;
                }
    }

    ll mn = inf64;
    ll mx = -inf64;

//    cout << "\n";
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            mn = min(mn, a[i][j]);
            mx = max(mx, a[i][j]);
//            cout << a[i][j] << " ";
        }
//        cout << "\n";
    }

    cout << mx << " " << mn << " " << a[x][y] << "\n";

    return 0;
}