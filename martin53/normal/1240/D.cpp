#include<bits/stdc++.h>
using namespace std;
const int nmax=1e6+42;
int n,inp[nmax];

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int prime_1,prime_2;
int base_1,base_2;
int inv_1,inv_2;

long long dc(int l,int r)
{
    if(l==r)return 0;

    int av=(l+r)/2;
    long long ret=dc(l,av)+dc(av+1,r);

    map< pair<int,int> ,int> seen_r={};
    vector<int> now_ri={};

    long long hsh_ri_1=0,hsh_ri_2=0;

    for(int i=av+1;i<=r;i++)
    {
        if(now_ri.size()==0||(now_ri.size()&&now_ri.back()!=inp[i]))
        {
            hsh_ri_1=(hsh_ri_1*base_1+inp[i])%prime_1;
            hsh_ri_2=(hsh_ri_2*base_2+inp[i])%prime_2;

            now_ri.push_back(inp[i]);
        }
        else
        {
            hsh_ri_1=((hsh_ri_1-inp[i])*inv_1%prime_1+prime_1)%prime_1;
            hsh_ri_2=((hsh_ri_2-inp[i])*inv_2%prime_2+prime_2)%prime_2;

            now_ri.pop_back();
        }
        seen_r[{hsh_ri_1,hsh_ri_2}]++;
    }


    vector<int> now_le={};

    long long hsh_le_1=0,hsh_le_2=0;

    for(int i=av;i>=l;i--)
    {
        if(now_le.size()==0||(now_le.size()&&now_le.back()!=inp[i]))
        {
            hsh_le_1=(hsh_le_1*base_1+inp[i])%prime_1;
            hsh_le_2=(hsh_le_2*base_2+inp[i])%prime_2;

            now_le.push_back(inp[i]);
        }
        else
        {
            hsh_le_1=((hsh_le_1-inp[i])*inv_1%prime_1+prime_1)%prime_1;
            hsh_le_2=((hsh_le_2-inp[i])*inv_2%prime_2+prime_2)%prime_2;

            now_le.pop_back();
        }
        if(seen_r.count({hsh_le_1,hsh_le_2}))ret=ret+seen_r[{hsh_le_1,hsh_le_2}];
    }
    return ret;
}
long long solve()
{
    scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    map< pair<int,int> ,int> seen_r={};
    vector<int> now_ri={};

    long long hsh_ri_1=0,hsh_ri_2=0;

    seen_r[{0,0}]++;

    long long ret=0;
    for(int i=1;i<=n;i++)
    {
        if(now_ri.size()==0||(now_ri.size()&&now_ri.back()!=inp[i]))
        {
            hsh_ri_1=(hsh_ri_1*base_1+inp[i])%prime_1;
            hsh_ri_2=(hsh_ri_2*base_2+inp[i])%prime_2;

            now_ri.push_back(inp[i]);
        }
        else
        {
            hsh_ri_1=((hsh_ri_1-inp[i])*inv_1%prime_1+prime_1)%prime_1;
            hsh_ri_2=((hsh_ri_2-inp[i])*inv_2%prime_2+prime_2)%prime_2;

            now_ri.pop_back();
        }
        if(seen_r.count({hsh_ri_1,hsh_ri_2}))ret=ret+seen_r[{hsh_ri_1,hsh_ri_2}];
        seen_r[{hsh_ri_1,hsh_ri_2}]++;
    }

    return ret;
}

bool prime(int ret)
{
    for(int i=2;i*i<=ret;i++)
        if(ret%i==0)return 0;
    return 1;
}
int nxt(int pr)
{
    while(prime(pr)==0)
    {
        pr++;
    }
    return pr;

}

long long my_pow(long long a,long long b,long long mod)
{
    long long ret=1;
    while(b)
    {
        if(b%2)ret=ret*a%mod;
        a=a*a%mod;
        b=b/2;
    }
    return ret;
}
int main()
{
    prime_1=nxt(1e9+rng()%10000);
    base_1=nxt(10+rng()%100);
    inv_1=my_pow(base_1,prime_1-2,prime_1);

    prime_2=nxt(2e9+rng()%10000);
    base_2=nxt(base_1+rng()%100+1);
    inv_2=my_pow(base_2,prime_2-2,prime_2);
    /*
    cout<<prime_1<<" "<<base_1<<" "<<inv_1<<endl;
    cout<<prime_2<<" "<<base_2<<" "<<inv_2<<endl;
    */
    int q;
    scanf("%i",&q);

    for(int i=1;i<=q;i++)
        printf("%lld\n",solve());

    return 0;
}