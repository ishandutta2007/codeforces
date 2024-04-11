
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
    int n, a[4];
    cin >> n;
    rep(i, 0, 4) cin >> a[i];
    rep(mask, 0, 1 << 4) {
        bool flag = true;
        rep(i, 0, 4) {
            int b = a[i] - (mask >> i & 1) - (mask >> ((i + 1) % 4) & 1);
            if(b < 0 || b > n - 2) flag = false;
        }
        if(flag) {
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
    while(te--) solve();
}