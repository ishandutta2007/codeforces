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

int N;
int P[2222];

signed main(){
    cin>>N;
    rep(i,N)cin>>P[i];

    int I=0;
    rep(i,N)for(int j=i+1;j<N;j++)if(P[i]>P[j])I++;

    int Q;scanf("%lld",&Q);

    bool f=I%2;
    while(Q--){
        int l,r;
        scanf("%lld%lld",&l,&r);
        int len=r-l+1;
        int tmp=len*(len-1)/2;
        if(tmp&1)f^=1;
        if(f)puts("odd");
        else puts("even");
    }
    return 0;
}