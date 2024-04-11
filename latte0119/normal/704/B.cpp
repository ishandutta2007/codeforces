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
#define mp make_pair
#define fi first
#define se second
template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

const int INF=1001001001001001001ll;

int N,S,E;
int X[5000],A[5000],B[5000],C[5000],D[5000];

int dp[5010][5010];

signed main(){
    scanf("%lld%lld%lld",&N,&S,&E);
    rep(i,N)scanf("%lld",&X[i]);
    rep(i,N)scanf("%lld",&A[i]);
    rep(i,N)scanf("%lld",&B[i]);
    rep(i,N)scanf("%lld",&C[i]);
    rep(i,N)scanf("%lld",&D[i]);

    S--;E--;
    if(S>E){
        rep(i,N){
            swap(A[i],B[i]);
            swap(C[i],D[i]);
        }
        rep(i,N-1)X[i]=X[i+1]-X[i];

        reverse(X,X+N);
        reverse(A,A+N);
        reverse(B,B+N);
        reverse(C,C+N);
        reverse(D,D+N);
        rep(i,N-1)X[i+1]+=X[i];
        S=N-1-S;
        E=N-1-E;
    }

    fill_n(*dp,5010*5010,INF);
    dp[0][0]=0;
    //1->S
    rep(i,S){
        for(int j=0;j<=i;j++){
            chmin(dp[i+1][j+1],dp[i][j]+B[i]+D[i]-2*X[i]);

            if(j>1){
                chmin(dp[i+1][j-1],dp[i][j]+A[i]+C[i]+2*X[i]);

            }
            if(j){
                chmin(dp[i+1][j],dp[i][j]+B[i]+C[i]);
                chmin(dp[i+1][j],dp[i][j]+A[i]+D[i]);
            }
        }
    }

    //S
    if(S==0){
        dp[1][0]=D[0]-X[0];
    }
    else{
        for(int i=1;i<=S;i++){
            chmin(dp[S+1][i-1],dp[S][i]+C[S]+X[S]);
            chmin(dp[S+1][i],dp[S][i]+D[S]-X[S]);
        }
    }

    //S->E
    for(int i=S+1;i<E;i++){
        for(int j=0;j<i;j++){
            chmin(dp[i+1][j+1],dp[i][j]+B[i]+D[i]-2*X[i]);
            if(j){
                chmin(dp[i+1][j-1],dp[i][j]+A[i]+C[i]+2*X[i]);
                chmin(dp[i+1][j],dp[i][j]+B[i]+C[i]);

            }chmin(dp[i+1][j],dp[i][j]+A[i]+D[i]);
        }
    }

    //E
    if(E+1==N){
        cout<<dp[E][0]+X[E]+A[E]<<endl;
        return 0;
    }

    for(int i=1;i<E;i++){
        chmin(dp[E+1][i],dp[E][i]+X[E]+A[E]);
    }
    for(int i=0;i<E;i++){
        chmin(dp[E+1][i+1],dp[E][i]-X[E]+B[E]);
    }

    //E->N-1
    for(int i=E+1;i+1<N;i++){
        for(int j=1;j<i;j++){
            chmin(dp[i+1][j+1],dp[i][j]+B[i]+D[i]-2*X[i]);
            if(j){
                chmin(dp[i+1][j-1],dp[i][j]+A[i]+C[i]+2*X[i]);
                chmin(dp[i+1][j],dp[i][j]+B[i]+C[i]);
                chmin(dp[i+1][j],dp[i][j]+A[i]+D[i]);
            }
        }
    }

    cout<<dp[N-1][1]+2*X[N-1]+A[N-1]+C[N-1]<<endl;
    return 0;
}