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

const int MAXN = 200100;

int n, b[MAXN];

int main() { _
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n;
    rep(i, n) cin >> b[i];
    sort(b, b+n);

    cout << b[n-1]-b[0] << ' ';
    int x, y;
    for (x=0; x<n && b[x] == b[0]; x++);
    for (y=n-1; y>=0 && b[y] == b[n-1]; y--);

    if (x == n) cout << ll(n)*(n-1)/2;
    else cout << ll(x)*(n-1-y);
    return 0;
}