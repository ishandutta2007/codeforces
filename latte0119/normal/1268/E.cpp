#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second

using vint=vector<int>;
using pint=pair<int,int>;
using vpint=vector<pint>;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

template<class A,class B>
ostream& operator<<(ostream& ost,const pair<A,B>&p){
    ost<<"{"<<p.first<<","<<p.second<<"}";
    return ost;
}

template<class T>
ostream& operator<<(ostream& ost,const vector<T>&v){
    ost<<"{";
    for(int i=0;i<v.size();i++){
        if(i)ost<<",";
        ost<<v[i];
    }
    ost<<"}";
    return ost;
}

struct Cactus{
    vector<vector<int>>G;
    vector<vector<int>>cs;
    vector<int>vis,par,dep;
    void dfs(int v){
        vis[v]=1;
        for(auto u:G[v]){
            if(!vis[u]){
                par[u]=v;
                dep[u]=dep[v]+1;
                dfs(u);
            }
            else if(dep[u]<dep[v]){
                int w=v;
                vector<int>c{w};
                while(true){
                    w=par[w];
                    c.push_back(w);
                    if(w==u)break;
                }
                cs.push_back(c);
            }
        }
    }
    Cactus(const vector<vector<int>>&G):G(G){
        vis.resize(G.size());
        par.resize(G.size());
        dep.resize(G.size());
        dfs(0);
    }
};

int N,M;
int A[555555],B[555555];

int info[555555];

int dp[555555];
int memA[555555],memB[555555];
signed main(){
    scanf("%d%d",&N,&M);

    vint lis;
    vector<vint>G(N);
    map<pint,int>edgeID;
    rep(i,M){
        scanf("%d%d",&A[i],&B[i]);
        A[i]--;B[i]--;
        G[A[i]].pb(B[i]);
        G[B[i]].pb(A[i]);
        edgeID[{A[i],B[i]}]=i;
        edgeID[{B[i],A[i]}]=i;
    }

    Cactus cac(G);

    fill_n(info,M,-1);
    
    for(auto c:cac.cs){
        if(c.size()==2)continue;
        vint id;
        rep(i,c.size()){
            int a=c[i];
            int b=c[(i+1)%c.size()];
            id.pb(edgeID[{a,b}]);
        }
        rotate(id.begin(),min_element(all(id)),id.end());
        int m=max_element(all(id))-id.begin();
        bool ok=true;
        for(int i=0;i<m;i++)if(id[i]>id[i+1])ok=false;
        for(int i=m;i+1<id.size();i++)if(id[i]<id[i+1])ok=false;
        if(!ok)continue;

        info[id[0]]=id[m];
    }

    rep(i,N)dp[i]=1;
    for(int i=M-1;i>=0;i--){
        int addA=dp[B[i]];
        int addB=dp[A[i]];
        if(info[i]!=-1){
            int k=info[i];
            int tmp=memA[k]+memB[k];
            addA-=tmp;
            addB-=tmp;
        }
        memA[i]=dp[A[i]];
        memB[i]=dp[B[i]];
        dp[A[i]]+=addA;
        dp[B[i]]+=addB;
    }

    rep(i,N)dp[i]--;

    rep(i,N){
        if(i)printf(" ");
        printf("%d",dp[i]);
    }
    puts("");
    return 0;
}