
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
    vi a(n), b(n), c(m), ans(m), d2(n + 1, -1);
    vector<vi> d(n + 1);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n) {
        cin >> b[i];
        if(a[i] != b[i]) {
            d[b[i]].push_back(i);
        }
        d2[b[i]] = i;
    }
    stack<int> st;
    rep(i, 0, m) {
        cin >> c[i];
        st.push(i);
        if(d2[c[i]] != -1) {
            int p = d2[c[i]];
            if(!d[c[i]].empty()) {
                p = d[c[i]].back();
                d[c[i]].pop_back();
            }
            while(!st.empty()) {
                int x = st.top(); st.pop();
                ans[x] = p + 1;
            }
        }
    }
    if(!st.empty()) {
        cout << "NO\n";
        return;
    }
    rep(i, 1, n + 1) {
        if(!d[i].empty()) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
    rep(i, 0, m) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}