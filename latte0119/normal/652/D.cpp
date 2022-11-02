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
template<class T,class U>inline void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>inline void chmax(T &t,U f){if(t<f)t=f;}

struct BIT{
    int N;
    vint dat;
    void init(int n){
        N=n;
        dat.resize(N+1);
    }
    void add(int k,int x){
        for(k++;k<=N;k+=k&-k)dat[k]+=x;
    }
    int sum(int k){
        int ret=0;
        for(k++;k;k-=k&-k)ret+=dat[k];
        return ret;
    }
};

int N;
int l[222222],r[222222];
struct BIT;

int ans[444444];

signed main(){

    vint press;
    scanf("%lld",&N);
    rep(i,N)scanf("%lld%lld",&l[i],&r[i]);
    rep(i,N){
        press.pb(l[i]);
        press.pb(r[i]);
    }
    sort(all(press));
    rep(i,N){
        l[i]=lower_bound(all(press),l[i])-press.begin();
        r[i]=lower_bound(all(press),r[i])-press.begin();
    }

    vpint st;
    rep(i,N)st.pb(pint(l[i],r[i]));
    sort(all(st));

    BIT bit;bit.init(444444);
    for(int i=N-1;i>=0;i--){
        int ll=st[i].fi,rr=st[i].se;
        ans[ll]=bit.sum(rr);
        bit.add(rr,1);
    }

    rep(i,N)printf("%lld\n",ans[l[i]]);
    return 0;
}