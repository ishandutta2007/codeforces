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

const int INF=LLONG_MAX/10;
struct segtree{
    static const int SEG=1<<21;
    vint dat,put;
    segtree(vint &v):dat(SEG*2),put(SEG*2){
        for(int i=0;i<v.size();i++)dat[i+SEG-1]=v[i];
        for(int i=SEG-2;i>=0;i--)dat[i]=max(dat[i*2+1],dat[i*2+2]);
    }
    void add(int a,int b,int x,int k=0,int l=0,int r=SEG){
        if(r<=a||b<=l)return;
        if(a<=l&&r<=b){
            put[k]+=x;
            dat[k]+=x;
            return;
        }
        add(a,b,x,k*2+1,l,(l+r)/2);
        add(a,b,x,k*2+2,(l+r)/2,r);
        dat[k]=max(dat[k*2+1],dat[k*2+2])+put[k];
    }
    int get(int a=0,int b=SEG,int k=0,int l=0,int r=SEG){
        if(r<=a||b<=l)return -INF;
        if(a<=l&&r<=b)return dat[k];
        return max(get(a,b,k*2+1,l,(l+r)/2),get(a,b,k*2+2,(l+r)/2,r))+put[k];
    }
};

int N,M,K;
vint v;
vpint s;
signed main(){
    scanf("%lld%lld%lld",&N,&M,&K);
    v.resize(N);s.resize(M);
    rep(i,N)scanf("%lld",&v[i]);
    rep(i,M)scanf("%lld",&s[i].fi),s[i].se=i;
    sort(all(v));sort(all(s));


    vint latte(segtree::SEG);
    rep(i,N)if(v[i]<latte.size())latte[v[i]]++;
    rep(i,latte.size())latte[i]-=K;
    for(int i=1;i<latte.size();i++)latte[i]+=latte[i-1];

    segtree seg(latte);
    if(seg.get()>0){
        puts("-1");
        return 0;
    }
    vint ans;
    for(int i=M-1;i>=0;i--){
        if(s[i].fi>=segtree::SEG){
            ans.pb(s[i].se);
            continue;
        }
        seg.add(s[i].fi,segtree::SEG,1);
        if(seg.get()>0)break;
        ans.pb(s[i].se);
    }

    printf("%lld\n",(int)ans.size());
    rep(i,ans.size())printf("%lld ",ans[i]+1);
    puts("");
    return 0;
}