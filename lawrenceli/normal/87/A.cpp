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

int gcd(int a, int b) {
    if (!b) return a;
    return gcd(b, a%b);
}

int main() { _
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    int a, b;
    cin >> a >> b;
    ll m = ll(a)*b/gcd(a, b);
    int c = m/b, d = m/a;
    if (c+1<d) cout << "Dasha\n";
    else if (d+1<c) cout << "Masha\n";
    else cout << "Equal\n";
    return 0;
}