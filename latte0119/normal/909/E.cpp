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
int E[111111];

vint G[111111];

signed main(){
    scanf("%lld%lld",&N,&M);
    rep(i,N)scanf("%lld",&E[i]);

    vint deg(N);
    rep(i,M){
        int a,b;
        scanf("%lld%lld",&a,&b);
        G[a].pb(b);
        deg[b]++;
    }


    queue<int>que[2];
    rep(i,N){
        if(deg[i]==0)que[E[i]].push(i);
    }

    int ans=0;
    for(int t=0;;t=1-t){
        if(t==1&&que[t].size()==0)break;
        while(que[t].size()){
            int v=que[t].front();
            que[t].pop();
            for(auto u:G[v]){
                if(--deg[u]==0){
                    que[E[u]].push(u);
                }
            }
        }
        ans+=t;
    }
    cout<<ans<<endl;
    return 0;
}