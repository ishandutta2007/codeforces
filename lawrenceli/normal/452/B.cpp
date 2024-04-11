#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define px real()
#define py imag()
#define rep(i, n) for (int i=0, _##i=(n); i<_##i; ++i)
#define repi(i, n) for (__typeof((n).begin()) i=(n).begin(), _##i=n.end(); i != _##i; ++i)
#define sz(x) int((x).size())
#define print(x) cerr << #x << ": " << x << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef complex<double> pnt;

int sq(int x) { return x*x; }

int main() { _
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    int n, m;
    cin >> n >> m;
    if (n == 0) {
        cout << 0 << ' ' << 1 << '\n';
        cout << 0 << ' ' << m << '\n';
        cout << 0 << ' ' << 0 << '\n';
        cout << 0 << ' ' << m-1 << '\n';
    } else if (m == 0) {
        cout << 1 << ' ' << 0 << '\n';
        cout << n << ' ' << 0 << '\n';
        cout << 0 << ' ' << 0 << '\n';
        cout << n-1 << ' ' << 0 << '\n';
    } else if (n > m) {
        if (sqrt(sq(n)+sq(m))*2+n > sqrt(sq(n)+sq(m-1))*2+sqrt(sq(n)+sq(m))) {
            cout << 0 << ' ' << 0 << '\n';
            cout << n << ' ' << m << '\n';
            cout << 0 << ' ' << m << '\n';
            cout << n << ' ' << 0 << '\n';
        } else {
            cout << 0 << ' ' << 1 << '\n';
            cout << n << ' ' << m << '\n';
            cout << 0 << ' ' << 0 << '\n';
            cout << n << ' ' << m-1 << '\n';
        }
    } else {
        if (sqrt(sq(n)+sq(m))*2+m > sqrt(sq(n-1)+sq(m))*2+sqrt(sq(n)+sq(m))) {
            cout << 0 << ' ' << 0 << '\n';
            cout << n << ' ' << m << '\n';
            cout << n << ' ' << 0 << '\n';
            cout << 0 << ' ' << m << '\n';
        } else {
            cout << n-1 << ' ' << m << '\n';
            cout << 0 << ' ' << 0 << '\n';
            cout << n << ' ' << m << '\n';
            cout << 1 << ' ' << 0 << '\n';
        }
    }
    return 0;
}