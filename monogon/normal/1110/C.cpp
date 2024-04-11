
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin >> q;
    while(q--) {
        ll a;
        cin >> a;
        if(__builtin_popcountll(a + 1) == 1) {
            for(ll x = 2; x * x <= a; x++) {
                if(a % x == 0) {
                    cout << a/x << '\n';
                    goto hell;
                }
            }
            cout << 1 << '\n';
        }else {
            ll ans = 0;
            rep(i, 0, 30) {
                if(ans >= a) break;
                ans ^= (1LL << i);
            }
            cout << ans << '\n';
        }
        hell:;
    }
}