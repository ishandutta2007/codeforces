
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
    vector<int> a(n + 1);
    rep(i, 1, n + 1) {
        cin >> a[i];
    }
    int idx = n;
    while(idx > 0 && a[idx] == idx) idx--;
    cout << fixed << setprecision(8);
    double ans = 1;
    while(m--) {
        int r;
        double p;
        cin >> r >> p;
        if(r >= idx) {
            ans *= (1 - p);
        }
    }
    if(idx == 0) {
        cout << 1.0 << '\n';
        return;
    }
    ans = 1 - ans;
    cout << ans << '\n';
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