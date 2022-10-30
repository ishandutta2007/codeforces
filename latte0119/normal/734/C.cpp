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

signed main(){
    int N,M,K;
    scanf("%lld%lld%lld",&N,&M,&K);
    int X,S;scanf("%lld%lld",&X,&S);

    vector<pint>a(M),b(K);
    rep(i,M)scanf("%lld",&a[i].se);
    rep(i,M)scanf("%lld",&a[i].fi);
    rep(i,K)scanf("%lld",&b[i].se);
    rep(i,K)scanf("%lld",&b[i].fi);

    a.pb({0,X});b.pb({0,0});
    sort(all(a));sort(all(b));

    int ans=LLONG_MAX;
    int cur=0,ma=0;
    for(int i=a.size()-1;i>=0;i--){
        if(a[i].fi>S)continue;
        while(cur<b.size()&&b[cur].fi+a[i].fi<=S)chmax(ma,b[cur++].se);
        chmin(ans,max(0ll,N-ma)*a[i].se);
    }
    cout<<ans<<endl;
    return 0;
}