#include <bits/stdc++.h>
#define ll long long
#define INF 1000000005
#define MOD 1000000007
#define EPS 1e-10
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rrep(i,n) for(int i=(int)(n)-1;i>=0;--i)
#define srep(i,s,t) for(int i=(int)(s);i<(int)(t);++i)
#define each(a,b) for(auto& (a): (b))
#define all(v) (v).begin(),(v).end()
#define len(v) (int)(v).size()
#define zip(v) sort(all(v)),v.erase(unique(all(v)),v.end())
#define cmx(x,y) x=max(x,y)
#define cmn(x,y) x=min(x,y)
#define fi first
#define se second
#define pb push_back
#define show(x) cout<<#x<<" = "<<(x)<<endl
#define spair(p) cout<<#p<<": "<<p.fi<<" "<<p.se<<endl
#define sar(a,n) cout<<#a<<":";rep(pachico,n)cout<<" "<<a[pachico];cout<<endl
#define svec(v) cout<<#v<<":";rep(pachico,v.size())cout<<" "<<v[pachico];cout<<endl
#define svecp(v) cout<<#v<<":";each(pachico,v)cout<<" {"<<pachico.first<<":"<<pachico.second<<"}";cout<<endl
#define sset(s) cout<<#s<<":";each(pachico,s)cout<<" "<<pachico;cout<<endl
#define smap(m) cout<<#m<<":";each(pachico,m)cout<<" {"<<pachico.first<<":"<<pachico.second<<"}";cout<<endl

using namespace std;

typedef pair<int,int> P;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<double> vd;
typedef vector<P> vp;
typedef vector<string> vs;

const int MAX_N = 100005;

int dp[20001][51][101];
int dp2[20001][51];
int a[20001];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,K,p;
    cin >> n >> K >> p;
    rep(i,n){
        cin >> a[i];
    }
    rep(i,n+1){
        rep(j,K+1){
            dp2[i][j] = -INF;
            rep(k,p){
                dp[i][j][k] = -INF;
            }
        }
    }
    dp[0][0][0] = 0;
    dp2[0][0] = 0;
    srep(i,1,n+1){
        srep(j,1,K+1){
            rep(k,p){
                dp[i][j][k] = dp[i-1][j][(k+p-a[i-1]%p)%p] - (k+p-a[i-1]%p)%p + k;
                cmx(dp2[i][j],dp[i][j][k]);
            }
            cmx(dp[i][j][a[i-1]%p],dp2[i-1][j-1] + a[i-1] % p);
            cmx(dp2[i][j],dp[i][j][a[i-1]%p]);
        }
    }
    cout << *max_element(dp[n][K],dp[n][K]+p) << "\n";
    return 0;
}