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

const int MAXA = 100100;
const int MAXB = 31;

int n, dp[MAXA][MAXB];

int exp(int a, int b) {
    ll x = 1;
    rep(i, b) {
        x *= a;
        if (x >= n) x = n;
    }
    return x;
}

int calc(int a, int b) {
    if (b == 1 && a >= MAXA) return ((n-a)&1)^1;
    if (a == 1 && b >= MAXB) return 2;
    int& ret = dp[a][b];
    if (ret != -1) return ret;
    bool c = 0;
    if (exp(a+1, b)<n) {
        int res = calc(a+1, b);
        if (res == 0) return ret = 1;
        else if (res == 2) c = 1;
    }
    if (exp(a, b+1)<n) {
        int res = calc(a, b+1);
        if (res == 0) return ret = 1;
        else if (res == 2) c = 1;
    }
    if (c) return ret = 2;
    return ret = 0;
}

int main() { _
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    int a, b;
    cin >> a >> b >> n;
    memset(dp, -1, sizeof(dp));

    int res = calc(a, b);
    if (res == 0) cout << "Stas\n";
    else if (res == 1) cout << "Masha\n";
    else cout << "Missing\n";
    return 0;
}