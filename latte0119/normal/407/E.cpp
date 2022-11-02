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

int INF=1001001001001001001ll;
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
            put[k]+=x;
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

    int latte(int a,int b,int K,int k=0,int l=0,int r=SEG){
        push(k);
        if(r<=a||b<=l)return -1;
        if(a<=l&&r<=b){
            if(dat[k]>K)return -1;
            if(l+1==r)return l;
        }
        int tmp=latte(a,b,K,k*2+1,l,(l+r)/2);
        if(tmp!=-1)return tmp;
        return latte(a,b,K,k*2+2,(l+r)/2,r);
    }
};


int N,K,D;
int A[222222];

pint smax(pint p,pint q){
    if(p.se-p.fi>q.se-q.fi)return p;
    if(p.se-p.fi<q.se-q.fi)return q;
    return min(p,q);
}

int pre[222222];

signed main(){
    scanf("%lld%lld%lld",&N,&K,&D);
    rep(i,N)scanf("%lld",&A[i]);

    if(D==0){
        int L=0;
        pint ans;
        rep(i,N){
            if(i&&A[i-1]!=A[i])L=i;
            ans=smax(ans,pint(L,i+1));
        }
        cout<<ans.fi+1<<" "<<ans.se<<endl;
        return 0;
    }

    int hoge=(1000000000+D-1)/D;
    rep(i,N)A[i]+=hoge*D;
    map<int,int>mp;
    rep(i,N){
        int r=A[i]/D;
        if(mp.find(r)!=mp.end())pre[i]=mp[r];
        else pre[i]=-1;
        mp[r]=i;
    }


    segtree seg;
    rep(i,N)seg.add(i,i+1,1+i);

    vpint Mv,mv;
    Mv.pb({INF,-1});
    mv.pb({-INF,-1});

    int L=0;
    pint ans;
    for(int i=0;i<N;i++){
        seg.add(0,N,-1);
        int M=A[i]/D;
        while(Mv.back().fi<=M){
            pint p=Mv.back();
            Mv.pop_back();
            seg.add(Mv.back().se+1,p.se+1,-p.fi);
        }

        while(mv.back().fi>=M){
            pint p=mv.back();
            mv.pop_back();
            seg.add(mv.back().se+1,p.se+1,p.fi);
        }

        seg.add(Mv.back().se+1,i+1,M);
        seg.add(mv.back().se+1,i+1,-M);
        Mv.pb({M,i});
        mv.pb({M,i});

        if(i&&A[i-1]%D!=A[i]%D)L=i;
        chmax(L,pre[i]+1);
        /*
        int lb=L,ub=i+1;
        while(ub-lb>1){
            int mid=(ub+lb)/2;
            if(seg.query(L,mid)>K)lb=mid;
            else ub=mid;
        }*/
        ans=smax(ans,pint(seg.latte(L,i+1,K),i+1));
    }

    cout<<ans.fi+1<<" "<<ans.se<<endl;
    return 0;
}