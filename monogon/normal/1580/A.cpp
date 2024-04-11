
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

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    vector<vi> ones(n);
    rep(i, 0, n) {
        cin >> s[i];
        ones[i].resize(m + 1);
        ones[i][0] = 0;
        rep(j, 1, m + 1) {
            ones[i][j] = ones[i][j - 1] + (s[i][j - 1] == '1');
        }
    }
    int ans = 5 * 4;
    vi a(n), b(n);
    rep(l, 1, m + 1) rep(r, l + 3, m + 1) {
        rep(i, 0, n) {
            a[i] = ones[i][r - 1] - ones[i][l];
            b[i] = a[i] + (s[i][l - 1] == '0') + (s[i][r - 1] == '0');
            a[i] = (r - l - 1) - a[i];
        }
        int sumb = 0;
        int sumb2 = 0;
        int best = 1e9;
        rep(i, 0, n) {
            int valR = sumb + a[i];
            if(i >= 4) {
                sumb2 += b[i - 4];
                best = min(best, -sumb2 + a[i - 4]);
            }
            ans = min(ans, valR + best);
            sumb += b[i];
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}