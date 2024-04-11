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

int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}

const int INF=1001001001;

namespace SCC{
    void visit(const vector<vector<int>>&G,vector<int>&vs,vector<int>&used,int v){
        used[v]=true;
        for(auto u:G[v]){
            if(!used[u])visit(G,vs,used,u);
        }
        vs.push_back(v);
    }

    void visit2(const vector<vector<int>>&T,vector<int>&used,vector<int>&comp,vector<int>&vec,int k,int v){
        comp[v]=k;
        used[v]=true;
        vec.push_back(v);

        for(auto u:T[v]){
            if(!used[u])visit2(T,used,comp,vec,k,u);
        }
    }

    void decompose(const vector<vector<int>>&G,vector<vector<int>>&H,vector<int>&comp){
        vector<vector<int>>T(G.size());
        for(int i=0;i<G.size();i++){
            for(auto v:G[i]){
                T[v].push_back(i);
            }
        }
        comp.resize(G.size());

        vector<int>vs(G.size());
        vector<int>used(G.size());
        for(int i=0;i<G.size();i++){
            if(!used[i])visit(G,vs,used,i);
        }
        reverse(vs.begin(),vs.end());
        fill(used.begin(),used.end(),0);

        int K=0;
        vector<vector<int>>S;
        for(auto v:vs){
            if(!used[v]){
                S.push_back(vector<int>());
                visit2(T,used,comp,S.back(),K++,v);
            }
        }

        H.resize(K);
        fill(used.begin(),used.end(),0);
        for(int i=0;i<K;i++){
            for(auto v:S[i]){
                for(auto u:G[v]){
                    if(used[comp[u]]||comp[v]==comp[u])continue;
                    used[comp[u]]=true;
                    H[comp[v]].push_back(comp[u]);
                }
            }
            for(auto v:H[i])used[v]=false;
        }

    }
}


int N,M,D;

vector<vint>G;
int op[111111];

int dp[111111][55];
char ukuku[55];

int vis[111111];
int d[111111];
signed main(){
    scanf("%lld%lld%lld",&N,&M,&D);
    G.resize(N);
    rep(i,M){
        int a,b;
        scanf("%lld%lld",&a,&b);
        a--;b--;
        G[a].pb(b);
    }

    rep(i,N){
        scanf("%s",ukuku);
        rep(j,D){
            if(ukuku[j]=='1')op[i]+=1ll<<j;
        }
    }

    vector<vint>H;
    vint comp;

    SCC::decompose(G,H,comp);

    fill_n(*dp,111111*55,-INF);
    dp[0][0]=0;

    vector<vint>uku(H.size());
    rep(i,N)uku[comp[i]].pb(i);

    for(int k=0;k<H.size();k++){
        vint vs=uku[k];

        int s=vs[0];
        vis[s]=1;
        queue<pint>que;
        que.push({s,0});
        while(que.size()){
            int v,p;
            tie(v,p)=que.front();
            que.pop();
            for(auto u:G[v]){
                if(comp[u]!=k)continue;
                int q=(p+1)%D;
                if(vis[u]>>q&1)continue;
                vis[u]|=1ll<<q;
                que.push({u,q});
            }
        }

        int L=D;
        
        for(int i=1;i<D;i++)if(vis[s]>>i&1){
            L=i;
            break;
        }
        
        for(auto v:vs){
            for(int i=0;i<D;i++)if(vis[v]>>i&1){
                d[v]=i;break;
            }
        }


        for(auto v:vs){
            for(int i=D-1;i>=L;i--){
                chmax(dp[v][i-L],dp[v][i]);
            }
            for(int i=0;i<D;i++){
                chmax(dp[s][i],dp[v][(i+d[v])%L]);
            }
        }

        for(auto v:vs){
            int b=0;
            rep(i,D)if(op[v]>>i&1)b|=1ll<<(i%L);


            rep(i,L){
                if(b>>((i+d[v])%L)&1)dp[s][i]++;
            }
        }

        for(auto v:vs){
            rep(i,D){
                int val=dp[s][(i-d[v]+L)%L];
                for(auto u:G[v])if(comp[u]!=k)chmax(dp[u][(i+1)%D],val);
            }
        }
    }

    int ans=0;
    rep(i,N)rep(j,D)chmax(ans,dp[i][j]);
    printf("%lld\n",ans);
    return 0;
}