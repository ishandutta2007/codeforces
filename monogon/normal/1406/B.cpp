
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
    int te;
    cin >> te;
    while(te--) {
        int n;
        cin >> n;
        vector<ll> a(n);
        vector<ll> neg, pos;
        bool b = false;
        rep(i, 0, n) {
            cin >> a[i];
            (a[i] < 0 ? neg : pos).push_back(a[i]);
            if(a[i] == 0) b = true;
        }
        ll ans = LLONG_MIN;
        if(b) {
            ans = 0;
        }
        sort(pos.rbegin(), pos.rend());
        sort(neg.rbegin(), neg.rend());
        rep(k, 0, 6) {
            if(sz(pos) >= k && sz(neg) >= 5 - k) {
                ll x1 = 1, x2 = 1, x3 = 1, x4 = 1;
                rep(i, 0, k) {
                    x1 *= pos[i];
                    x2 *= pos[i];
                    x3 *= pos[sz(pos) - i - 1];
                    x4 *= pos[sz(pos) - i - 1];
                }
                rep(i, 0, 5 - k) {
                    x1 *= neg[i];
                    x2 *= neg[sz(neg) - i - 1];
                    x3 *= neg[i];
                    x4 *= neg[sz(neg) - i - 1];
                }
                ans = max({ans, x1, x2, x3, x4});
            }
        }
        cout << ans << '\n';
    }
}