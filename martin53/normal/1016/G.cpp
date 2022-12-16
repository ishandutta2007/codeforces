#include<bits/stdc++.h>
using namespace std;

const int nmax=2e5+42,MX=1e6;

int n;
long long x,y;

long long inp[nmax];

long long mult(long long a,long long b,long long mod)
{
    long long ret=0;

    while(b)
    {
        if(b%2)
        {
            ret=ret+a;
            if(ret>=mod)ret=ret-mod;
        }

        a=a+a;
        if(a>=mod)a=a-mod;

        b=b/2;
    }
    return ret;
}
long long eval(long long x,long long free,long long mod)
{
    x=mult(x,x,mod);
    x=(x+free)%mod;
    return x;
}

mt19937 rng(42);
long long go(long long num)
{
    int free=rng()%10000+1;

    long long x=eval(2,free,num),y=2;

    int cnt=0;

    while(__gcd(abs(x-y),num)==1)
    {
        cnt++;
        if(cnt>MX/2)return -1;

        x=eval(x,free,num);
        x=eval(x,free,num);

        y=eval(y,free,num);
    }

    return __gcd(abs(x-y),num);
}
vector< long long > faster(long long num)
{
    //cout<<"num= "<<num<<endl;

    vector<long long> ret={};

    while(1)
    {
        long long cur=go(num);

        if(cur==-1)
        {
            ret.push_back(num);
            break;
        }

        if(cur==num)continue;

        ret.push_back(cur);
        ret.push_back(num/cur);
        break;
    }

    return ret;
}
vector< long long > factor(long long num)
{
    vector< long long > ret={};

    for(long long i=2;i*i<=num&&i<=MX;i++)
        if(num%i==0)
        {
            int deg=0;

            while(num%i==0)
            {
                deg++;
                num=num/i;
            }

            ret.push_back(i);
        }

    if(num==1)return ret;

    if(num<=1LL*MX*MX)ret.push_back(num);
    else
    {
        vector<long long> help=faster(num);

        for(auto k:help)
            ret.push_back(k);
    }

    return ret;
}

vector<long long> primes;

vector<int> mem_deg[nmax];

vector<int> fast_factor(long long num)
{
    vector<int> ret={};

    for(auto k:primes)
    {
        int deg=0;

        while(num%k==0)
        {
            deg++;
            num=num/k;
        }

        ret.push_back(deg);
    }

    return ret;
}

void gen_new_primes()
{
    vector<int> le=fast_factor(x),ri=fast_factor(y);

    vector<long long> new_primes={};

    for(int i=0;i<le.size();i++)
    {
        if(le[i]!=ri[i])new_primes.push_back(primes[i]);
    }

    primes=new_primes;
}

int low[nmax],high[nmax];

int main()
{
    scanf("%i%lld%lld",&n,&x,&y);

    for(int i=1;i<=n;i++)scanf("%lld",&inp[i]);

    if(y%x)
    {
        printf("0\n");
        return 0;
    }

    primes=factor(y);

    //for(auto w:primes)cout<<w<<" ";cout<<endl;

    gen_new_primes();

    inp[n+1]=x;
    inp[n+2]=y;

    for(int i=1;i<=n+2;i++)
    {
        mem_deg[i]=fast_factor(inp[i]);
    }

    for(int i=1;i<=n;i++)
        if(inp[i]%x==0)
        {
            int mask=0;

            for(int j=0;j<primes.size();j++)
                if(mem_deg[n+1][j]<mem_deg[i][j])mask+=(1<<j);

            low[mask]++;
        }

    for(int i=1;i<=n;i++)
        if(y%inp[i]==0)
        {
            int mask=0;

            for(int j=0;j<primes.size();j++)
                if(mem_deg[i][j]<mem_deg[n+2][j])mask+=(1<<j);

            high[mask]++;
        }

    long long outp=0;

    for(int p=0;p<(1<<primes.size());p++)
    {
        int remain=(1<<primes.size())-1-p;

        for(int q=remain;true;q=(q-1)&remain)
        {
            outp+=1LL*low[p]*high[q];

            if(q==0)break;
        }
    }
    printf("%lld\n",outp);

    return 0;
}