
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
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

const int N = 2e5 + 5, M = 998244353;
int n, m;
int a[N], b[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    rep(i, 0, n) {
        cin >> a[i];
    }
    rep(i, 0, m) {
        cin >> b[i];
    }
    if(m > n) {
        cout << "0\n";
        return 0;
    }
    reverse(a, a + n);
    reverse(b, b + m);

    int x = 0, y = 0;
    ll ans = 1;
    rep(i, 0, m - 1) {
        while(x < n && a[x] > b[i]) {
            x++;
        }
        while(y < n && a[y] >= b[i]) {
            y++;
        }
        if(x == y) {
            cout << "0\n";
            return 0;
        }
        // cout << "x, y = " << x << ' ' << y << endl;
        ans = (ans * (y - x)) % M;
    }
    if(*min_element(a, a + n) != b[m - 1]) {
        cout << "0\n";
        return 0;
    }
    cout << ans << '\n';
}