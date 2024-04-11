#include <bits/stdc++.h>
#define ff(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fb(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define pb push_back

typedef long long ll;
using namespace std;
typedef vector <int> vi;

int N;
int a[105];
bool vis[105];
int sz[105];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N; ff(i, 1, N) cin >> a[i];
    ff(i, 1, N) {
        memset(vis, 0, sizeof vis);
        vis[i] = 1; int tmp = i;
        while (1) {
            ++sz[i];
            tmp = a[tmp];
            if (tmp == i) break;
            if (vis[tmp]) return cout << -1 << endl, 0;
            vis[tmp] = 1;
        }
    }
    ll ans = sz[1];
    ff(i, 2, N) ans = ans / __gcd(ans, 1ll * sz[i]) * sz[i];
    if (ans % 2 == 0) ans /= 2;
    cout << ans << endl;
    return 0;
}