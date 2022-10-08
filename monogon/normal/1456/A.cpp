
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
        int n, p, k;
        ll x, y;
        string s;
        cin >> n >> p >> k >> s >> x >> y;
        p--;
        vi cnt(n + 1, 0);
        ll ans = 1e18;
        for(int i = n - 1; i >= p; i--) {
            cnt[i] = (s[i] == '0') + (i + k >= n ? 0 : cnt[i + k]);
            ans = min(ans, y * (i - p) + x * (cnt[i]));
        }
        cout << ans << '\n';
    }
}