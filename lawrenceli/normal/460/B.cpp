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

int a, b, c;
vector<int> ans;

int sum(ll x) {
    int ret = 0;
    while (x) {
        ret += x%10;
        x /= 10;
    }
    return ret;
}

int main() { _
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> a >> b >> c;
    for (int s=1; s<=81; s++) {
        ll x = 1;
        rep(i, a) x *= s;
        x = x*b+c;
        if (x>0 && x<1e9 && sum(x) == s) ans.push_back(x);
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    rep(i, ans.size()) cout << ans[i] << ' ';
    return 0;
}