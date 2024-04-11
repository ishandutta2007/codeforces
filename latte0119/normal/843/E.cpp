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


struct edge{
    int to,cap,rev,id;
    edge(int to,int cap,int rev,int id):to(to),cap(cap),rev(rev),id(id){}
};

const int INF=1001001001;
vector<edge>G[222];
void add_edge(int from,int to,int cap,int id){
    G[from].pb(edge(to,cap,G[to].size(),id));
    G[to].pb(edge(from,0,G[from].size()-1,-1));
}

bool used[222];

int dfs(int v,int t,int f){
    if(v==t)return f;
    used[v]=true;
    for(auto &e:G[v]){
        if(used[e.to]||e.cap==0)continue;
        int ff=dfs(e.to,t,min(f,e.cap));
        if(ff==0)continue;
        e.cap-=ff;
        G[e.to][e.rev].cap+=ff;
        return ff;
    }
    return 0;
}
int max_flow(int s,int t){
    int f=0;
    while(true){
        memset(used,0,sizeof(used));
        int ff=dfs(s,t,INF);
        if(ff==0)return f;
        f+=ff;
    }
}

int N,M,S,T;
int A[1111],B[1111],C[1111];
bool ei[1111];
int cap[1111];
vpint G2[1111];
bool dfs2(int v,int t){
    used[v]=true;
    for(auto &e:G2[v]){
        if(used[e.fi])continue;
        if(!dfs2(e.fi,t))continue;
        cap[e.se]++;
        return true;
    }
    return false;
}
signed main(){
    scanf("%lld%lld%lld%lld",&N,&M,&S,&T);
    S--;T--;

    rep(i,M){
        scanf("%lld%lld%lld",&A[i],&B[i],&C[i]);
        A[i]--;B[i]--;
        if(C[i]==0){
            add_edge(A[i],B[i],INF,-1);
        }
        else{
            add_edge(B[i],A[i],INF,-1);
            add_edge(A[i],B[i],1,i);
        }
    }

    printf("%lld\n",max_flow(S,T));

    memset(used,0,sizeof(used));
    queue<int>que;
    que.push(S);
    used[S]=true;
    while(que.size()){
        int v=que.front();
        que.pop();
        for(auto &e:G[v]){
            if(e.cap==0||used[e.to])continue;
            used[e.to]=true;
            que.push(e.to);
        }
    }

    rep(i,222){
        for(auto &e:G[i]){
            if(e.id==-1)continue;
            if(used[i]&&!used[e.to])ei[e.id]=true;
        }
    }

    rep(i,M){
        if(C[i]==0)continue;
        G2[A[i]].pb({B[i],i});
    }


    rep(i,M){
        if(C[i]==0){
            cap[i]=1;
            continue;
        }
        memset(used,0,sizeof(used));
        dfs2(S,A[i]);
        dfs2(B[i],T);
        cap[i]++;
    }


    rep(i,M){
        int f=cap[i];
        if(C[i]==0)f=0;
        else if(C[i]==1&&!ei[i])cap[i]++;
        printf("%lld %lld\n",f,cap[i]);
    }
    return 0;
}