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

int N,P;
int A[111111],B[111111];

bool C(double x){
    double sum=0.0;
    rep(i,N){
        double tmp=B[i]-A[i]*x;
        if(tmp>=0.0)continue;
        sum+=-tmp/P;
    }
    return sum<=x;
}

signed main(){
    scanf("%lld%lld",&N,&P);
    rep(i,N)scanf("%lld%lld",&A[i],&B[i]);

    int sum=accumulate(A,A+N,0ll);
    if(sum<=P){
        puts("-1");
        return 0;
    }

    double lb=0.0,ub=1e11;
    rep(i,100){
        double mid=(ub+lb)/2;
        if(C(mid))lb=mid;
        else ub=mid;
    }

    printf("%.20f\n",lb);
    return 0;
}