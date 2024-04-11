
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

const int N = 2e5 + 5;
vi d[N];

void solve() {
    int n;
    cin >> n;
    vi u(n);
    vector<vector<ll>> a(n + 1);
    rep(i, 0, n) cin >> u[i];
    rep(i, 0, n) {
        ll s;
        cin >> s;
        a[u[i]].push_back(s);
    }
    vector<ll> ans(n + 1);
    rep(i, 1, n + 1) {
        int m = sz(a[i]);
        sort(all(a[i]));
        ll sum = accumulate(all(a[i]), 0LL);
        rep(j, 0, m) {
            for(int k : d[m - j]) {
                if(j < k) {
                    ans[k] += sum;
                }
            }
            sum -= a[i][j];
        }
    }
    rep(i, 1, n + 1) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    rep(i, 1, N) {
        for(int j = i; j < N; j += i) {
            d[j].push_back(i);
        }
    }

    int te;
    cin >> te;
    while(te--) solve();
}