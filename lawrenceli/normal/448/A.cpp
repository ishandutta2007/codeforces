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

int up(int a, int b) {
    if (a%b == 0) return a/b;
    else return a/b+1;
}

int main() { _
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    int a1, a2, a3;
    int b1, b2, b3;
    int n, a, b;
    cin >> a1 >> a2 >> a3 >> b1 >> b2 >> b3 >> n;
    a = a1 + a2 + a3, b = b1 + b2 + b3;
    if (up(a, 5)+up(b, 10) <= n) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}