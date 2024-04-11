#include<bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int,int>pint;
typedef vector<int>vint;
typedef vector<pint>vpint;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
template<class T,class U>inline void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>inline void chmax(T &t,U f){if(t<f)t=f;}

int f[1111111];
vint prime;

int n,m;
int a[1111111];

int dp[1111111];

signed main(){
    fill_n(f,1111111,1);f[0]=f[1]=0;
    scanf("%lld%lld",&n,&m);
    rep(i,n)scanf("%lld",&a[i]);
    for(int i=2;i<=m;i++){
        if(!f[i])continue;
        prime.pb(i);
        for(int j=i+i;j<=m;j+=i)f[j]=0;
    }

    rep(i,n)if(a[i]<=m)dp[a[i]]++;
    for(int p:prime){
        for(int i=1;i<=m;i++){
            if(i*p>m)break;
            dp[i*p]+=dp[i];
        }
    }

    int ma=1;
    for(int i=2;i<=m;i++)if(dp[ma]<dp[i])ma=i;
    vint ans;
    rep(i,n)if(ma%a[i]==0)ans.pb(i);
    printf("%lld %lld\n",ma,dp[ma]);
    rep(i,ans.size())printf("%lld ",ans[i]+1);
    puts("");
    return 0;
}