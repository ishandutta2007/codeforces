#include<bits/stdc++.h>
using namespace std;
#define IT set<node>::iterator
const int MOD=1e9+7;
typedef long long ll;
struct node{
    int l,r;mutable ll v;
    node(int L,int R,ll V):l(L),r(R),v(V){}
    bool operator < (const node & a)const{
        return l<a.l;
    }
};
set<node> s;
inline IT split(int pos){
    IT it=s.lower_bound(node(pos,-1,0));
    if(it!=s.end()&&it->l==pos) return it;
    --it;
    int l=it->l,r=it->r;ll v=it->v;
    s.erase(it);s.insert(node(l,pos-1,v));
    return s.insert(node(pos,r,v)).first;
}
inline void add(int l,int r,ll x){
    IT itr=split(r+1),itl=split(l);
    for(; itl!=itr; ++itl) itl->v+=x;
}
inline void assign(int l,int r,ll x){
    IT itr=split(r+1),itl=split(l);
    s.erase(itl,itr);s.insert(node(l,r,x));
}
pair<ll,int> v[100005];
inline ll rnk(int l,int r,int k){
    IT itr=split(r+1),itl=split(l);int cnt=0;
    for(; itl!=itr; ++itl) v[++cnt]=make_pair(itl->v,itl->r-itl->l+1);
    sort(v+1,v+cnt+1);
    for(int i=1;i<=cnt;i++) {
        k-=v[i].second;
        if(k<=0) return v[i].first;
    }
}
inline ll qpow(ll a,ll b,ll mod){
    ll ans=1;a%=mod;
    for(;b;b>>=1,a=a*a%mod) if(b&1) ans=ans*a%mod;
    return ans;
}
inline ll sum(int l,int r,int x,int mod){
    IT itr=split(r+1),itl=split(l);
    ll ans=0;
    for(; itl!=itr; ++itl) ans=(ans+((itl->r-itl->l+1)*qpow(itl->v,x,mod)%mod))%mod;
    return ans;
}
int n,m;
ll seed,vmax;
inline ll rnd(){
    ll ret=seed;
    seed=(seed*7+13)%MOD;
    return ret;
}
int main(){
    cin>>n>>m>>seed>>vmax;
    for(int i=1;i<=n;i++) s.insert(node(i,i,(rnd()%vmax)+1));
    s.insert(node(n+1,n+1,0));
    for(int i=1;i<=m;i++){
        int op=(rnd()%4)+1,l=(rnd()%n)+1,r=(rnd()%n)+1;
        if (l>r) swap(l,r);
        int x,y;
        if(op==3) x=(rnd()%(r-l+1))+1;
        else x=(rnd()%vmax)+1;
        if(op==4) y=(rnd()%vmax)+1;
        if (op==1) add(l,r,x);
        else if (op==2) assign(l,r,x);
        else if (op==3) printf("%lld\n",rnk(l,r,x));
        else printf("%lld\n",sum(l,r,x,y));
    }
    return 0;
}