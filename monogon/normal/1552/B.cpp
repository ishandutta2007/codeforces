
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
    vector<array<int, 6>> ve, vv;
    rep(i, 0, n) {
        array<int, 6> a;
        rep(j, 0, 5) cin >> a[j];
        a[5] = i;
        int j = 0;
        rep(k, 0, sz(ve)) {
            int cnt = 0;
            rep(l, 0, 5) cnt += (a[l] < ve[k][l]);
            if(cnt >= 3) {
                j++;
            }else {
                ve[k - j] = ve[k];
            }
        }
        vv.push_back(a);
        ve.erase(ve.end() - j, ve.end());
        if(ve.empty()) ve.push_back(a);
    }
    assert(!ve.empty());
    array<int, 6> best = ve[0];
    bool ok = true;
    rep(i, 0, n) {
        if(i == best[5]) continue;
        int cnt = 0;
        rep(l, 0, 5) cnt += (best[l] < vv[i][l]);
        if(cnt < 3) ok = false;
    }
    if(ok) cout << best[5] + 1 << '\n';
    else cout << -1 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}