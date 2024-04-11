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

signed main(){
    int hoge,A,B;
    scanf("%lld%lld%lld",&hoge,&A,&B);
    int N;scanf("%lld",&N);
    int ans=0;
    rep(i,N){
        int x;scanf("%lld",&x);
        ans+=(A<x&&x<B);
    }
    printf("%lld\n",ans);
    return 0;
}