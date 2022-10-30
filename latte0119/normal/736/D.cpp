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

int N,M;

typedef bitset<2000>bs;

bs A[2000];
bs B[2000];
int X[555555],Y[555555];

signed main(){
    scanf("%lld%lld",&N,&M);
    rep(i,M){
        int a,b;
        scanf("%lld%lld",&a,&b);
        a--;b--;
        A[a][b]=1;
        X[i]=a;Y[i]=b;
    }

    rep(i,N)B[i][i]=1;
    rep(i,N){
        int t=-1;
        for(int j=i;j<N;j++)if(A[j][i])t=j;
        assert(t!=-1);
        if(t!=i){
            swap(A[i],A[t]);
            swap(B[i],B[t]);
        }

        for(int j=0;j<N;j++){
            if(i==j)continue;
            if(A[j][i]==0)continue;
            A[j]^=A[i];
            B[j]^=B[i];
        }
    }

    rep(i,M){
        if(B[Y[i]][X[i]])puts("NO");
        else puts("YES");
    }
    return 0;
}