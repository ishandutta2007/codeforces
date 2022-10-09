#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = a; i < b; ++i)
#define trav(x,v) for(auto &x : v)
#define all(v) v.begin(),v.end()
#define sz(v) (int)(v.size())
#define rrep(i,a,b) for(int i = b; i --> a;)
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> pii;
        
const int mx = 411;

ll p;

void add_mod(ll &x, ll d){
        x = (x%p + d%p) % p;
}

vector<vector<ll>> dp(mx, vector<ll>(mx));

int main(){
        cin.sync_with_stdio(0);
        cin.tie(0);
        cin.exceptions(cin.failbit);

        int t;

        cin >> t >> p; 

        vector<ll> f(mx);

        dp[0][0] = 1;

        rep(n,0,mx){
                rep(i,0,n+1) add_mod(f[n], dp[i][n]);
                if(f[n] < 0) f[n] += p;
                if(n >= 4) add_mod(dp[1][n], -f[n]);
                if(n+1 == mx) continue;
                rep(i,0,n+1) rep(d,4,n+1)
                        add_mod(dp[i+1][n+1], -(i+1)*dp[i][n+1-d] % p * f[d]);
                rep(i,0,n+1) rep(d,1,n+2)
                        add_mod(dp[i+1][n+1], (i+1)*dp[i][n+1-d] * (d>1 ? 2 : 1) * (d%2 ? 1 : -1));
        }

        f[2] = 2;

        rep(_,0,t){
                int n;
                cin >> n;
                ll res = f[n];
                res = res % p;
                if(res < 0) res += p;
                cout << res << endl;
        }

}