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

int N,M;
int A[111];
int X[111],Y[111];

struct Dinic{
    struct edge{
        int to,cap,rev;
        edge(int to,int cap,int rev):to(to),cap(cap),rev(rev){}
    };

    static const int INF=1001001001;
    vector<vector<edge>>G;
    vector<int>level,iter;
    Dinic(int v):G(v),level(v),iter(v){}

    void addEdge(int from,int to,int cap){
        G[from].push_back(edge(to,cap,G[to].size()));
        G[to].push_back(edge(from,0,G[from].size()-1));
    }

    void bfs(int s){
        fill(level.begin(),level.end(),-1);
        queue<int>que;
        level[s]=0;
        que.push(s);
        while(que.size()){
            int v=que.front();
            que.pop();
            for(auto &e:G[v]){
                if(e.cap&&level[e.to]==-1){
                    level[e.to]=level[v]+1;
                    que.push(e.to);
                }
            }
        }
    }

    int dfs(int v,int t,int f){
        if(v==t)return f;
        for(int &i=iter[v];i<G[v].size();i++){
            edge &e=G[v][i];
            if(e.cap>0&&level[v]<level[e.to]){
                int d=dfs(e.to,t,min(f,e.cap));
                if(d>0){
                    e.cap-=d;
                    G[e.to][e.rev].cap+=d;
                    return d;
                }
            }
        }
        return 0;
    }

    int maxFlow(int s,int t){
        int flow=0;
        while(true){
            bfs(s);
            if(level[t]<0)return flow;
            fill(iter.begin(),iter.end(),0);
            int f;
            while((f=dfs(s,t,INF))>0)flow+=f;
        }
    }
};

int calc(vint a){
    Dinic d(N+114);
    int src=N,snk=N+1;

    rep(i,N){
        if(i&1){
            d.addEdge(i,snk,a[i]);
        }
        else{
            d.addEdge(src,i,a[i]);
        }
    }
    rep(i,M){
        d.addEdge(X[i],Y[i],Dinic::INF);
    }

    return d.maxFlow(src,snk);
}

signed main(){
    cin>>N>>M;
    rep(i,N)cin>>A[i];
    rep(i,M){
        cin>>X[i]>>Y[i],X[i]--,Y[i]--;
        if(X[i]&1)swap(X[i],Y[i]);
    }
    vint p;
    rep(i,N){
        int a=A[i];
        for(int j=2;j*j<=a;j++){
            if(a%j==0){
                p.pb(j);
                while(a%j==0)a/=j;
            }
        }
        if(a!=1)p.pb(a);
    }

    sort(all(p));p.erase(unique(all(p)),p.end());

    int ans=0;
    for(auto u:p){
        vint a(N);
        rep(i,N){
            while(A[i]%u==0){
                a[i]++;
                A[i]/=u;
            }
        }
        ans+=calc(a);
    }

    cout<<ans<<endl;
    return 0;
}