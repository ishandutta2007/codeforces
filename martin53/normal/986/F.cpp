#include<bits/stdc++.h>
using namespace std;
const int tmax=1e4+42,MX=32e6,K_MAX=1e5+42;
struct query
{
    long long n,k;
    int id;
};
bool cmp(query a,query b)
{
    return a.k<b.k;
}
int t;
query inp[tmax];

bitset<MX> is_prime;//0-> prime
vector<int> primes;
void prec()
{
    int p=2;
    while(p*p<MX)
    {
        for(int j=p*p;j<MX;j=j+p)is_prime[j]=1;
        p++;
        while(is_prime[p])p++;
    }

    for(int i=2;i<MX;i++)
        if(is_prime[i]==0)primes.push_back(i);
}

bool output[tmax];

vector<long long> current;

long long dist[K_MAX];
priority_queue< pair<long long/*dist*/,int/*mod*/> > pq;

long long my_pow(long long a,long long b,long long mod)
{
    if(b==0)return 1;
    long long mem=my_pow(a,b/2,mod);
    if(b%2)return mem*mem%mod*a%mod;
    return mem*mem%mod;
}
void solve(int l,int r)
{
    current={};
    for(auto k:primes)
    {
        if(1LL*k*k>inp[l].k)break;
        if(inp[l].k%k==0)
        {
            while(inp[l].k%k==0)inp[l].k=inp[l].k/k;
            current.push_back(k);
        }
    }

    if(inp[l].k!=1)current.push_back(inp[l].k);

    if(current.size()==0)return;
    if(current.size()==1)
    {
        long long p=current[0];
        for(int j=l;j<=r;j++)
            if(inp[j].n%p==0)output[inp[j].id]=1;
        return;
    }

    if(current.size()>=3)//the minimal is up to k^(1/3)<=10^5
    {
        for(int j=0;j<current[0];j++)
            dist[j]=-1;
        pq.push({0,0});
        while(pq.size())
        {
            pair<long long/*dist*/,int/*mod*/> now=pq.top();
            pq.pop();

            if(dist[now.second]!=-1)continue;
            dist[now.second]=-now.first;
            for(int i=1;i<current.size();i++)
                pq.push({-(-now.first+current[i]),(-now.first+current[i])%current[0]});
        }

        for(int j=l;j<=r;j++)
            if(dist[inp[j].n%current[0]]<=inp[j].n)output[inp[j].id]=1;
    }
    //current[0]*a+current[1]*b=n
    for(int j=l;j<=r;j++)
        if(inp[j].n%current[0]==0||inp[j].n%current[1]==0)output[inp[j].id]=1;
        else
        {
            long long b=my_pow(current[1]%current[0],current[0]-2,current[0]);
            b=b*(inp[j].n%current[0])%current[0];

            if(b<=inp[j].n/current[1])output[inp[j].id]=1;
        }
}
int main()
{
    prec();

    scanf("%i",&t);
    for(int i=1;i<=t;i++)
    {
        scanf("%lld%lld",&inp[i].n,&inp[i].k);
        inp[i].id=i;
    }

    sort(inp+1,inp+t+1,cmp);

    for(int i=1;i<=t;i++)
    {
        int j=i;
        while(j<=t&&inp[i].k==inp[j].k)j++;

        solve(i,j-1);

        i=j-1;
    }

    for(int i=1;i<=t;i++)
        if(output[i])printf("YES\n");
        else printf("NO\n");
    return 0;
}