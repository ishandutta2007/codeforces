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
int A[111111];


signed main(){
    scanf("%lld",&N);
    rep(i,N)scanf("%lld",&A[i]);

    int mi=0,ma=0;
    int sum=0;
    int ans=0;
    for(int i=N-2;i>=0;i--){
        int tmp=abs(A[i+1]-A[i]);
        if(i&1)tmp*=-1;
        sum+=tmp;

        if(i&1){
            chmax(ans,-sum+ma);
        }
        else{
            chmax(ans,sum-mi);
        }

        chmax(ma,sum);
        chmin(mi,sum);
    }

    printf("%lld\n",ans);
    return 0;
}