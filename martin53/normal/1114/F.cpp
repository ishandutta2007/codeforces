#include<bits/stdc++.h>
using namespace std;
const int nmax=4e5+42,LIM=300+3,mod=1e9+7,MX=62;
bool primes[LIM];//0-> prime
vector<int> prime;
int inv[LIM];
long long my_pow(long long a,int b)
{
    if(a==0)return 0;
    if(a==1)return 1;
    long long ret=1;
    while(b)
    {
        if(b%2)ret=ret*a%mod;
        a=a*a%mod;
        b=b/2;
    }
    return ret;
}
int order[LIM];
void init()
{
    primes[0]=1;
    primes[1]=1;

    int p=2;
    while(p*p<LIM)
    {
        for(int j=p*p;j<LIM;j=j+p)primes[j]=1;
        p++;
        while(primes[p])p++;
    }

    for(int i=2;i<LIM;i++)
        if(primes[i]==0)prime.push_back(i);

    for(int i=3;i<LIM;i++)
        order[i]=order[i-1]+(!primes[i]);

    for(int i=1;i<LIM;i++)inv[i]=my_pow(i,mod-2);
}
struct info
{
    long long prod;
    long long mask;
    long long lazy;
    long long lazy_mask;
    int sz;
};

int n,arr[nmax];
int q;

info tree[4*nmax];
int LEFT[nmax*4],RIGHT[nmax*4];

info actual(info now)
{
    now.mask=now.mask|now.lazy_mask;
    now.lazy_mask=0;

    now.prod=now.prod*my_pow(now.lazy,now.sz)%mod;
    now.lazy=1;

    return now;
}

info my_merge(info l,info r)
{
    l=actual(l);
    r=actual(r);
    info ret;
    ret.prod=l.prod*r.prod%mod;
    ret.lazy=1;
    ret.lazy_mask=0;
    ret.mask=l.mask|r.mask;
    ret.sz=l.sz+r.sz;
    return ret;
}

void push(int node)
{
    tree[node*2].lazy=tree[node*2].lazy*tree[node].lazy%mod;
    tree[node*2].lazy_mask=tree[node*2].lazy_mask|tree[node].lazy_mask;

    tree[node*2+1].lazy=tree[node*2+1].lazy*tree[node].lazy%mod;
    tree[node*2+1].lazy_mask=tree[node*2+1].lazy_mask|tree[node].lazy_mask;

    tree[node].lazy=1;
    tree[node].lazy_mask=0;
}
void add(int node,int num)
{
    tree[node].lazy=tree[node].lazy*num%mod;
    for(auto k:prime)
    {
        if(k*k>num)break;
        else if(num%k==0)
        {
            while(num%k==0)num=num/k;
            tree[node].lazy_mask|=(1LL<<order[k]);
        }
    }
    if(num!=1)tree[node].lazy_mask|=(1LL<<order[num]);
}
void build(int node,int l,int r)
{
    if(l==r)
    {
        tree[node].prod=arr[l];
        for(int i=0;i<MX;i++)
            if(arr[l]%prime[i]==0)tree[node].mask=tree[node].mask^(1LL<<i);
        tree[node].lazy=1;
        tree[node].sz=1;
        return;
    }
    int av=(l+r)/2;
    build(node*2,l,av);
    build(node*2+1,av+1,r);

    tree[node]=my_merge(tree[node*2],tree[node*2+1]);
}
void update(int node,int l,int r,int lq,int rq,int mult)
{
    if(l==lq&&r==rq)
    {
        //cout<<"add "<<node<<" "<<mult<<endl;
        add(node,mult);
        return;
    }
    push(node);
    int av=(l+r)/2;
    if(lq<=av)update(node*2,l,av,lq,min(rq,av),mult);
    if(av<rq)update(node*2+1,av+1,r,max(av+1,lq),rq,mult);
    tree[node]=my_merge(tree[node*2],tree[node*2+1]);
}
info query(int node,int l,int r,int lq,int rq)
{
    if(l==lq&&r==rq)
    {
        //cout<<l<<" "<<r<<" -> "<<tree[node].prod<<" "<<tree[node].mask<<" "<<tree[node].lazy<<" "<<tree[node].lazy_mask<<" "<<tree[node].sz<<endl;
        //cout<<actual(tree[node]).prod<<endl;
        return actual(tree[node]);
    }

    push(node);
    int av=(l+r)/2;
    info ret;ret.prod=1;ret.mask=0;ret.lazy=1;ret.lazy_mask=0;

    if(lq<=av)ret=my_merge(ret,query(node*2,l,av,lq,min(av,rq)));
    if(av<rq)ret=my_merge(ret,query(node*2+1,av+1,r,max(av+1,lq),rq));

    tree[node]=my_merge(tree[node*2],tree[node*2+1]);

    return ret;
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie();
cout.tie();
init();

cin>>n>>q;
for(int i=1;i<=n;i++)
    cin>>arr[i];

build(1,1,n);

string type;
int l,r,val;
for(int i=1;i<=q;i++)
{
    cin>>type;
    if(type=="TOTIENT")
    {
        cin>>l>>r;

        info now=query(1,1,n,l,r);
        //cout<<"now: "<<l<<" "<<r<<" -> "<<now.prod<<" "<<now.mask<<" "<<now.lazy<<" "<<now.lazy_mask<<endl;
        for(int j=0;j<MX;j++)
            if((now.mask&(1LL<<j)))now.prod=now.prod*(prime[j]-1)%mod*inv[prime[j]]%mod;
        cout<<now.prod<<"\n";
    }
    else
    {
        cin>>l>>r>>val;
        update(1,1,n,l,r,val);
    }
}
return 0;
}