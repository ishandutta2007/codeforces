#include<bits/stdc++.h>
using namespace std;

#define int long long

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

int N;
int A[222222];
int gain[222222];

signed main(){
    scanf("%lld",&N);
    rep(i,N)scanf("%lld",&A[i]);
    map<pint,int>mile;

    int M;scanf("%lld",&M);
    int ans=accumulate(A,A+N,0ll);
    rep(i,M){
        int s,t,u;
        scanf("%lld%lld%lld",&s,&t,&u);
        s--;
        if(mile.find(pint(s,t))!=mile.end()){
            int v=mile[pint(s,t)];
            mile.erase(pint(s,t));
            ans-=max(0ll,A[v]-gain[v]);
            gain[v]--;
            ans+=max(0ll,A[v]-gain[v]);
        }
        if(u==0){

        }
        else{
            u--;
            mile[pint(s,t)]=u;
            ans-=max(0ll,A[u]-gain[u]);
            gain[u]++;
            ans+=max(0ll,A[u]-gain[u]);
        }
        printf("%lld\n",ans);
    }
    return 0;
}