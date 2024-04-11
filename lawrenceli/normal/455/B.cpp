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

int n, k, sze=1;
char trie[MAXN];
int chd[MAXN][30], dp[MAXN], dp2[MAXN];

void add(string s) {
    int cur = 0;
    rep(i, s.length()) {
        int nxt = chd[cur][s[i]-'a'];
        if (nxt == -1) {
            chd[cur][s[i]-'a'] = sze;
            trie[sze] = s[i]-'a';
            nxt = sze++;
        }
        cur = nxt;
    }
}

int calc(int cur) {
    int& ret = dp[cur];
    if (ret != -1) return ret;
    rep(i, 26)
        if (chd[cur][i] != -1)
            if (!calc(chd[cur][i]))
                return ret = 1;
    return ret = 0;
}

int calc2(int cur) {
    int& ret = dp2[cur];
    if (ret != -1) return ret;
    int cnt = 0;
    rep(i, 26)
        if (chd[cur][i] != -1) {
            cnt++;
            if (!calc2(chd[cur][i]))
                return ret = 1;
        }
    if (cnt) return ret = 0;
    return ret = 1;
}

int main() { _
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    memset(chd, -1, sizeof(chd));
    memset(dp, -1, sizeof(dp));
    memset(dp2, -1, sizeof(dp2));
    cin >> n >> k;
    rep(i, n) {
        string s; cin >> s;
        add(s);
    }

    int res = calc(0), res2 = calc2(0);
    if (res == 0) cout << "Second\n";
    else if (res2) cout << "First\n";
    else if (k&1) cout << "First\n";
    else cout << "Second\n";
    return 0;
}