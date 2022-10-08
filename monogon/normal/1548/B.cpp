
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

template<typename T>
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
            st[i][0] = abs(a[i]);
        }
        for(int j = 1; j < lg; j++) {
            for(int i = 0; i + (1 << j) <= n; i++) {
                st[i][j] = gcd(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
    T query(int l, int r) {
        int j = log[r - l + 1];
        return gcd(st[l][j], st[r - (1 << j) + 1][j]);
    }
};

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, 0, n) {
        cin >> a[i];
    }
    for(int i = n - 1; i > 0; i--) a[i] -= a[i - 1];
    a[0] = 0;
    sparse<ll> S(a);
    int j = 1;
    int ans = 0;
    rep(i, 1, n) {
        if(j < i) j = i;
        while(j < n && S.query(i, j) != 1) j++;
        ans = max(ans, j - i);
    }
    cout << ans + 1 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}