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

int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}
int lcm(int a,int b){
    return a/gcd(a,b)*b;
}

int N,M,P;
int A[11111];

int mpow(int n,int m,int mod){
    int ret=1;
    while(m){
        if(m&1)ret=ret*n%mod;
        n=n*n%mod;
        m>>=1;
    }
    return ret;
}

int dp[2][5555][2];

const int mod=1000000007;
inline void add(int &a,int b){
    a+=b;
    if(a>=mod)a-=mod;
}

signed main(){
    cin>>N>>M>>P;
    rep(i,N)cin>>A[i];

    int b=0;
    rep(i,M){
        int x;cin>>x;b=gcd(x,b);
    }
    b=gcd(b,P-1);
    vint lis;
    for(int i=1;i*i<=P-1;i++){
        if((P-1)%i)continue;
        lis.pb(i);
        if((P-1)/i!=i)lis.pb((P-1)/i);
    }
    sort(all(lis));

    vint p;
    for(int i=0;i<N;i++){
        int a=mpow(A[i],b,P);
        for(int j=0;j<lis.size();j++){
            if(mpow(a,lis[j],P)!=1)continue;
            p.pb((P-1)/lis[j]);
            break;
        }
    }


    vector<vint>mat(lis.size(),vint(lis.size()));
    rep(i,lis.size())rep(j,lis.size()){
        mat[i][j]=lower_bound(all(lis),lcm(lis[i],lis[j]))-lis.begin();
    }


    dp[0][0][0]=1;
    rep(i,N){
        int w=lower_bound(all(lis),p[i])-lis.begin();
        rep(j,lis.size()){
            rep(k,2){
                add(dp[(i+1)&1][j][k],dp[i&1][j][k]);
                add(dp[(i+1)&1][mat[j][w]][k^1],dp[i&1][j][k]);
                dp[i&1][j][k]=0;
            }
        }
    }




    dp[N&1][0][0]=(dp[N&1][0][0]-1+mod)%mod;



    int ans=0;
    for(int i=0;i<lis.size();i++){
        add(ans,dp[N&1][i][1]*((P-1)/lis[i])%mod);
        add(ans,(mod-dp[N&1][i][0]*((P-1)/lis[i])%mod)%mod);
    }

    cout<<ans<<endl;
    return 0;
}