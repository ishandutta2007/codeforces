
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
    cin >> n;
    map<ll, int> ma;
    rep(i, 0, n) {
        int a;
        cin >> a;
        ma[a]++;
    }
    vector<pair<ll, int>> ve(all(ma));
    int ans = 0;
    rep(i, 0, sz(ve)) {
        int len = ve[i].second;
        int idx = i + 1;
        while(idx < sz(ve)) {
            len++;
            ll gap = ve[idx].first - ve[i].first;
            idx = lower_bound(all(ve), make_pair(ve[i].first + 2 * gap, -1)) - ve.begin();
        }
        ans = max(ans, len);
    }
    cout << n - ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}