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

struct segtree{
    static const int SEG=1<<18;
    int *dat;
    void init(int *a,bool rev){
        dat=new int[SEG*2];
        rep(i,SEG){
            dat[i+SEG-1]=a[i];
            if(rev)dat[i+SEG-1]*=-1;
        }
        for(int i=SEG-2;i>=0;i--)dat[i]=min(dat[i*2+1],dat[i*2+2]);
    }
    int get(int a,int b,int k=0,int l=0,int r=SEG){
        if(r<=a||b<=l)return LLONG_MAX;
        if(a<=l&&r<=b)return dat[k];
        return min(get(a,b,k*2+1,l,(l+r)/2),get(a,b,k*2+2,(l+r)/2,r));
    }
};

int N,M;
int a[1000000];
vint idx[1000000];
signed main(){
    scanf("%lld%lld",&N,&M);
    rep(i,N){
        scanf("%lld",&a[i]);
        a[i]--;
        idx[a[i]].pb(i);

    }
    segtree mi,ma;
    mi.init(a,0);ma.init(a,1);
    while(M--){
        int l,r,x;
        scanf("%lld%lld%lld",&l,&r,&x);l--;x--;
        int p=mi.get(l,r),q=-ma.get(l,r);
        if(p==q&&p==x)puts("-1");
        else{
            if(p==x)swap(p,q);
            int i=*lower_bound(all(idx[p]),l);
            printf("%lld\n",i+1);
        }
    }
    return 0;
}