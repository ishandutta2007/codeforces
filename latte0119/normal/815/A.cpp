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

const int INF=1001001001;
const int INFLL=1001001001001001001ll;
const int mod=1000000007;
inline void add(int &a,int b){
    a+=b;
    if(a>=mod)a-=mod;
}

int H,W;
int A[111][111];

signed main(){
    scanf("%lld%lld",&H,&W);
    rep(i,H)rep(j,W)scanf("%lld",&A[i][j]);

    int latte=*min_element(A[0],A[0]+W);

    int ans=INT_MAX,arcans;
    for(int k=0;k<=latte;k++){
        bool ok=true;

        int cnt=0;
        rep(i,H){
            bool f=true;
            rep(j,W){
                if(A[i][0]-(A[0][0]-k)!=A[i][j]-(A[0][j]-k))f=false;
            }
            if(A[i][0]-(A[0][0]-k)<0)f=false;
            if(!f){
                ok=false;
                break;
            }
            cnt+=A[i][0]-(A[0][0]-k);
        }
        rep(i,W)cnt+=A[0][i]-k;

        if(ok&&ans>cnt){
            ans=cnt;
            arcans=k;
        }
    }

    if(ans==INT_MAX)puts("-1");
    else{
        printf("%lld\n",ans);
        rep(i,H){
            rep(j,A[i][0]-(A[0][0]-arcans))printf("row %lld\n",i+1);
        }
        rep(i,W){
            rep(j,A[0][i]-arcans)printf("col %lld\n",i+1);
        }
    }
    return 0;
}