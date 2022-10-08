
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
    int n;
    string s;
    cin >> n >> s;
    vi a;
    ll ans = 0;
    ll best = LLONG_MAX;
    vector<int> e(n);
    rep(i, 0, n) {
        if(s[i] == '*') {
            int k = sz(a);
            a.push_back(i);
            ans += abs(i - k);
            e[i - k]++;
        }
    }
    int sheep = sz(a), num = sheep;
    for(int i = 0; i + sheep <= n; i++) {
        best = min(best, ans);
        num -= e[i];
        ans -= 2 * num - sheep;
    }
    cout << best << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}