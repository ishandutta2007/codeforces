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

const int MAXN = 1005;
const int MAXP = 30;

int n, p, dp[MAXN][MAXP][MAXP][2];
string s, t;

int calc(int i, int j, int k, bool l) {
    int& ret = dp[i][j][k][l];
    if (ret != -1) return ret;
    ret = -2;
    int st = s[i]-'a';
    if (l) st = 0;
    for (int i1=st; i1<p; i1++) {
        if (i1 != j && i1 != k && calc(i+1, k, i1, l||i1!=s[i]-'a') != -2)
            return ret = i1;
    }
    return ret;
}

int main() { _
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    }

    cin >> n >> p >> s;
    bool b = 0;
    for (int i=s.length()-1; i>=0; i--)
        if (s[i]-'a' != p-1) {
            s[i]++;
            for (int j=i+1; j<s.length(); j++)
                s[j] = 'a';
            b = 1;
            break;
        }
    if (!b) {
        cout << "NO\n";
        return 0;
    }

    memset(dp, -1, sizeof(dp));
    rep(i, MAXP)
        rep(j, MAXP)
            rep(k, 2)
                dp[n][i][j][k] = 0;

    int j = MAXP-1, k = MAXP-1, l=0;
    for (int i=0; i<s.length(); i++) {
        int x = calc(i, j, k, l);
        if (x == -2) {
            cout << "NO\n";
            return 0;
        }
        if (x != s[i]-'a') l = 1;
        t += x+'a';
        j = k, k = x;
    }

    cout << t << '\n';
    return 0;
}