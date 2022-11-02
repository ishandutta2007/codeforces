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

const int mod=998244353;
int mpow(int n,int m){
    int ret=1;
    while(m){
        if(m&1)ret=ret*n%mod;
        n=n*n%mod;
        m>>=1;
    }
    return ret;
}
int fact[111111];
int inv[111111];

int N;

int dp[2][2222][11];

inline void add(int &a,int b){
    a+=b;
    if(a>=mod)a-=mod;
}

vector<vint>calc(vint e){
    memset(dp,0,sizeof(dp));
    dp[0][0][0]=1;
    for(int i=0;i<e.size();i++){
        for(int j=0;j<=i;j++){
            for(int k=0;k<11;k++){
                add(dp[(i+1)&1][j+1][(k+e[i])%11],dp[i&1][j][k]);
                add(dp[(i+1)&1][j][(k-e[i]+11)%11],dp[i&1][j][k]);
                dp[i&1][j][k]=0;
            }
        }
    }

    vector<vint>E(e.size()+1,vint(11));
    rep(i,e.size()+1)rep(j,11)E[i][j]=dp[e.size()&1][i][j];
    return E;
}


void solve(){
    cin>>N;
    vint e,o;
    rep(i,N){
        string s;
        cin>>s;
        reverse(all(s));
        int v=0;
        for(int j=0;j<s.size();j++){
            if(j&1)v+=s[j]-'0';
            else v-=s[j]-'0';
        }
        v=(v+11*114514)%11;
        if(s.size()&1)o.pb(v);
        else e.pb(v);
    }

    if(o.size()==0){
        int sum=accumulate(all(e),0ll)%11;
        if(sum==0)cout<<fact[N]<<endl;
        else cout<<0<<endl;
        return;
    }

    auto E=calc(e);
    auto O=calc(o);

    int ans=0;

    for(int k=0;k<11;k++){
        int tmp=O[(o.size()+1)/2][k]*fact[(o.size()+1)/2]%mod*fact[o.size()/2]%mod;

        for(int a=0;a<=e.size();a++){
            int tmp2=E[a][(11-k)%11];

            int p=o.size()/2+1;
            tmp2=tmp2*fact[p+a-1]%mod*inv[p-1]%mod;

            int b=e.size()-a;
            p=(o.size()+1)/2;
            tmp2=tmp2*fact[p+b-1]%mod*inv[p-1]%mod;
            add(ans,tmp*tmp2%mod);
        }
    }
    cout<<ans<<endl;

}

signed main(){
    fact[0]=1;
    for(int i=1;i<111111;i++)fact[i]=fact[i-1]*i%mod;
    inv[111111-1]=mpow(fact[111111-1],mod-2);
    for(int i=111111-2;i>=0;i--)inv[i]=inv[i+1]*(i+1)%mod;

    int T;cin>>T;while(T--)solve();
    return 0;
}