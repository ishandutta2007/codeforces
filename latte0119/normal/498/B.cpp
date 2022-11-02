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

using D=double;

int N,T;

D dp[5555];
D nex[5555];
signed main(){
    cin>>N>>T;

    D ans=0.0;

    dp[0]=1;

    rep(i,N){
        int ppp;
        int t;
        cin>>ppp>>t;
        D p=ppp/100.0;

        memset(nex,0,sizeof(nex));
        D x=0;

        D po=1.0;
        rep(j,t-1)po*=1-p;

        for(int j=1;j<=T;j++){
            x=x*(1-p)+dp[j-1];
            if(j>=t)x-=dp[j-t]*po;
            nex[j]+=x*p;

            if(j>=t)nex[j]+=dp[j-t]*po;
        }
        for(int j=0;j<=T;j++){
            dp[j]=nex[j];
            ans+=dp[j];
        }
    }

    cout<<setprecision(20)<<ans<<endl;
    return 0;
}