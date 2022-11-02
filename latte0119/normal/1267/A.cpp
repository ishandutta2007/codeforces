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
using tap=tuple<int,int,int>;
int N;
int A[222222],B[222222],T[222222];

const int INF=1001001001001001001ll*3;
signed main(){
    scanf("%lld",&N);
    rep(i,N)scanf("%lld%lld%lld",&A[i],&B[i],&T[i]);


    rep(i,N){
        B[i]=B[i]-T[i]+1;
    }

    priority_queue<tap,vector<tap>,greater<tap>>que;
    rep(i,N)que.emplace(A[i],B[i],T[i]);
    vector<tap>lis;
    while(que.size()){
        int ll,rr,tt;
        tie(ll,rr,tt)=que.top();
        que.pop();
        if(lis.size()==0){
            lis.eb(ll,rr,tt);
            continue;
        }

        int l,r,t;
        tie(l,r,t)=lis.back();

        if(r<=ll){
            lis.eb(ll,rr,tt);
            continue;
        }
        if(t<=tt){
            if(r<rr)que.emplace(r,rr,tt);
            continue;
        }
        lis.pop_back();
        if(l<ll){
            lis.eb(l,ll,t);
        }
        lis.eb(ll,rr,tt);
        if(rr<r){
            que.emplace(rr,r,t);
        }
    }

    reverse(all(lis));
    vector<tap>nex;
    int pos=INF;
    for(auto &uku:lis){
        int l,r,t;
        tie(l,r,t)=uku;
        if(l+t>=pos)continue;
        chmin(r,pos-t);
        chmin(pos,l+t);
        nex.eb(l,r,t);
    }

    lis=nex;
    
    int cur=-INF;
    int ans=0;
    while(lis.size()){
        int l,r,t;
        tie(l,r,t)=lis.back();
        lis.pop_back();
        chmax(cur,l);
        int tmp=(r-cur+t-1)/t;
        ans+=tmp;
        cur+=t*tmp;
    }
    cout<<ans<<endl;
    return 0;
}