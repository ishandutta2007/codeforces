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

int N,K,S,T;
vint v;

bool C(int u){
    int t=0;
    for(int i=0;i+1<v.size();i++){
        int d=v[i+1]-v[i];
        if(d*2<=u)t+=d;
        else if(d>u)return false;
        else{
            int d2=u-d;
            int d1=d-d2;
            t+=d1*2+d2;
        }
    }
    return t<=T;
}

signed main(){
    v={0};
    scanf("%lld%lld%lld%lld",&N,&K,&S,&T);

    vint A(N),B(N);
    rep(i,N)scanf("%lld%lld",&A[i],&B[i]);

    rep(i,K){
        int a;
        scanf("%lld",&a);
        v.pb(a);
    }
    v.pb(S);
    sort(all(v));


    int lb=0,ub=INT_MAX;
    while(ub-lb>1){
        int mid=(ub+lb)/2;
        if(C(mid))ub=mid;
        else lb=mid;
    }

    int ans=INT_MAX;
    rep(i,N){
        if(B[i]<=lb)continue;
        chmin(ans,A[i]);
    }
    if(ans==INT_MAX)ans=-1;
    printf("%lld\n",ans);
    return 0;
}