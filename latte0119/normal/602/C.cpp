#include<bits/stdc++.h>
using namespace std;

//#define int long long

typedef pair<int,int>pint;
typedef vector<int>vint;
#define pb push_back
#define mp make_pair
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
template<class T,class U>void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>void chmax(T &t,U f){if(t<f)t=f;}

const int INF=10101010;

int E[400][400];
int dist[400][400];
int N,M;

signed main(){
    scanf("%d%d",&N,&M);
    rep(i,M){
        int a,b;
        scanf("%d%d",&a,&b);
        a--;b--;
        E[a][b]=E[b][a]=1;
    }

    if(E[0][N-1]){
        rep(i,N)rep(j,N)E[i][j]=1-E[i][j];
    }

    fill_n(*dist,400*400,INF);
    rep(i,N)dist[i][i]=0;

    rep(i,N)rep(j,N){
        if(i==j)continue;
        dist[i][j]=E[i][j]?1:INF;
    }

    rep(k,N)rep(i,N)rep(j,N)dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);

    if(dist[0][N-1]==INF)puts("-1");
    else printf("%d\n",dist[0][N-1]);
    return 0;
}