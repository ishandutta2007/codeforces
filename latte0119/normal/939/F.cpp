#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

const int INF=222;
int N,K;
int L[111],R[111];

int dp[2][100010][2];

vpint qs[100010];
int tmp[100010];
signed main(){
    scanf("%lld%lld",&N,&K);
    rep(i,K)scanf("%lld%lld",&L[i],&R[i]);

    if(L[0]>N){
        cout<<"Hungry"<<endl;
        return 0;
    }

    fill_n(**dp,2*100010*2,INF);
    dp[0][L[0]][0]=0;

    L[K]=2*N;

    rep(i,K){
        int X=R[i]-L[i];
        int Y=L[i+1]-R[i];
        rep(j,N+1){
            chmin(dp[i&1][j][1],dp[i&1][j][0]+1);
            chmin(dp[i&1][j][0],dp[i&1][j][1]+1);
        }

        rep(j,N+1){
            chmin(dp[(i+1)&1][j][1],dp[i&1][j][1]);
            if(j+X+Y<=N)chmin(dp[(i+1)&1][j+X+Y][0],dp[i&1][j][0]);
        }
        rep(k,2){
            rep(j,N+1){
                int l=j,r=j+X;
                if(k==1)l+=Y,r+=Y;
                if(l>N)continue;
                chmin(r,N);
                qs[l].pb({dp[i&1][j][k]+1,r});
            }
            priority_queue<pint,vector<pint>,greater<pint>>que;
            rep(j,N+1){
                rep(l,qs[j].size())que.push(qs[j][l]);
                qs[j].clear();
                while(que.size()&&que.top().se<j)que.pop();
                if(que.size())tmp[j]=que.top().fi;
                else tmp[j]=INF;
            }
            rep(j,N+1)chmin(dp[(i+1)&1][j][1-k],tmp[j]);
        }

        rep(j,N+1)dp[i&1][j][0]=dp[i&1][j][1]=INF;
    }

    int ans=min(dp[K&1][N][0],dp[K&1][N][1]);
    if(ans==INF){
        cout<<"Hungry"<<endl;
    }
    else{
        cout<<"Full"<<endl<<ans<<endl;
    }
    return 0;
}