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

const int MAXN = 100100;

int n, m, num[MAXN], pre[MAXN], cnt[2][2][2];
char s[MAXN];
ll ans[2];

int main() { _
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    scanf("%s", s); n = strlen(s);
    for (int i=0, j; i<n; i=j) {
        for (j=i; j<n && s[j] == s[i]; j++);
        num[m] = j-i;
        pre[m] = i;
        m++;
    }

    rep(i, m) {
        ans[0] += ll((num[i]+1)/2)*(((num[i]&1)^1)+num[i]-1)/2;
        ans[1] += ll(num[i]/2+1)*((num[i]&1)+num[i])/2;
        rep(j, 2)
            rep(j1, 2)
                rep(k, 2) {
                    int x = k==0 ? num[i]/2 : (num[i]+1)/2;
                    ans[(pre[i]&1)^j^j1^k] += ll(x)*cnt[i&1][j][j1];
                }
        rep(j, 2) cnt[i&1][pre[i+1]&1][j] += j==0 ? num[i]/2 : (num[i]+1)/2;
    }

    cout << ans[0] << ' ' << ans[1] << '\n';
    return 0;
}