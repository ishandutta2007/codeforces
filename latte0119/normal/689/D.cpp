#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int>pint;
typedef vector<int>vint;
typedef vector<pint>vpint;
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
template<class T,class U>inline void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>inline void chmax(T &t,U f){if(t<f)t=f;}

struct segtree{
    static const int INF=1001001001;
    static const int SEG=1<<18;
    vint dat;
    segtree():dat(SEG*2,INF){}

    void update(int k,int x){
        k+=SEG-1;
        dat[k]=x;
        while(k){
            k=(k-1)/2;
            dat[k]=min(dat[k*2+1],dat[k*2+2]);
        }
    }
    int query(int a,int b,int k=0,int l=0,int r=SEG){
        if(r<=a||b<=l)return INF;
        if(a<=l&&r<=b)return dat[k];
        return min(query(a,b,k*2+1,l,(l+r)/2),query(a,b,k*2+2,(l+r)/2,r));
    }
};

signed main(){
    int N;
    scanf("%lld",&N);
    vint A(N),B(N);
    rep(i,N)scanf("%lld",&A[i]);
    rep(i,N)scanf("%lld",&B[i]);

    segtree segA,segB;
    rep(i,N){
        segA.update(i,-A[i]);
        segB.update(i,B[i]);
    }

    int ans=0;
    int l=0,r=0;
    rep(i,N){
        chmax(l,i);
        while(l<N&&-segA.query(i,l+1)<segB.query(i,l+1))l++;
        chmax(r,l);
        while(r<N&&-segA.query(i,r+1)==segB.query(i,r+1))r++;
        ans+=r-l;
    }
    printf("%lld\n",ans);
    return 0;
}