#include <bits/stdc++.h>

using namespace std;

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
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
int t, n, k;
const int MOD = 1000000007;

void solve() {
    cin >> n >> k;
    if (k==1) {
        cout << 1 << '\n';
        return;
    }
    vll planes(n, 1);
    F0R(i, n) planes[i]=1;
    ll ans = n;
    F0R(i, k-2) {
        vll next(n, 0);
        if (i%2==0) {
            next[0]=0;
            FOR(j, 1, n) {
                next[j] = (next[j-1]+planes[j-1])%MOD;
                ans += next[j];
                ans %= MOD;
            }
        } else {
            next[n-1]=0;
            for (int j = n-2; j >= 0; j--) {
                next[j]=(next[j+1]+planes[j+1])%MOD;
                ans += next[j];
                ans %= MOD;
            }
        }
        F0R(j, n) planes[j]=next[j];
    }
    cout << ans+1 << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--) {
        solve();
    }
}