#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;
typedef vector<bool> vb;
typedef vector<pair<int,int>> vpi;
 
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)
 
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define pi pair<int, int>
#define mp make_pair
#define F first
#define S second

int n;
vi p, factors;
vll dp;
ll MOD = 998244353;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    p.rsz(n+1, -1);
    for (int i = 4; i <= n; i += 2) p[i]=2;
    for (int i = 3; i <= n; i += 2) {
        if (p[i]==-1) for (ll j = (ll)i*(ll)i; j <= n; j += (ll)i) p[j]=i;
    }
    factors.rsz(n+1);
    factors[1]=1;
    for (int i = 2; i <= n; i++) {
        if (p[i]==-1) factors[i]=2;
        else {
            int cnt = 1, x=i;
            while (x%p[i]==0) {
                cnt++;
                x /= p[i];
            }
            factors[i]=factors[x]*cnt;
        }
    }
    dp.rsz(n+1, 0);
    dp[1]=1;
    ll sum = 1;
    for (int i = 2; i <= n; i++) {
        dp[i]=(sum+factors[i])%MOD;
        sum = (sum+dp[i])%MOD;
    }
    cout << dp[n] << '\n';
}