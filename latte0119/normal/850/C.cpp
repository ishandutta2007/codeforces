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

int dp[1<<20];

int G(int s){
    if(s<(1<<20))return dp[s];
    int ma=0;
    rep(i,33)if(s>>i&1)ma=i;
    bool ex[33]={};
    for(int i=1;i<=ma+1;i++){
        int k=s>>i;
        int l=s&((1ll<<(i-1))-1);
        int g=G(k|l);
        ex[g]=true;
    }
    int ret=0;
    while(ex[ret])ret++;
    return ret;
}

signed main(){
    dp[0]=0;
    for(int s=1;s<(1<<20);s++){
        int ma=0;
        rep(i,33)if(s>>i&1)ma=i;
        bool ex[33]={};
        for(int i=1;i<=ma+1;i++){
            int k=s>>i;
            int l=s&((1ll<<(i-1))-1);
            int g=dp[k|l];
            ex[g]=true;
        }

        int ret=0;
        while(ex[ret])ret++;
        dp[s]=ret;
    }

    int N;
    cin>>N;
    vint A(N);
    rep(i,N)cin>>A[i];

    vint p;
    rep(i,N){
        int a=A[i];
        for(int j=2;j*j<=a;j++){
            if(a%j)continue;
            p.pb(j);
            while(a%j==0)a/=j;
        }
        if(a!=1)p.pb(a);
    }
    sort(all(p));p.erase(unique(all(p)),p.end());
    int X=0;
    rep(i,p.size()){
        int s=0;
        rep(j,A.size()){
            int cnt=0;
            while(A[j]%p[i]==0)A[j]/=p[i],cnt++;
            if(cnt)s|=(1ll<<(cnt-1));
        }
        X^=G(s);
    }
    if(X)cout<<"Mojtaba"<<endl;
    else cout<<"Arpa"<<endl;
    return 0;
}