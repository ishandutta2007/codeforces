
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

int N,M;
int A[1111][1111];

int x[1111][1111],y[1111][1111];

signed main(){
    scanf("%lld%lld",&N,&M);
    rep(i,N)rep(j,M)scanf("%lld",&A[i][j]);


    rep(i,N){
        vint vs;
        rep(j,M)vs.pb(A[i][j]);
        sort(all(vs));vs.erase(unique(all(vs)),vs.end());
        rep(j,M){
            int k=lower_bound(all(vs),A[i][j])-vs.begin();
            x[i][j]=k;
            y[i][j]=vs.size()-k-1;
        }
    }

    rep(j,M){
        vint vs;
        rep(i,N)vs.pb(A[i][j]);
        sort(all(vs));vs.erase(unique(all(vs)),vs.end());
        rep(i,N){
            int k=lower_bound(all(vs),A[i][j])-vs.begin();
            chmax(x[i][j],k);
            chmax(y[i][j],vs.size()-k-1);
        }
    }

    rep(i,N){
        rep(j,M){
            if(j)printf(" ");
            printf("%lld",x[i][j]+y[i][j]+1);
        }puts("");
    }

    return 0;
}