
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
#define rep(i, a, b) for(int i = (a); i < (b); i++)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int) (x).size())

void solve() {
    int n, k, m;
    cin >> n >> k >> m;
    vector<bool> ve(n + 1, false);
    rep(i, 0, m) {
        int b;
        cin >> b;
        ve[b] = true;
    }
    if((n - m) % (k - 1) != 0) {
        cout << "NO\n";
        return;
    }
    k = (k - 1) / 2;
    int cnt = 0;
    rep(i, 1, n + 1) {
        if(!ve[i]) cnt++;
        else if(cnt >= k && n - m - cnt >= k) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
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