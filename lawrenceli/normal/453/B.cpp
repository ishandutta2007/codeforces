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

const int MAXN = 105;
const int MAXV = 60;
const int MAXB = 17;

int n, ar[MAXN], dp[MAXN][1<<MAXB], par[MAXN][1<<MAXB], ans[MAXN];
int primes[MAXB], ind[MAXV], cnt;
vector<int> fact[MAXV];
vector<int> good[1<<MAXB], aft[1<<MAXB];

void init() {
    for (int i=2; i<MAXV; i++)
        if (fact[i].empty()) {
            primes[cnt] = i, ind[i] = cnt, cnt++;
            for (int j=i; j<MAXV; j+=i)
                fact[j].push_back(i);
        }

    rep(i, 1<<MAXB) {
        for (int j=1; j<MAXV; j++) {
            bool b = 1;
            int x = i;
            rep(k, fact[j].size())
                if (i&1<<ind[fact[j][k]]) {
                    b = 0;
                    break;
                } else x ^= 1<<ind[fact[j][k]];
            if (b) {
                good[i].push_back(j);
                aft[i].push_back(x);
            }
        }
    }
}

int calc(int a, int b) {
    if (a == 0) return 0;
    int& ret = dp[a][b];
   //cout << a << ' ' << b << ' ' << ret << endl;
    if (ret != -1) return ret;
    ret = 1e9;
    rep(i, good[b].size()) {
        int res = abs(ar[a-1]-good[b][i])+calc(a-1, aft[b][i]);
        if (res < ret)
            ret = res, par[a][b] = i;
    }
    return ret;
}

int main() { _
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n;
    rep(i, n) cin >> ar[i];
    init();

    memset(dp, -1, sizeof(dp));

    calc(n, 0);

    int a = n, b = 0;
    while (a) {
        int i = par[a][b];
        ans[a-1] = good[b][i];
        a--, b = aft[b][i];
    }

    rep(i, n) cout << ans[i] << ' ';
    return 0;
}