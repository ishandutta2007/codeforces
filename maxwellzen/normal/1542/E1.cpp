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
ll MOD;
vll sum[501]; // sum[i][k]: # ways for permutation of i numbers to have k inversions
vll prefsum[501];
vll ans;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> MOD;
    // n=4; MOD=403458273;
    int nc2 = n*(n-1)/2;
    sum[1].rsz(nc2+1, 0);
    prefsum[1].rsz(nc2+1, 0);
    sum[1][0]=1;
    F0R(k, nc2+1) prefsum[1][k]=1;
    ans.rsz(n+1, 0);
    FOR(i, 2, n+1) {
        sum[i].rsz(nc2+1, 0);
        prefsum[i].rsz(nc2+1, 0);
        int ic2 = i*(i-1)/2;
        F0R(k, ic2+1) {
            sum[i][k]=(prefsum[i-1][k]-(k >= i ? prefsum[i-1][k-i] : 0))%MOD;
            while (sum[i][k]<0) sum[i][k] += MOD;
        }
        prefsum[i][0]=sum[i][0];
        FOR(k, 1, nc2+1) prefsum[i][k] = (sum[i][k] + prefsum[i][k-1])%MOD;
        FOR(k, 1, nc2+1) prefsum[i-1][k] = (prefsum[i-1][k] + prefsum[i-1][k-1])%MOD;
        ans[i]=(i*ans[i-1])%MOD;
        F0R(j, i) {
            FOR(inv1, j+2, ic2) {
                ans[i] = (ans[i] + sum[i-1][inv1-j]*(prefsum[i-1][inv1-j-2]-(inv1>i ? prefsum[i-1][inv1-i-1]:0)))%MOD;
            }
        }
        sum[i-1].clear();
        prefsum[i-1].clear();
    }
    ans[n] %= MOD;
    while (ans[n]<0) ans[n] += MOD;
    cout << ans[n] << '\n';
}