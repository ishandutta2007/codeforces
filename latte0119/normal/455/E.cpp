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
inline bool check(pint &a,pint &b,pint &c){
    return (b.fi-a.fi)*(c.se-b.se)>=(b.se-a.se)*(c.fi-b.fi);
}

inline int f(pint &p,int x){
    return p.fi*x+p.se;
}

struct CHT{
    deque<pint>d;
    void add(int a,int b){
        pint p(a,b);
        while(d.size()>=2&&check(d[d.size()-2],d[d.size()-1],p))d.pop_back();
        d.pb(p);
    }

    int query(int x){
        if(d.size()==0)return INF;
        while(d.size()>=2&&f(d[0],x)>=f(d[1],x))d.pop_front();
        return f(d[0],x);
    }
};

struct segtree{
    static const int SEG=1<<17;
    vector<CHT>dat;
    segtree():dat(SEG*2){}

    void update(int k,int a,int b){
        k+=SEG-1;
        dat[k].add(a,b);
        while(k){
            k=(k-1)/2;
            dat[k].add(a,b);
        }
    }

    int query(int a,int b,int x,int k=0,int l=0,int r=SEG){
        if(r<=a||b<=l)return INF;
        if(a<=l&&r<=b)return dat[k].query(x);
        return min(query(a,b,x,k*2+1,l,(l+r)/2),query(a,b,x,k*2+2,(l+r)/2,r));
    }
};

int N,Q;
int A[111111];
int S[111111];

signed main(){
    scanf("%lld",&N);
    rep(i,N)scanf("%lld",&A[i]);
    rep(i,N)S[i]=A[i];
    rep(i,N)S[i+1]+=S[i];

    vector<tuple<int,int,int>>vec;
    rep(i,N)vec.pb(make_tuple(A[i],i*A[i]-S[i],i));

    sort(all(vec));reverse(all(vec));


    segtree seg;
    rep(i,N){
        int a,b,j;
        tie(a,b,j)=vec[i];
        seg.update(j,a,b);
    }

    scanf("%lld",&Q);

    vector<tuple<int,int,int>>qs;
    rep(i,Q){
        int l,r;
        scanf("%lld%lld",&l,&r);
        r--;
        qs.pb(make_tuple(l-r,r,i));
    }
    sort(all(qs));
    vint ans(Q);

    rep(i,Q){
        int l,r,j;
        tie(l,r,j)=qs[i];
        l+=r;
        ans[j]=seg.query(r-l+1,r+1,l-r)+S[r];
    }
    rep(i,Q)printf("%lld\n",ans[i]);
    return 0;
}