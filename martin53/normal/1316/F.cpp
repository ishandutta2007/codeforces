#include<bits/stdc++.h>
using namespace std;

const int nmax=6e5+42,mod=1e9+7;

long long my_pow(long long a,int b)
{
    long long ret=1;

    while(b)
    {
        if(b%2)ret=ret*a%mod;
        b=b/2;
        a=a*a%mod;
    }
    return ret;
}

long long inv(long long a)
{
    return my_pow(a,mod-2);
}
struct info
{
    long long sum_incr;//pi*2^i
    long long sum_decr;//pj*2^(-j)
    int cnt;
    long long sum;
};
info tree[4*nmax];

long long mem_powers[nmax],mem_inv_powers[nmax];

long long sum_sq=0;

pair<int,int> mem[nmax];

int n,q,inp[nmax],all[nmax];

info my_merge(info l,info r)
{
    info ret;
    ret.cnt=l.cnt+r.cnt;

    ret.sum_incr=(l.sum_incr+1LL*mem_powers[l.cnt]*r.sum_incr)%mod;
    ret.sum_decr=(l.sum_decr+1LL*mem_inv_powers[l.cnt]*r.sum_decr)%mod;

    ret.sum=(l.sum+r.sum)%mod;
    ret.sum=(ret.sum+1LL*l.sum_incr*r.sum_decr%mod*mem_inv_powers[l.cnt])%mod;

    return ret;
}

info mem_alone[nmax];

void update(int node,int l,int r,int pos,int coeff)
{
    if(l==r)
    {
        tree[node].cnt+=coeff;
        tree[node].sum_incr=all[pos]*mem_alone[tree[node].cnt].sum_incr%mod;
        tree[node].sum_decr=all[pos]*mem_alone[tree[node].cnt].sum_decr%mod;

        tree[node].sum=1LL*all[pos]*all[pos]%mod*mem_alone[tree[node].cnt].sum%mod;

        //cout<<"update "<<pos<<" "<<coeff<<" -> "<<tree[node].sum_incr<<" "<<tree[node].sum_decr<<" "<<tree[node].sum<<endl;

        return;
    }

    int av=(l+r)/2;
    if(pos<=av)update(node*2,l,av,pos,coeff);
    else update(node*2+1,av+1,r,pos,coeff);

    tree[node]=my_merge(tree[node*2],tree[node*2+1]);
}
void upd(int val,int coeff)
{
    int pos=lower_bound(all+1,all+n+q+1,val)-all;

    update(1,1,n+q,pos,coeff);
}

long long query()
{
    return 1LL*tree[1].sum*mem_inv_powers[1]%mod;
}

int main()
{
    scanf("%i",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%i",&inp[i]);
        all[i]=inp[i];
    }

    mem_powers[0]=1;
    mem_inv_powers[0]=1;

    for(int i=1;i<=n;i++)
    {
        mem_powers[i]=mem_powers[i-1]*2%mod;
        mem_inv_powers[i]=inv(mem_powers[i]);
    }

    mem_alone[1].cnt=1;
    mem_alone[1].sum_incr=2;
    mem_alone[1].sum_decr=inv(2);
    mem_alone[1].sum=0;

    for(int i=2;i<=n;i++)
        mem_alone[i]=my_merge(mem_alone[i-1],mem_alone[1]);

    scanf("%i",&q);
    for(int i=1;i<=q;i++)
    {
        scanf("%i%i",&mem[i].first,&mem[i].second);
        all[i+n]=mem[i].second;
    }

    sort(all+1,all+n+q+1);

    for(int i=1;i<=n;i++)
        upd(inp[i],1);

    printf("%lld\n",query());

    for(int i=1;i<=q;i++)
    {
        upd(inp[mem[i].first],-1);

        inp[mem[i].first]=mem[i].second;

        upd(inp[mem[i].first],1);

        printf("%lld\n",query());
    }
    return 0;
}