#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define fi first
#define se second

typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

const int SEG=1<<17;
int N,Q,S;

vpint G[SEG*4];

void addEdge(int a,int b,int x,int t,int w,int k=0,int l=0,int r=SEG){
    if(r<=a||b<=l)return;
    if(a<=l&&r<=b){
        if(t==2){
            G[(x+SEG-1)*2+1].pb({k*2,w});
        }
        else if(t==3){
            G[k*2+1].pb({(x+SEG-1)*2,w});
        }
        return;
    }
    addEdge(a,b,x,t,w,k*2+1,l,(l+r)/2);
    addEdge(a,b,x,t,w,k*2+2,(l+r)/2,r);
}

const int INF=1001001001001001001ll;
int dist[SEG*4];
signed main(){
    scanf("%lld%lld%lld",&N,&Q,&S);
    S--;
    rep(i,Q){
        int t,v,l,r,w;
        scanf("%lld",&t);
        if(t==1){
            scanf("%lld%lld%lld",&v,&l,&w);
            l--;
            v--;
            r=l+1;
            t=2;
        }
        else{
            scanf("%lld%lld%lld%lld",&v,&l,&r,&w);
            l--;
            v--;
        }

        addEdge(l,r,v,t,w);
    }

    fill_n(dist,SEG*4,INF);

    dist[(S+SEG-1)*2]=0;
    priority_queue<pint,vector<pint>,greater<pint>>que;
    que.push({0,(S+SEG-1)*2});
    while(que.size()){
        int c,v;
        tie(c,v)=que.top();
        que.pop();
        if(dist[v]<c)continue;
        for(auto &e:G[v]){
            if(dist[e.fi]<=dist[v]+e.se)continue;
            dist[e.fi]=dist[v]+e.se;
            que.push({dist[e.fi],e.fi});
        }

        if(v&1){
            if(v/2!=0){
                int u=(v/2-1)/2;
                if(dist[u*2+1]>dist[v]){
                    dist[u*2+1]=dist[v];
                    que.push({dist[u*2+1],u*2+1});
                }
            }
        }
        else{
            int u=v^1;
            if(dist[u]>dist[v]){
                dist[u]=dist[v];
                que.push({dist[u],u});
            }
            if(v/2<SEG-1){
                u=v/2*2+1;
                if(dist[u*2]>dist[v]){
                    dist[u*2]=dist[v];
                    que.push({dist[u*2],u*2});
                }
                u=v/2*2+2;
                if(dist[u*2]>dist[v]){
                    dist[u*2]=dist[v];
                    que.push({dist[u*2],u*2});
                }
            }
        }
    }

    rep(i,N){
        if(dist[(i+SEG-1)*2]==INF)printf("-1 ");
        else printf("%lld ",dist[(i+SEG-1)*2]);
    }puts("");
    return 0;
}