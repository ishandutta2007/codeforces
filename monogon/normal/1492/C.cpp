
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
    int n, m;
    string s, t;
    cin >> n >> m >> s >> t;
    vi l(m + 1), r(m + 1);
    int idx = 0;
    rep(i, 0, n) {
        if(idx < m && s[i] == t[idx]) {
            idx++;
            l[idx] = i;
        }
    }
    idx = m;
    for(int i = n - 1; i >= 0; i--) {
        if(idx > 0 && s[i] == t[idx - 1]) {
            r[idx] = i;
            idx--;
        }
    }
    int ans = 0;
    rep(i, 1, m) {
        ans = max(ans, r[i + 1] - l[i]);
    }
    cout << ans << '\n';
}