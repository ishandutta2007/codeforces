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

int N;
int A[111111];

vint G[111111];

vint latte,beet;
int dfs(int v){
    if(G[v].size()==0){
        latte.pb(A[v]);
        return 1;
    }

    bool flag=false;
    for(auto u:G[v]){
        if(!dfs(u))flag=true;
    }
    if(flag)latte.pb(A[v]);
    else beet.pb(A[v]);
    return flag;
}

signed main(){
    scanf("%lld",&N);
    rep(i,N)scanf("%lld",&A[i]);
    for(int i=1;i<N;i++){
        int p;scanf("%lld",&p);
        p--;
        G[p].pb(i);
    }
    dfs(0);
    int X=0;
    rep(i,latte.size())X^=latte[i];

    int ans=0;
    if(X==0){
        ans+=(int)latte.size()*((int)latte.size()-1)/2;
        ans+=(int)beet.size()*((int)beet.size()-1)/2;
    }

    map<int,int>cnt;
    for(auto w:beet)cnt[w]++;

    for(auto w:latte){
        ans+=cnt[X^w];
    }

    cout<<ans<<endl;
    return 0;
}