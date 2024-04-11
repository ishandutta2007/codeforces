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

const int INF=1001001001001ll;
int N,M;
int A[10000],B[10000],C[10000];
vint es;

vint dijkstra(int s){
    vint dist(N,INF);
    vector<vpint>G(N);
    rep(i,M){
        G[A[i]].pb(pint(B[i],C[i]));
        G[B[i]].pb(pint(A[i],C[i]));
    }
    dist[s]=0;
    priority_queue<pint,vector<pint>,greater<pint>>que;
    que.push(pint(0,s));
    while(que.size()){
        int v,c;
        tie(c,v)=que.top();
        que.pop();
        if(dist[v]<c)continue;
        for(auto e:G[v]){
            if(dist[e.fi]<=c+e.se)continue;
            dist[e.fi]=c+e.se;
            que.push(pint(dist[e.fi],e.fi));
        }
    }
    return dist;
}

signed main(){
    int L,S,T;
    scanf("%lld%lld%lld%lld%lld",&N,&M,&L,&S,&T);
    rep(i,M){
        scanf("%lld%lld%lld",&A[i],&B[i],&C[i]);
        if(C[i]==0)es.pb(i);
    }

    rep(i,es.size())C[es[i]]=INF;
    vint dist=dijkstra(S);

    if(es.size()==0){
        if(dist[T]!=L){
            puts("NO");
            return 0;
        }
        else{
            puts("YES");
            rep(i,M)printf("%lld %lld %lld\n",A[i],B[i],C[i]);
            return 0;
        }
    }

    if(dist[T]<L){
        cout<<"NO"<<endl;
        return 0;
    }

    rep(i,es.size())C[es[i]]=1;
    dist=dijkstra(S);
    if(dist[T]>L){
        cout<<"NO"<<endl;
        return 0;
    }

    rep(i,es.size())C[es[i]]=INF;

    int l=0,r=es.size();
    while(r-l>1){
        int mid=(l+r)/2;
        reps(i,l,mid){
            C[es[i]]=1;
        }
        dist=dijkstra(S);
        if(dist[T]<=L){
            reps(i,l,mid){
                C[es[i]]=INF;
            }
            r=mid;
        }
        else{
            l=mid;
        }
    }

    int lb=1,ub=INF;
    while(ub-lb>1){
        int mid=(ub+lb)/2;
        C[es[l]]=mid;
        dist=dijkstra(S);
        if(dist[T]<=L)lb=mid;
        else ub=mid;
    }

    C[es[l]]=lb;

    puts("YES");
    rep(i,M)printf("%lld %lld %lld\n",A[i],B[i],C[i]);
}