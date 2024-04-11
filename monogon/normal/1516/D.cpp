
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
    int n, q;
    cin >> n >> q;
    const int N = 1e5 + 5;
    vi pr(N, 1);
    rep(i, 2, N) {
        if(pr[i] == 1) {
            for(int j = i; j < N; j += i) {
                pr[j] = i;
            }
        }
    }
    vi a(n + 1), nxt(n + 1);
    map<int, int> ma;

    rep(i, 1, n + 1) {
        cin >> a[i];
        ll x = a[i];
        while(x > 1) {
            int p = pr[x];
            while(x % p == 0) x /= p;
            nxt[i] = max(nxt[i], ma[p]);
            ma[p] = i;
        }
        nxt[i] = max(nxt[i], nxt[i - 1]);
    }
    const int K = 20;
    vector<vi> par(n + 1, vi(K));
    rep(i, 0, n + 1) par[i][0] = nxt[i];
    rep(l, 1, K) {
        rep(i, 0, n + 1) {
            par[i][l] = par[par[i][l - 1]][l - 1];
        }
    }
    while(q--) {
        int L, r;
        cin >> L >> r;
        int ans = 0;
        for(int l = K - 1; l >= 0; l--) {
            if(par[r][l] >= L) {
                ans += (1 << l);
                r = par[r][l];
            }
        }
        ans++;
        cout << ans << '\n';
    }
}