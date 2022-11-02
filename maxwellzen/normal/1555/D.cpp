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

int n, m, l, r;
string s;
vi a;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    a.rsz(n);
    cin >> s;
    F0R(i, n) a[i] = s[i]-'a';
    int p[n][3][3];
    int perms[6][3] = {{0,1,2}, {0,2,1}, {1,0,2}, {1,2,0}, {2,0,1}, {2,1,0}};
    F0R(i, n) {
        F0R(c, 3) {
            F0R(j, 3) {
                if (a[i]==c && i%3 != j) p[i][c][j]=1;
                else p[i][c][j]=0;
                if (i>0) p[i][c][j] += p[i-1][c][j];
            }
        }
    }
    F0R(q, m) {
        cin >> l >> r;
        l--; r--;
        int ans = 1e9;
        F0R(i, 6) {
            int cur = 0;
            F0R(j, 3) cur += p[r][j][perms[i][j]] - (l==0 ? 0 : p[l-1][j][perms[i][j]]);
            ans = min(ans, cur);
        }
        cout << ans << '\n';
    }
}