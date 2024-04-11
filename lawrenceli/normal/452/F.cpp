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

const int MAXN = 300100;
const int MULT = 1e9 + 7;

int n, ar[MAXN];
ll pw[MAXN], bit[2][MAXN];

void update(int c, int i, ll v) {
    for (; i<MAXN; i+=i&-i) bit[c][i] += v;
}

ll query(int c, int i) {
    ll ret = 0;
    for (; i>0; i-=i&-i) ret += bit[c][i];
    return ret;
}

int main() { _
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n;
    rep(i, n) cin >> ar[i];

    pw[0] = 1;
    for (int i=1; i<=n; i++) pw[i] = pw[i-1]*MULT;

    rep(i, n) {
        int l = min(ar[i], n-ar[i]+1);
        if ((query(0, ar[i]+l-1)-query(0, ar[i]-1))*pw[n-ar[i]] != (query(1, ar[i])-query(1, ar[i]-l))*pw[ar[i]]) {
            cout << "YES\n";
            return 0;
        }
        update(0, ar[i], pw[ar[i]]);
        update(1, ar[i], pw[n-ar[i]]);
    }

    cout << "NO\n";
    return 0;
}