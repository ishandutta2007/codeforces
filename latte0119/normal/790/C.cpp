#include<bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int,int>pint;
typedef vector<int>vint;
typedef vector<pint>vpint;
#define pb push_back
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
template<class T,class U>inline void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>inline void chmax(T &t,U f){if(t<f)t=f;}

void dbg(){
    cout<<"latte"<<endl;
}

const int INF=1001001001;
int dp[77][77][77][2];

int N;
string S;

int sum[3][77];

signed main(){
    cin>>N>>S;
    vector<int>vs,ks,es;

    rep(i,N){
        if(S[i]=='V'){
            vs.pb(i);
            sum[0][i+1]++;
        }
        else if(S[i]=='K'){
            ks.pb(i);
            sum[1][i+1]++;
        }
        else{
            es.pb(i);
            sum[2][i+1]++;
        }
        rep(j,3)sum[j][i+1]+=sum[j][i];
    }

    fill_n(***dp,77*77*77*2,INF);
    dp[0][0][0][0]=0;
    for(int i=0;i<N;i++){
        rep(v,vs.size()+1)rep(k,ks.size()+1){
            if(i<v+k)continue;
            int e=i-v-k;
            if(e>es.size())continue;
            rep(f,2){
                if(v!=vs.size()){
                    int j=vs[v];
                    int cost=0;
                    cost+=max(0ll,sum[0][j]-v);
                    cost+=max(0ll,sum[1][j]-k);
                    cost+=max(0ll,sum[2][j]-e);
                    chmin(dp[i+1][v+1][k][1],dp[i][v][k][f]+cost);
                }
                if(k!=ks.size()&&f==0){
                    int j=ks[k];
                    int cost=0;
                    cost+=max(0ll,sum[0][j]-v);
                    cost+=max(0ll,sum[1][j]-k);
                    cost+=max(0ll,sum[2][j]-e);
                    chmin(dp[i+1][v][k+1][0],dp[i][v][k][f]+cost);
                }
                if(e!=es.size()){
                    int j=es[e];
                    int cost=0;
                    cost+=max(0ll,sum[0][j]-v);
                    cost+=max(0ll,sum[1][j]-k);
                    cost+=max(0ll,sum[2][j]-e);
                    chmin(dp[i+1][v][k][0],dp[i][v][k][f]+cost);
                }
            }
        }
    }

    cout<<min(dp[N][vs.size()][ks.size()][0],dp[N][vs.size()][ks.size()][1])<<endl;
    return 0;
}