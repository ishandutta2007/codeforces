
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

const int N = 2e5 + 5;
int n, cnt[N][26];
string s;

int solve(int l, int r, char c) {
    if(l == r) {
        return s[l] != c;
    }
    int m = l + (r - l) / 2;
    assert(r - m == m - l + 1);
    return min(
        solve(l, m, c + 1) + (r - m) - (cnt[r + 1][c - 'a'] - cnt[m + 1][c - 'a']),
        solve(m + 1, r, c + 1) + (m - l + 1) - (cnt[m + 1][c - 'a'] - cnt[l][c - 'a'])
    );
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> s;
        rep(i, 1, n + 1) {
            rep(c, 0, 26) {
                cnt[i][c] = cnt[i - 1][c];
            }
            cnt[i][s[i - 1] - 'a']++;
        }
        cout << solve(0, n - 1, 'a') << '\n';
    }
}