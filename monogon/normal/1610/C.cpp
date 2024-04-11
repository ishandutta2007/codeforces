
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
    vi a(n), b(n);
    rep(i, 0, n) {
        cin >> a[i] >> b[i];
    }
    int L = 0, R = n + 1;
    while(L < R) {
        int m = (L + R) / 2;
        int idx = 0;
        rep(i, 0, n) {
            if(idx < m && b[i] >= idx && a[i] >= m - idx - 1) {
                idx++;
            }
        }
        if(idx < m) {
            R = m;
        }else {
            L = m + 1;
        }
    }
    cout << L - 1 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}