#include<bits/stdc++.h>
using namespace std;

#define int long long

typedef pair<int,int>pint;
typedef vector<int>vint;
typedef vector<pint>vpint;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
template<class T,class U>void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>void chmax(T &t,U f){if(t<f)t=f;}

int N,K;

int fld[500][500];
signed main(){
    cin>>N>>K;
    int cur=N*N;
    K--;
    rep(i,N){
        for(int j=N-1;j>=K;j--)fld[i][j]=cur--;
    }
    rep(i,N){
        for(int j=K-1;j>=0;j--)fld[i][j]=cur--;
    }

    int sum=0;
    rep(i,N)sum+=fld[i][K];
    printf("%lld\n",sum);
    rep(i,N){
        rep(j,N)printf("%lld ",fld[i][j]);
        puts("");
    }
    return 0;
}