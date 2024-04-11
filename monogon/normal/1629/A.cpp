
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
    int b;
    vi a(n);
    int k;
    cin >> k;
    rep(i, 0, n) cin >> a[i];
    vector<pii> ve;
    rep(i, 0, n) {
        cin >> b;
        ve.push_back({a[i], b});
    }
    sort(all(ve));
    for(auto &p : ve) {
        if(p.first <= k) k += p.second;
    }
    cout << k << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}