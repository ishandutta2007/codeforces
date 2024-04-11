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

int n;

int main() { _
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n;
    if (n <= 3) {
        cout << "NO\n";
    } else if (n%2 == 0) {
        cout << "YES\n";
        for (int i=6; i<=n; i+=2)
            cout << i << " - " << i-1 << " = " << 1 << '\n';
        cout << "4 * 3 = 12\n";
        cout << "12 * 2 = 24\n";
        rep(i, (n-4)/2) cout << "1 * 1 = 1\n";
        cout << "24 * 1 = 24\n";
    } else {
        cout << "YES\n";
        for (int i=7; i<=n; i+=2)
            cout << i << " - " << i-1 << " = " << 1 << '\n';
        cout << "5 + 1 = 6\n";
        cout << "4 * 6 = 24\n";
        cout << "3 - 2 = 1\n";
        rep(i, (n-5)/2) cout << "1 * 1 = 1\n";
        cout << "24 * 1 = 24\n";
    }
    return 0;
}