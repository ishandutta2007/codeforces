
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
        vector<ll> d(n);
        ll ans = 0;
        rep(i, 0, n) {
            cin >> d[i];
        }
        sort(all(d));
        ll s = 0;
        rep(i, 0, n) {
            if(i > 0) ans += d[i] - d[i - 1];
            ans -= d[i] * i - s;
            s += d[i];
        }
        cout << ans << '\n';
    }
}