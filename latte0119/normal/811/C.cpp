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

const int INF=1001001001001001001ll;
int N;
int A[5555];

int dp[5555];
int fir[5555];
int las[5555];
signed main(){
    cin>>N;
    rep(i,N)cin>>A[i];

    fill_n(fir,5555,INF);
    rep(i,N)chmin(fir[A[i]],i);
    rep(i,N)chmax(las[A[i]],i);

    fill_n(dp,5555,-INF);
    dp[0]=0;

    for(int i=0;i<N;i++){
        int r=-1;
        chmax(dp[i+1],dp[i]);
        int latte=0;
        for(int j=i;j<N;j++){
            if(fir[A[j]]<i)break;
            if(fir[A[j]]==j)latte^=A[j];
            chmax(r,las[A[j]]);
            if(r<=j)chmax(dp[j+1],dp[i]+latte);
        }
    }

    cout<<dp[N]<<endl;
    return 0;
}