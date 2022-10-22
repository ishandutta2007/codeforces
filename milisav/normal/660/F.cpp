#include<bits/stdc++.h>
#define maxn 500000
#define inf 1e18
#define maxs 1e13
using namespace std;
struct node {
    node *l,*r;
    long long k,n;
};
long long maxv(node* &rt,long long l,long long r,long long x) {
    if(rt==NULL) return -inf;
    if(l==r) return x*rt->k+rt->n;
    long long m=(l+r)/2;
    if(x<=m) return max(x*rt->k+rt->n,maxv(rt->l,l,m,x));
    else return max(x*rt->k+rt->n,maxv(rt->r,m+1,r,x));
}
void add_function(node* &rt,long long l,long long r,long long k,long long n) {
    if(l==r) {
        if(k*l+n>=rt->k*l+rt->n) {
            swap(k,rt->k);
            swap(n,rt->n);
        }
        return;
    }
    if(rt->k*l+rt->n>=k*l+n && rt->k*r+rt->n>=k*r+n) return;
    if(rt->k*l+rt->n<=k*l+n && rt->k*r+rt->n<=k*r+n) {
        swap(rt->k,k);
        swap(rt->n,n);
        return;
    }
    long long m=(l+r)/2;
    if(rt->k*l+rt->n<=k*l+n && rt->k*m+rt->n<=k*m+n) {
        swap(rt->k,k);
        swap(rt->n,n);
    }
    if(rt->k*l+rt->n>=k*l+n && rt->k*m+rt->n>=k*m+n) {
        if(rt->r==NULL) {
            rt->r=new node();
            rt->r->k=k;
            rt->r->n=n;
        }
        else add_function(rt->r,m+1,r,k,n);
        return;
    }
    if(rt->k*(m+1)+rt->n<=k*(m+1)+n && rt->k*r+rt->n<=k*r+n) {
        swap(rt->k,k);
        swap(rt->n,n);
    }
    if(rt->k*(m+1)+rt->n>=k*(m+1)+n && rt->k*r+rt->n>=k*r+n) {
        if(rt->l==NULL) {
            rt->l=new node();
            rt->l->k=k;
            rt->l->n=n;
        }
        else add_function(rt->l,l,m,k,n);
        return;
    }
}
long long n;
long long a[maxn];
long long ans=0;
long long tot;
long long cn;
long long sm=0;
node* rt;
int main() {
    scanf("%lld",&n);
    for(long long i=1;i<=n;i++) scanf("%lld",&a[i]);
    rt=new node();
    rt->l=rt->r=NULL;
    rt->k=rt->n=0;
    for(long long i=1;i<=n;i++) {
        tot+=i*a[i];
        cn+=sm;
        sm+=a[i];
        ans=max(ans,tot+maxv(rt,-maxs,maxs,sm));
        add_function(rt,-maxs,maxs,-i,cn);
    }
    printf("%lld",ans);
}