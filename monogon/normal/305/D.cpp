
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

// edges either unit length, or length k + 1
// length k + 1 edges cannot be used in conjunction

const int N = 1e6 + 5, M = 1e9 + 7;
int n, m, k;
ll pow2[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    set<int> se;
    int cnt = 0;
    rep(i, 0, m) {
        int u, v;
        cin >> u >> v;
        if(v == u + 1) {
            cnt++;
        }else if(v == u + k + 1) {
            se.insert(u);
        }else {
            cout << 0 << '\n';
            return 0;
        }
    }
    if(!se.empty() && *prev(se.end()) - *se.begin() >= k + 1) {
        cout << 0 << '\n';
        return 0;
    }
    ll ans = 0;
    if(se.empty()) ans++;
    pow2[0] = 1;
    rep(i, 1, n + 1) {
        pow2[i] = (2 * pow2[i - 1]) % M;
    }
    rep(i, 1, n + 1) {
        // i first one included
        if((se.empty() || (*prev(se.end()) - i <= k && i <= *se.begin())) && i <= n - k - 1) {
            if(!se.empty() && i == *se.begin()) {
                (ans += pow2[max(0, min(k, n - k - i - 1) + 1 - sz(se))]) %= M;
            }else {
                (ans += pow2[max(0, min(k, n - k - i - 1) - sz(se))]) %= M;
            }
        }
    }
    ans = (ans + M) % M;
    cout << ans << '\n';
}