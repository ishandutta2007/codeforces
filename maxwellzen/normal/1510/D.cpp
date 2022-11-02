#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef vector<pi> vpi;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)

#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define mp make_pair
#define F first
#define S second

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll MOD = 1e9+7;// 998244353;

int n, d;
vi a, b, ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> d;
    a.rsz(n);
    F0R(i, n) cin >> a[i];
    if (d==0) {
        bool five=false, two=false;
        F0R(i, n) {
            if (a[i]%2==0) two=true;
            if (a[i]%5==0) five=true;
        }
        if (two && five) {
            cout << n << '\n';
            F0R(i, n) cout << a[i] << ' ';
            cout << endl;
        }
        else cout << -1 << endl;
        return 0;
    }
    if (d==5) {
        bool five=false;
        F0R(i, n) if (a[i]%2 != 0 && a[i]%5==0) five=true;
        if (five) {
            int cnt = 0;
            F0R(i, n) if (a[i]%2 != 0) cnt++;
            cout << cnt << '\n';
            F0R(i, n) if (a[i]%2 != 0) cout << a[i] << ' ';
            cout << '\n';
        } else cout << -1 << endl;
        return 0;
    }
    if (d%2 != 0) {
        F0R(i, n) if (a[i]%2 != 0) b.pb(a[i]);
        a = b; n = a.size(); b.clear();
    }
    F0R(i, n) if (a[i]%5 != 0) b.pb(a[i]);
    a = b; n = a.size(); b.clear();
    if (n==0) {
        cout << -1 << endl;
        return 0;
    }
    int test = 1;
    F0R(i, n) test = (test*a[i])%10;
    if (test==d) {
        cout << n << '\n';
        F0R(i, n) cout << a[i] << ' ';
        cout << '\n';
        return 0;
    }
    ll dp[n][10][4];
    F0R(i, n) F0R(j, 10) F0R(k, 4) dp[i][j][k]=-1;
    pi par[n][10][4];
    dp[0][1][1] = a[0];
    dp[0][a[0]%10][0] = 1;
    FOR(i, 1, n) {
        F0R(k, 10) {
            F0R(j, 4) {
                if (dp[i-1][k][j]==-1) continue;
                if (j<3 && (dp[i][k][j+1]==-1 || dp[i][k][j+1]>dp[i-1][k][j]*a[i])) {
                    dp[i][k][j+1]=dp[i-1][k][j]*a[i];
                    par[i][k][j+1]=mp(k, j);
                }
                int nxt = (k * a[i])%10;
                if (dp[i][nxt][j]==-1 || dp[i-1][k][j] < dp[i][nxt][j]) {
                    dp[i][nxt][j] = dp[i-1][k][j];
                    par[i][nxt][j]=mp(k, j);
                }
            }
        }
    }
    ans.clear();
    int dig = d, ex=0;
    FOR(i, 1, 4) if (dp[n-1][d][ex]==-1 || (dp[n-1][d][i]!=-1 && dp[n-1][d][i]<dp[n-1][d][ex])) ex=i;
    if (dp[n-1][d][ex]==-1) {
        cout << -1 << endl;
        return 0;
    }
    R0F(i, n) {
        if (i==0 && dp[i][dig][ex]>1) continue;
        pi cur = par[i][dig][ex];
        if (i>0 && cur.S<ex) {
            ex=cur.S;
            continue;
        }
        ans.pb(a[i]);
        dig = cur.F;
    }
    sort(all(ans));
    cout << ans.size() << '\n';
    for (int i : ans) cout << i << ' ';
    cout << '\n';
}