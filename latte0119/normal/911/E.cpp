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

int N,K;
int P[222222];
bool ex[222222];
signed main(){
    scanf("%lld%lld",&N,&K);
    rep(i,K)scanf("%lld",&P[i]),P[i]--,ex[P[i]]=1;
    vint stk;
    int nex=0;
    rep(i,K){
        stk.pb(P[i]);
        while(stk.size()&&stk.back()==nex){
            stk.pop_back();
            nex++;
        }
    }

    for(int i=0;i+1<stk.size();i++)if(stk[i]<stk[i+1]){
        cout<<-1<<endl;
        return 0;
    }

    for(int i=K;i<N;i++){
        if(stk.size()==0)stk.pb(N-1);
        else stk.pb(stk.back()-1);
        P[i]=stk.back();
        while(stk.size()&&stk.back()==nex){
            stk.pop_back();
            nex++;
        }
    }

    rep(i,N){
        if(i)printf(" ");
        printf("%lld",P[i]+1);
    }puts("");
    return 0;
}