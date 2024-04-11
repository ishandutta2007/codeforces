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

int N,K;
int T[222222];
int w[222222];

int solve(vint lis,int k){
    sort(all(lis));
    reverse(all(lis));
    rep(i,lis.size())k-=lis[i];
    int ret=0;
    rep(i,lis.size()){
        if(k>=0)break;
        ret+=2;
        k+=lis[i]-1;
    }
    if(k<0)return 1001001001001001001ll;
    return ret;
}

signed main(){
    scanf("%lld%lld",&N,&K);
    rep(i,N)scanf("%lld",&T[i]),w[i]=1;

    for(int i=N-1;i>=0;i--){
        if(T[i]<0)continue;
        if(i)w[i-1]+=w[i];
        w[i]=0;
    }

    vint lis;
    rep(i,N)if(T[i]<0)lis.pb(w[i]);

    if(lis.size()==0){
        cout<<0<<endl;
        return 0;
    }
    if(lis.size()>K){
        cout<<-1<<endl;
        return 0;
    }


    int ans=1001001001001001001ll;
    rep(i,2){
        int t=lis.back();
        lis.pop_back();
        chmin(ans,solve(lis,K-1-(t-1)*(1-i))+i);
        lis.pb(t);
    }
    cout<<ans+1<<endl;
    return 0;
}