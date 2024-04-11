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

const int INF=1001001001;
const int INFLL=1001001001001001001ll;
const int mod=1000000007;
inline void am(int &a,int b){
    a+=b;
    if(a>=mod)a-=mod;
}

int dy[]={-1,0,1,0};
int dx[]={0,-1,0,1};

int H,W,N;
int Y[11111],X[11111];


vint G[11111];

vint yoko[11111],tate[11111];

signed main(){
    cin>>H>>W>>N;
    rep(i,N)cin>>Y[i]>>X[i];

    map<pint,int>latte;
    rep(i,N)latte[{Y[i],X[i]}]=i;

    rep(i,N){
        rep(j,4){
            int ny=Y[i]+dy[j];
            int nx=X[i]+dx[j];
            if(latte.find({ny,nx})!=latte.end()){
                G[i].pb(latte[{ny,nx}]);
            }
        }
        yoko[Y[i]].pb(i);
        tate[X[i]].pb(i);
    }

    int s;
    rep(i,N)if(Y[i]==1&&X[i]==1)s=i;

    deque<pint>que;
    que.push_back({0,s});
    vint dist(N,INF);
    dist[s]=0;
    while(que.size()){
        int d,v;
        tie(d,v)=que.front();
        que.pop_front();
        if(dist[v]>d)continue;

        for(auto u:G[v]){
            if(dist[u]>dist[v]){
                dist[u]=dist[v];
                que.push_front({dist[u],u});
            }
        }

        for(int w=-2;w<=2;w++){
            int y=Y[v]+w;
            if(y<=0||y>H)continue;
            for(auto u:yoko[y]){
                if(dist[u]>dist[v]+1){
                    dist[u]=dist[v]+1;
                    que.push_back({dist[u],u});
                }
            }
            yoko[y].clear();
        }

        for(int w=-2;w<=2;w++){
            int x=X[v]+w;
            if(x<=0||x>W)continue;
            for(auto u:tate[x]){
                if(dist[u]>dist[v]+1){
                    dist[u]=dist[v]+1;
                    que.push_back({dist[u],u});
                }
            }
            tate[x].clear();
        }
    }

    int ans=INF;
    rep(i,N){
        if(Y[i]==H&&X[i]==W)ans=dist[i];
        else if(H-Y[i]<=1||W-X[i]<=1)chmin(ans,dist[i]+1);
    }

    if(ans==INF)cout<<-1<<endl;
    else cout<<ans<<endl;
    return 0;
}