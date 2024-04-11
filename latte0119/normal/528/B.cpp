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

struct BIT{
    int N;
    vint dat;
    void init(int n){
        N=n;
        dat.resize(n+1);
    }
    void update(int k,int x){
        for(k++;k<=N;k+=k&-k)chmax(dat[k],x);
    }
    int getmax(int k){
        int ret=0;
        for(k++;k;k-=k&-k)chmax(ret,dat[k]);
        return ret;
    }
};

int N;
vpint ps;
signed main(){
    scanf("%lld",&N);
    rep(i,N){
        int x,w;
        scanf("%lld%lld",&x,&w);
        ps.pb({x,w});
    }
    sort(all(ps));
    vint latte;
    rep(i,N)latte.pb(ps[i].fi+ps[i].se);
    sort(all(latte));latte.erase(unique(all(latte)),latte.end());

    BIT bit;bit.init(N);
    rep(i,N){
        int x=ps[i].fi,w=ps[i].se;
        int idx=upper_bound(all(latte),x-w)-latte.begin()-1;
        int idx2=lower_bound(all(latte),x+w)-latte.begin();
        int tmp=bit.getmax(idx);
        bit.update(idx2,tmp+1);
    }
    cout<<bit.getmax(N-1)<<endl;
    return 0;
}