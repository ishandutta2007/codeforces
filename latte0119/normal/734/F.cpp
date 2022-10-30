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

int N;
int A[222222];
int B[222222],C[222222];
int D[222222];

signed main(){
    scanf("%lld",&N);
    rep(i,N)scanf("%lld",&B[i]);
    rep(i,N)scanf("%lld",&C[i]);
    rep(i,N)D[i]=B[i]+C[i];

    int tmp=accumulate(D,D+N,0ll);
    if(tmp%(2*N)){
        puts("-1");
        return 0;
    }

    int sumA=tmp/(2*N);
    rep(i,N){
        if(D[i]<sumA||(D[i]-sumA)%N){
            puts("-1");
            return 0;
        }
        A[i]=(D[i]-sumA)/N;
    }

    int cnt[33]={};
    rep(i,33)rep(j,N)if(A[j]>>i&1)cnt[i]++;

    rep(i,N){
        int b=0,c=0;
        rep(j,33){
            if(A[i]>>j&1){
                b+=(1ll<<j)*cnt[j];
                c+=(1ll<<j)*N;
            }
            else{
                c+=(1ll<<j)*cnt[j];
            }
        }
        if(B[i]!=b||C[i]!=c){
            puts("-1");
            return 0;
        }
    }
    rep(i,N)printf("%lld ",A[i]);

    return 0;
}