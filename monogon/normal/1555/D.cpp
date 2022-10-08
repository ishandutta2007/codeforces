
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
    cin >> n >> m;
    string s;
    cin >> s;
    s = "$" + s;
    vector<vi> cost(6, vi(n + 1, 0));
    string str = "abc";
    rep(p, 0, 6) {
        rep(i, 1, n + 1) {
            cost[p][i] = cost[p][i - 1] + (s[i] != str[i % 3]);
        }
        next_permutation(all(str));
    }
    while(m--) {
        int l, r;
        cin >> l >> r;
        int ans = INT_MAX;
        rep(i, 0, 6) ans = min(ans, cost[i][r] - cost[i][l - 1]);
        cout << ans << '\n';
    }
}