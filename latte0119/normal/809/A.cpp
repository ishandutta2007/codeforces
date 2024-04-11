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

const int mod=1000000007;

int N;
int A[333333];

signed main(){
    scanf("%lld",&N);
    rep(i,N)scanf("%lld",&A[i]);
    sort(A,A+N);

    int ans=0;
    int latte=A[0];
    int beet=2;
    for(int i=1;i<N;i++){
        ans=(ans+A[i]*(beet-1+mod)-latte+mod)%mod;
        beet=beet*2%mod;
        latte=(latte*2+A[i])%mod;
    }

    cout<<ans<<endl;
    return 0;
}