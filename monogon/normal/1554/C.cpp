
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

// min i such that n xor i > m

// a = 1010111000
// n = 0001000101
// m = 1010111000

void solve() {
    ll n, m;
    cin >> n >> m;
    if(m < n) {
        cout << 0 << '\n';
        return;
    }
    ll ans = 0;
    for(int l = 31; l >= 0; l--) {
        if((m >> l & 1) && (~n >> l & 1) && (n ^ ans) < m) {
            ans ^= (1LL << l);
        }
    }
    if((n ^ ans) > m) {
        cout << ans << '\n';
        return;
    }
    int bit = 0;
    while(m >> bit & 1) bit++;
    ans ^= (1LL << bit);
    ans &= ~((1LL << bit) - 1);
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}