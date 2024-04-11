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

int N,X,K;
int A[200000];

void solve1(){
    priority_queue<pint,vector<pint>,greater<pint>>que;
    rep(i,N)que.push(pint(abs(A[i]),i));
    while(K>0&&que.size()){
        int v=que.top().se;
        que.pop();
        if(A[v]>=0)A[v]+=X;
        else A[v]-=X;
        K--;
        que.push(pint(abs(A[v]),v));
    }

    rep(i,N)printf("%lld ",A[i]);
}

void solve2(){
    int mi=0,miv=LLONG_MAX;
    rep(i,N){
        int val;
        if(A[i]>=0)val=A[i]+1;
        else val=-A[i];
        if(miv>val){
            mi=i;
            miv=val;
        }
    }

    miv=(miv+X-1)/X;
    if(A[mi]<0)A[mi]+=miv*X;
    else A[mi]-=miv*X;
    K-=miv;

    assert(K>=0);
    solve1();
}

void solve3(){
    priority_queue<pint,vector<pint>,greater<pint>>que;
    rep(i,N)que.push(pint(abs(A[i]),i));
    while(K>0&&que.size()){
        int v=que.top().se;
        que.pop();
        if(A[v]>=0)A[v]-=X;
        else A[v]+=X;
        K--;
        que.push(pint(abs(A[v]),v));
    }

    rep(i,N)printf("%lld ",A[i]);
}

signed main(){
    scanf("%lld%lld%lld",&N,&K,&X);
    rep(i,N)scanf("%lld",&A[i]);

    bool can=false;
    int cnt=0;
    rep(i,N){
        if(A[i]<0)cnt++;
        if(A[i]<0&&A[i]+K*X>=0)can=true;
        if(A[i]>=0&&A[i]-K*X<0)can=true;
    }

    if(cnt%2)solve1();
    else if(can)solve2();
    else solve3();
    return 0;
}