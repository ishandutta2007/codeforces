
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
    ll n, a, b;
    int m;
    cin >> n >> m >> a >> b;
    vector<ll> s(m);
    rep(i, 0, m) {
        cin >> s[i];
    }
    sort(all(s));
    ll crackers = min((ll) m, abs(a - b) - 1);
    ll ti = (a > b ? n - b : b - 1);
    int idx = 0;
    for(int i = crackers - 1; i >= 0; i--) {
        if(s[i] + idx < ti) {
            idx++;
        }
    }
    cout << idx << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) {
        solve();
    }
}