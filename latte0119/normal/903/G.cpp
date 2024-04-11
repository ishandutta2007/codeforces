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

const int INF=1001001001001001001ll;
struct segtree{
    static const int SEG=1<<18;
    vint dat,put;
    segtree():dat(SEG*2),put(SEG*2){}
    inline void push(int k){
        dat[k]+=put[k];
        if(k<SEG-1){
            put[k*2+1]+=put[k];
            put[k*2+2]+=put[k];
        }
        put[k]=0;
    }
    void add(int a,int b,int x,int k=0,int l=0,int r=SEG){
        push(k);
        if(r<=a||b<=l)return;
        if(a<=l&&r<=b){
            put[k]=x;
            push(k);
            return;
        }
        add(a,b,x,k*2+1,l,(l+r)/2);
        add(a,b,x,k*2+2,(l+r)/2,r);
        dat[k]=min(dat[k*2+1],dat[k*2+2]);
    }
    int query(int a,int b,int k=0,int l=0,int r=SEG){
        push(k);
        if(r<=a||b<=l)return INF;
        if(a<=l&&r<=b)return dat[k];
        return min(query(a,b,k*2+1,l,(l+r)/2),query(a,b,k*2+2,(l+r)/2,r));
    }
};

int N,M,Q;

signed main(){
    scanf("%lld%lld%lld",&N,&M,&Q);
    vint A,B;
    B.pb(0);
    rep(i,N-1){
        int a,b;
        scanf("%lld%lld",&a,&b);
        A.pb(a);B.pb(b);
    }
    A.pb(0);

    vector<vpint>G(N);
    rep(i,M){
        int a,b,c;
        scanf("%lld%lld%lld",&a,&b,&c);
        a--;
        G[a].pb({b,c});
    }

    segtree seg;
    rep(i,N)seg.add(i,i+1,B[i]);

    vint latte(N);
    rep(i,N){
        for(auto &e:G[i]){
            seg.add(0,e.fi,e.se);
        }
        latte[i]=seg.query(0,N);
    }

    segtree seg2;
    rep(i,N)seg2.add(i,i+1,A[i]+latte[i]);

    printf("%lld\n",seg2.query(0,N));
    while(Q--){
        int k,x;
        scanf("%lld%lld",&k,&x);
        k--;
        seg2.add(k,k+1,-A[k]+x);
        A[k]=x;
        printf("%lld\n",seg2.query(0,N));
    }
    return 0;
}