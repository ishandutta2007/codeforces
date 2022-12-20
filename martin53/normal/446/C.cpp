#include<bits/stdc++.h>
#define int long long
using namespace std;
const int nmax=3e5+42,mod=1e9+9;
int n,m;
int arr[nmax];
int pref[nmax];
int fib[nmax];
int pref_fib[nmax];

struct info
{
    int sum;
    int a,b;
};
info tree[nmax*4];
int normal(int x)
{
    if(x<0)x=x+mod;
    x=x%mod;
    return x;
}
int sum(int l,int r)
{
    return normal(pref_fib[r]-pref_fib[l-1]);
}
int ask_fib_sum(int a,int b,int sz)
{
    int ret=a*(fib[sz])+b*(fib[sz+1]-1);
    //cout<<"fib sum "<<a<<" "<<b<<" "<<sz<<" -> "<<ret<<endl;
    return ret%mod;
}
int ask_fib(int a,int b,int i)
{
    int ret=a*fib[i-2]+b*fib[i-1];
    ret=ret%mod;
    return ret;
}
int recalc(int node,int l,int r)
{
    int ret=0;
    if(l!=r)ret=ret+tree[node*2].sum+tree[node*2+1].sum;
    ret=ret+ask_fib_sum(tree[node].a,tree[node].b,r-l+1);
    return ret%mod;
}
void push(int node,int l,int r)
{
    tree[node*2].a=(tree[node].a+tree[node*2].a)%mod;
    tree[node*2].b=(tree[node].b+tree[node*2].b)%mod;

    int av=(l+r)/2;
    tree[node*2+1].a=(ask_fib(tree[node].a,tree[node].b,av-l+2)+tree[node*2+1].a)%mod;
    tree[node*2+1].b=(ask_fib(tree[node].a,tree[node].b,av-l+3)+tree[node*2+1].b)%mod;

    tree[node].a=0;
    tree[node].b=0;

    tree[node*2].sum=recalc(node*2,l,av);
    tree[node*2+1].sum=recalc(node*2+1,av+1,r);
    tree[node].sum=recalc(node,l,r);
}
void update(int node,int l,int r,int lq,int rq,int val)
{
    if(l==lq&&r==rq)
    {
        tree[node].a=(tree[node].a+fib[val])%mod;
        tree[node].b=(tree[node].b+fib[val+1])%mod;
        tree[node].sum=recalc(node,l,r);
        return;
    }
    push(node,l,r);

    int av=(l+r)/2;
    if(lq<=av){update(node*2,l,av,lq,min(av,rq),val);val=val+(av-lq+1);}
    if(av<rq)update(node*2+1,av+1,r,max(av+1,lq),rq,val);

    tree[node].sum=recalc(node,l,r);
}
int query(int node,int l,int r,int lq,int rq)
{
    //cout<<"query "<<node<<" "<<l<<" "<<r<<" "<<lq<<" "<<rq<<" "<<tree[node]<<endl;
    if(l==lq&&r==rq)return tree[node].sum;
    push(node,l,r);
    int av=(l+r)/2;
    int ret=0;
    if(lq<=av)ret=query(node*2,l,av,lq,min(av,rq));
    if(av<rq)ret=ret+query(node*2+1,av+1,r,max(av+1,lq),rq);
    ret=normal(ret);
    return ret;
}
signed main()
{
scanf("%lld%lld",&n,&m);
for(int i=1;i<=n;i++)scanf("%lld",&arr[i]);
for(int i=1;i<=n;i++)pref[i]=(pref[i-1]+arr[i])%mod;
fib[1]=1;
fib[2]=1;
for(int i=3;i<nmax;i++)fib[i]=(fib[i-1]+fib[i-2])%mod;
for(int i=1;i<nmax;i++)pref_fib[i]=(pref_fib[i-1]+fib[i])%mod;

int type,l,r;
for(int i=1;i<=m;i++)
{
    scanf("%lld%lld%lld",&type,&l,&r);
    if(type==1)
    {
        update(1,1,n,l,r,1);
    }
    else
    {
        long long val=normal(pref[r]-pref[l-1]);
        val=normal(val+query(1,1,n,l,r));
        printf("%lld\n",val);
    }
    /*
    for(int j=1;j<=7;j++)
    {
        cout<<j<<" -> "<<tree[j].a<<" "<<tree[j].b<<" "<<tree[j].sum;cout<<endl;
    }
    */
}
return 0;
}