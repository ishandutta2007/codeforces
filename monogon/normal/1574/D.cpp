
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
    int n;
    cin >> n;
    vi c(n);
    vector<vi> a(n);
    rep(i, 0, n) {
        cin >> c[i];
        a[i].resize(c[i]);
        rep(j, 0, c[i]) {
            cin >> a[i][j];
        }
    }
    int m;
    cin >> m;
    set<vi> se;
    rep(i, 0, m) {
        vi x(n);
        rep(j, 0, n) cin >> x[j];
        se.insert(x);
    }
    auto get = [&](const vi &x) {
        ll ans = 0;
        rep(i, 0, n) ans += a[i][x[i] - 1];
        return ans;
    };
    priority_queue<pair<ll, vi>> Q;
    Q.push({get(c), c});
    while(true) {
        vi v = Q.top().second; Q.pop();
        if(!se.count(v)) {
            rep(i, 0, n) {
                cout << v[i] << ' ';
            }
            cout << '\n';
            return 0;
        }
        rep(i, 0, n) {
            if(v[i] > 1) {
                v[i]--;
                Q.push({get(v), v});
                v[i]++;
            }
            if(v[i] < c[i]) break;
        }
    }
}