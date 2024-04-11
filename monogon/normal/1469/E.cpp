
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
    int n, k;
    string s;
    cin >> n >> k >> s;
    deque<int> ve;
    int j = 0;
    vector<bool> b(n + 1, false);
    for(int i = 0; i + k <= n; i++) {
        while(j < i + k) {
            if(s[j] == '0') {
                ve.push_back(j);
            }
            j++;
        }
        if(ve.empty() || ve[0] + 22 >= i + k) {
            ll val = 0;
            for(int idx : ve) {
                val += (1LL << (i + k - idx - 1));
            }
            if(val <= n) b[val] = true;
        }
        if(!ve.empty() && ve[0] == i) ve.pop_front();
    }
    string ans(k, '0');
    int idx = 0;
    while(idx <= n && b[idx]) idx++;
    if(idx > n || (k <= 22 && idx >= (1LL << k))) {
        cout << "NO\n";
        return;
    }
    rep(i, 0, min(22, k)) {
        if(idx >> i & 1) {
            ans[k - i - 1] = '1';
        }
    }
    cout << "YES\n";
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