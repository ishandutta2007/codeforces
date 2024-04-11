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

int n, m;
double ans;

double exp(double b, int e) {
    if (e == 0) return 1;
    double res = exp(b, e/2);
    if (e&1) return res*res*b;
    return res*res;
}

int main() { _
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> m >> n;
    for (int i=1; i<=m; i++)
        ans += 1-exp(double(i-1)/m, n);
    cout << fixed << setprecision(10) << ans << '\n';
    return 0;
}