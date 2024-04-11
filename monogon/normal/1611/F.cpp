
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

template<typename T, class Compare = std::less<T>>
struct sparse {
    vector<vector<T>> st;
    vector<int> log;
    int n;
    sparse(vector<T> a) {
        n = a.size();
        log.assign(n + 1, 0);
        log[1] = 0;
        for(int i = 2; i <= n; i++) {
            log[i] = log[i / 2] + 1;
        }
        int lg = log[n] + 1;
        st.assign(n, vector<T>(lg));
        for(int i = 0; i < n; i++) {
            st[i][0] = a[i];
        }
        for(int j = 1; j < lg; j++) {
            for(int i = 0; i + (1 << j) <= n; i++) {
                st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1], Compare{});
            }
        }
    }
    T query(int l, int r) {
        int j = log[r - l + 1];
        return min(st[l][j], st[r - (1 << j) + 1][j], Compare{});
    }
};

void solve() {
    int n;
    ll s;
    cin >> n >> s;
    vector<ll> a(n + 1);
    rep(i, 1, n + 1) {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    sparse<ll> S(a);
    // for all i in [l, r], s + a[i] - a[l - 1] >= 0
    // find minimum a[i]

    int j = 1;
    int ans = -1;
    int L = -1, R = -1;
    rep(i, 1, n + 1) {
        while(j <= n && S.query(i - 1, j) + s - a[i - 1] >= 0) {
            j++;
        }
        if(j - i - 1 > ans) {
            ans = j - i - 1;
            L = i;
            R = j - 1;
        }
    }
    if(ans == -1) cout << -1 << '\n';
    else cout << L << ' ' << R << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}