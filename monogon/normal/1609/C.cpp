
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

const int A = 1e6 + 5;
bool prime[A];

void solve() {
    int n, e;
    cin >> n >> e;
    vector<vi> ve(e);
    rep(i, 0, n) {
        int a;
        cin >> a;
        ve[i % e].push_back(a == 1 ? 1 : prime[a] ? 2 : 3);
    }
    ll ans = 0;
    vi cnt(4);
    rep(idx, 0, e) {
        fill(all(cnt), 0);
        int len = sz(ve[idx]);
        rep(i, 0, len) {
            if(ve[idx][i] == 2) {
                int l = i - 1, r = i + 1;
                while(l >= 0 && ve[idx][l] == 1) l--;
                while(r < len && ve[idx][r] == 1) r++;
                ans += 1LL * (r - i) * (i - l) - 1LL;
            }
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    rep(i, 0, A) prime[i] = true;
    prime[1] = false;
    rep(i, 2, A) {
        if(prime[i]) {
            for(int j = 2 * i; j < A; j += i) {
                prime[j] = false;
            }
        }
    }
    int te;
    cin >> te;
    while(te--) solve();
}