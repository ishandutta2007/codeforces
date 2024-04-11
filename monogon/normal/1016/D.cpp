
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;

// # # # .
// # # # .
// # # # .
// . . . .

const int N = 105;
int n, m;
ll a[N], b[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    ll x = 0;
    rep(i, 0, n) {
        cin >> a[i];
        x ^= a[i];
    }
    rep(i, 0, m) {
        cin >> b[i];
        x ^= b[i];
    }
    if(x != 0) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    rep(i, 0, n - 1) {
        rep(j, 0, m - 1) {
            cout << "0 ";
        }
        x ^= a[i];
        cout << a[i] << '\n';
    }
    rep(j, 0, m - 1) {
        cout << b[j] << " ";
    }
    cout << (b[m - 1] ^ x) << '\n';
}