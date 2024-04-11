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

int t;
ll x, ans, MOD=1e9+7;

vi factor;

void sieve(int n) {
    factor.clear();
    factor.rsz(n+1, 0);
    for (int i = 2; i <= n; i++) {
        if (factor[i]==0) {
            if ((ll)i*i<=n) for (int j = i*i; j <= n; j += i) factor[j]=i;
        }
    }
}

bool ispower(ll i, ll p) {
    // cout << i << ' ' << p << endl;
    while (i%p==0) i /= p;
    return i==1;
}
 
void solve() {
    cin >> x;
    ans=0;
    for (int i = 2; i <= 10000; i++) {
        if (x==0) break;
        ll p=-1;
        if (factor[i]==0) p=i;
        else if (ispower(i, factor[i])) p=factor[i];
        if (p==-1) continue;
        ll remain = x/p;
        ans += (ll)i*(x-remain);
        ans %= MOD;
        x=remain;
    }
    cout << ans << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sieve(10000);
    cin >> t;
    while (t--) {
        solve();
    }
}