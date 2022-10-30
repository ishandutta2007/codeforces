#include<bits/stdc++.h>
using namespace std;

#define int long long
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

int N;
int A[1111];

int table[8][1001][200];

int ans;
int dp[1<<8][1001];
bool lattemalta(int n){
    fill_n(*dp,(1<<8)*1001,INT_MIN);
    dp[0][0]=0;
    for(int i=0;i<(1<<8);i++){
        for(int j=0;j<=N;j++){
            for(int k=0;k<8;k++){
                if(i>>k&1)continue;
                for(int l=n;l<=n+1;l++){
                    if(table[k][j][l]==-1)continue;
                    chmax(dp[i|(1<<k)][table[k][j][l]],dp[i][j]+l);
                }
            }
        }
    }
    bool ret=false;
    for(int i=0;i<=N;i++){
        chmax(ans,dp[(1<<8)-1][i]);
        if(dp[(1<<8)-1][i]>=0)ret=true;
    }
    return ret;
}

signed main(){
    cin>>N;
    rep(i,N)cin>>A[i],A[i]--;
    vector<int>idx[8];
    rep(i,N)idx[A[i]].pb(i);
    for(int i=0;i<8;i++){
        for(int j=0;j<=N;j++){
            for(int k=0;k<200;k++){
                if(k==0){
                    table[i][j][k]=j;
                }
                else{
                    int l=lower_bound(all(idx[i]),j)-idx[i].begin();
                    if(l+k-1<idx[i].size()){
                        table[i][j][k]=idx[i][l+k-1]+1;
                    }
                    else{
                        table[i][j][k]=-1;
                    }
                }
            }
        }
    }

    int lb=0,ub=N/8+1;
    while(ub-lb>1){
        int mid=(ub+lb)/2;
        if(lattemalta(mid))lb=mid;
        else ub=mid;
    }
    lattemalta(lb);
    cout<<ans<<endl;
}