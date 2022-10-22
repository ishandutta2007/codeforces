#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < int(n); ++i)
#define rrep(i,n) for(int i = int(n)-1; i >= 0; --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
template<class T> void chmax(T& a, const T& b) {a = max(a, b);}
template<class T> void chmin(T& a, const T& b) {a = min(a, b);}
using ll = long long;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<ll>;
using VVL = vector<VL>;

int n, m;
ll ans[100100];
bool reachable[100100];

/*void proc1(int z) {
    ll x_;
    int y;
    cin >> x_ >> y;
    int x = (x + 99999) / 100000;
    rep(i, x) {
        int now = -1;
        for(int j = i; j <= m; j += x) {
            if (reachable[j]) now = y;
            if (now != -1 && !reachable[j]) {
                reachable[j] = true;
                ans[j] = z;
            }
            if (now != -1) now--;
        }
    }
}*/

void proc2(int z) {
    ll x, y;
    cin >> x >> y;
    for(int i = m; i >= 0; i--) if (reachable[i]) {
        for(ll j = (i * x + 99999) / 100000, rest = y - 1; j <= m && rest >= 0;) {
            if (reachable[j]) break;
            reachable[j] = true;
            ans[j] = z;
            rest--;
            j = (j * x + 99999) / 100000;
        }
    }
}
void proc1(int z) {
    ll x, y;
    cin >> x >> y;
    x = (x + 99999) / 100000;
    for(int i = m; i >= 0; i--) if (reachable[i]) {
        for(ll j = i + x, rest = y - 1; j <= m && rest >= 0;) {
            if (reachable[j]) break;
            reachable[j] = true;
            ans[j] = z;
            rest--;
            j += x;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    rep(j, m + 1) ans[j] = -1;
    reachable[0] = true;
    for(int z = 1; z <= n; z++) {
        int t;
        cin >> t;
        if (t == 1) proc1(z);
        else proc2(z);
    }
    for(int j = 1; j <= m; j++) {
        cout << ans[j] << " \n"[j == m];
    }
}