#include<bits/stdc++.h>
#define maxn 200000
#define inf 1e18
using namespace std;
struct node{
    node *nl,*nr;
    long long l,r;
    long long sz;
    long long k,n;
    node(long long l,long long r,long long k,long long n) {
        this->nl=NULL;
        this->nr=NULL;
        this->l=l;
        this->r=r;
        this->k=k;
        this->n=n;
        this->sz=1;
    }
    node(long long l,long long r) {
        this->nl=NULL;
        this->nr=NULL;
        this->l=l;
        this->r=r;
        this->k=0;
        this->n=0;
        this->sz=0;
    }
};
inline long long min_value(node* &rt,long long x) {
    if(rt==NULL || rt->sz==0) return inf;
    if(rt->sz==1) return rt->k*x+rt->n;
    long long m=(rt->l+rt->r)/2;
    if(x<=m) return min(rt->k*x+rt->n,min_value(rt->nl,x));
    else return min(rt->k*x+rt->n,min_value(rt->nr,x));
}
inline void add_function(node* &rt,long long k,long long n) {
    if(rt->sz==0) {
        rt->k=k;
        rt->n=n;
        rt->sz=1;
        return;
    }
    if(rt->l==rt->r) {
        if(k*rt->l+n<rt->k*rt->l+rt->n) {
            rt->k=k;
            rt->n=n;
            rt->sz=1;
        }
        return;
    }
    long long l=rt->l;
    long long r=rt->r;
    if(k*l+n>=rt->k*l+rt->n && k*r+n>=rt->k*r+rt->n) return;
    if(k*l+n<=rt->k*l+rt->n && k*r+n<=rt->k*r+rt->n) {
        swap(rt->k,k);
        swap(rt->n,n);
        return;
    }
    long long m=(l+r)/2;
    long long ch=0;
    long long x=rt->l;
    if(k*x+n<=rt->k*x+rt->n) ch|=2;
    if(k*x+n>=rt->k*x+rt->n) ch|=1;
    x=m;
    if(k*x+n<=rt->k*x+rt->n) ch|=2;
    if(k*x+n>=rt->k*x+rt->n) ch|=1;
    if(ch==3) {
        x=m+1;
        if(k*x+n<rt->k*x+rt->n) {
            swap(rt->k,k);
            swap(rt->n,n);
        }
        if(rt->nl==NULL) rt->nl=new node(l,m);
        add_function(rt->nl,k,n);
    }
    else {
        if(ch==2) {
            swap(rt->k,k);
            swap(rt->n,n);
        }
        if(rt->nr==NULL) rt->nr=new node(m+1,r);
        add_function(rt->nr,k,n);
    }
    rt->sz=1;
    if(rt->nl!=NULL) rt->sz+=rt->nl->sz;
    if(rt->nr!=NULL) rt->sz+=rt->nr->sz;
}
inline void traverse_erase(node* &rt,node* &aim) {
    if(rt==NULL || rt->sz==0) return;
    traverse_erase(rt->nl,aim);
    traverse_erase(rt->nr,aim);
    add_function(aim,rt->k,rt->n);
    free(rt);
}
long long n;
long long a[maxn+5];
long long b[maxn+5];
node* li_chao[maxn+5];
long long ptr[maxn];
long long dp[maxn];
vector<long long> s[maxn+5];
inline void dfs(long long u,long long p) {
    long long cnt=0;
    for(auto v:s[u]) {
        if(v!=p) {
            cnt++;
            dfs(v,u);
        }
    }
    if(cnt==0) {
        li_chao[u]=new node(-maxn,maxn);
        add_function(li_chao[u],b[u],0);
        return;
    }
    long long bv=-1;
    for(auto v:s[u]) {
        if(v!=p) {
            assert(li_chao[v]!=NULL);
            if(bv==-1 || li_chao[v]->sz>li_chao[bv]->sz) bv=v;
        }
    }
    li_chao[u]=li_chao[bv];
    for(auto v:s[u]) {
        if(v!=p && v!=bv) {
            traverse_erase(li_chao[v],li_chao[u]);
        }
    }
    dp[u]=min_value(li_chao[u],a[u]);
    add_function(li_chao[u],b[u],dp[u]);
}
int main() {
    scanf("%lld",&n);
    for(long long i=1;i<=n;i++) scanf("%lld",&a[i]);
    for(long long i=1;i<=n;i++) scanf("%lld",&b[i]);
    long long u,v;
    for(long long i=0;i<n-1;i++) {
        scanf("%lld %lld",&u,&v);
        s[u].push_back(v);
        s[v].push_back(u);
    }
    for(long long i=1;i<=n;i++) ptr[i]=i;
    dfs(1,-1);
    for(long long i=1;i<=n;i++) printf("%lld ",dp[i]);
    return 0;
}