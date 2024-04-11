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

const int mod=1000000007;
int dp[1111111];

int f(int n){
    if(n==1)return 1;
    vint v;
    for(int i=1;i*i<=n;i++){
        if(n%i)continue;
        v.pb(i);
        if(i*i!=n)v.pb(n/i);
    }
    sort(all(v));
    reverse(all(v));
    for(int i=0;i<v.size();i++){
        dp[i]=n/v[i]+1;
        for(int j=0;j<i;j++){
            if(v[j]%v[i])continue;
            dp[i]-=dp[j];
        }
    }
    return dp[v.size()-1];
}

/*
int g(int n){
    if(n==1)return 1;
    vint v;
    for(int i=1;i*i<=n;i++){
        if(n%i)continue;
        v.pb(i);
        if(i*i!=n)v.pb(n/i);
    }
    sort(all(v));
    reverse(all(v));
    memset(dp,0,sizeof(dp));
    for(int i=0;i<v.size();i++){
        for(int j=0;j<i;j++){
            if(v[j]%v[i])continue;
            dp[i]=(dp[i]-dp[j]+mod)%mod;
        }
        dp[i]=(dp[i]+n/v[i]+1)%mod;
    }
    return (accumulate(dp+1,dp+v.size(),0ll)+1)%mod;
}
*/

signed main(){
    int N,K;
    cin>>N>>K;
    int v=N;
    for(int i=1;i<=K;i++){
        if(i&1){
            v=f(v);
        }
        if(v==1)break;
    }
    cout<<v%mod<<endl;
    return 0;
}