#include<bits/stdc++.h>
using namespace std;

#define int long long
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define all(v) (v).begin(),(v).end()
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
#define pb push_back
#define fi first
#define se second
template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

const int INF=1001001001001001001ll;
int N,M,K;
vector<pint>G[100000];
int dist[100000];

signed main(){
    scanf("%lld%lld%lld",&N,&M,&K);
    rep(i,M){
        int a,b,c;
        scanf("%lld%lld%lld",&a,&b,&c);
        a--;b--;
        G[a].pb(pint(b,c));
        G[b].pb(pint(a,c));
    }

    fill_n(dist,N,INF);
    priority_queue<pint,vector<pint>,greater<pint>>que;
    rep(i,K){
        int a;
        scanf("%lld",&a);
        a--;
        dist[a]=0;
        que.push(pint(0,a));
    }

    while(que.size()){
        int c,v;
        tie(c,v)=que.top();
        que.pop();
        if(dist[v]<c)continue;
        for(auto e:G[v]){
            if(dist[e.fi]<=c+e.se)continue;
            dist[e.fi]=c+e.se;
            que.push(pint(dist[e.fi],e.fi));
        }
    }

    int mi=INF;
    rep(i,N)if(dist[i]!=0)chmin(mi,dist[i]);
    if(mi==INF)puts("-1");
    else printf("%lld\n",mi);
    return 0;
}