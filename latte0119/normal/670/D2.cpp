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
int A[100000],B[100000];

signed main(){
    scanf("%lld%lld",&N,&K);
    rep(i,N)scanf("%lld",&A[i]);
    rep(i,N)scanf("%lld",&B[i]);

    int lb=0,ub=2000000010ll;
    while(ub-lb>1){
        int mid=(ub+lb)/2;
        int cnt=0;
        rep(i,N){
            cnt+=max(0ll,A[i]*mid-B[i]);
            if(cnt>K)break;
        }
        if(cnt<=K)lb=mid;
        else ub=mid;
    }

    printf("%lld\n",lb);
    return 0;
}