#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
const int N = 1<<19;
const int mod = 1e9+7;

int add(int a, int b) {
    return (a+b)%mod;
}

int mul(int a,int b) {
    ll g = (1LL*a*b)%mod;
    return (int) g;
}

int power(int b, int p) {
    if(p == 0) return 1;
    int g = power(b,p/2);
    g = mul(g,g);
    if(p%2 == 1)
        g = mul(g,b);
    return g;
}

int inv(int b) {
    return power(b,mod-2);
}

int fac[N];

int binom(int n, int r) {
    if(r > n || r < 0)
        return 0;
    return mul(fac[n],inv(mul(fac[r],fac[n-r])));
}

void solve(){
    int cur = 1;
    for(int i=1;i<N;i++) {
        cur = mul(cur,i);
        fac[i] = cur;
    }
    fac[0] = 1;
    int pt = N/2;
    int n; cin>>n;
    int ans = 0;
    for(int i=0;i<n+5;i++) {
//        cout<<i<<endl;
        int k = 0;
        if(i < n+1) cin>>k;
//        cout<<i<<' '<<k<<' '<<pt<<endl;
        while(pt > k) {
            //We get to sum to k
            ans = add(ans, binom(pt+i-1,i-1));
            // if(binom(pt+i-1,i-1) > 0) {
            //     cout<<pt<<' '<<i<<endl;
            // }
            pt--;
        }
    }
    cout<<ans;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 1;
//    cin>>T; // Comment this out if it is a single testcase
    while(T--)
        solve();
    return 0;
}