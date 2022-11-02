#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
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


const int INF=1001001001;
int M,N,K,T;
int A[222222];
int L[222222],R[222222],D[222222];

int uni(vpint &lis){
    sort(all(lis));
    int ans=0;
    int r=-1;
    for(auto &pr:lis){
        if(pr.fi>r){
            r=pr.se;
            ans-=pr.fi;
            ans+=pr.se;
        }
        else{
            ans+=max(0ll,pr.se-r);
            chmax(r,pr.se);
        }
    }
    return ans;
}

signed main(){
    scanf("%lld%lld%lld%lld",&M,&N,&K,&T);
    rep(i,M)scanf("%lld",&A[i]);
    rep(i,K)scanf("%lld%lld%lld",&L[i],&R[i],&D[i]),L[i]--;

    sort(A,A+M);
    int lb=0,ub=M+1;
    while(ub-lb>1){
        int mid=(ub+lb)/2;

        int p=A[M-mid];

        vpint lis;
        rep(i,K)if(D[i]>p)lis.eb(L[i],R[i]);
        int t=N+1+uni(lis)*2;
        if(t<=T)lb=mid;
        else ub=mid;
    }
    cout<<lb<<endl;
    return 0;
}