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

int N,M,K;
int A[222222];

signed main(){
    scanf("%lld%lld%lld",&N,&M,&K);
    rep(i,N)scanf("%lld",&A[i]);

    sort(A,A+N);reverse(A,A+N);

    cout<<M/(K+1)*(A[0]*K+A[1])+M%(K+1)*A[0]<<endl;
}