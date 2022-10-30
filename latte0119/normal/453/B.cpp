#include<bits/stdc++.h>
using namespace std;

typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define all(v) (v).begin(),(v).end()
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
#define pb push_back
#define fi first
#define se second
template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

const int INF=1001001001;
bool f[1111];
vint ps;
int dp[111][1<<16];
int pre[111][1<<16];
int b[60];
signed main(){
    fill_n(f,1111,1);
    f[0]=f[1]=1;
    for(int i=2;i<1111;i++){
        if(!f[i])continue;
        ps.pb(i);
        for(int j=i*2;j<1111;j+=i)f[j]=0;
    }

    for(int i=1;i<59;i++){
        for(int j=0;j<16;j++)if(i%ps[j]==0)b[i]|=1<<j;
    }

    fill_n(*dp,111*(1<<16),INF);
    memset(pre,-1,sizeof(pre));

    int N;cin>>N;
    vint A(N);rep(i,N)cin>>A[i];
    dp[0][0]=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<(1<<16);j++){
            for(int k=1;k<59;k++){
                if(j&b[k])continue;
                int tmp=dp[i][j]+abs(A[i]-k);
                if(dp[i+1][j|b[k]]>tmp){
                    dp[i+1][j|b[k]]=tmp;
                    pre[i+1][j|b[k]]=k;
                }
            }
        }
    }

    vint ans;
    int t=0;
    rep(i,1<<16)if(dp[N][i]<dp[N][t])t=i;

    for(int i=N;i>0;i--){
        ans.pb(pre[i][t]);
        t^=b[pre[i][t]];
    }

    reverse(all(ans));
    rep(i,ans.size())cout<<ans[i]<<" ";cout<<endl;
    return 0;
}