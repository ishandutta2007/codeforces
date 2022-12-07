#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#define lowbit(x) ((x)&(-(x)))
using namespace std;
typedef long long LL;
const int MAXN=500010;
const int MAXK=10000010;
const int MOD=1000000007;
int n,a[MAXN];
int prime[1000010],tot;
int c[MAXK],d[MAXK],factor[MAXK],O[MAXN],Log[513],Factors[10];
LL mu[MAXK];
bool p[MAXK];
LL Pow[MAXN],sum,ans;
void get_prime(int n)
{
    mu[1]=1;
    for(int i=2;i<=n;i++)
    {
        if(!p[i]) prime[++tot]=i,factor[i]=i,mu[i]=-1;
        for(int j=1;j<=tot&&i*prime[j]<=n;j++)
        {
            p[i*prime[j]]=true;
            factor[i*prime[j]]=prime[j];
            if(i%prime[j]) mu[i*prime[j]]=MOD-mu[i];
            else {mu[i*prime[j]]=0;break;}
        }
    }
}
int main()
{
    get_prime(10000000);
    scanf("%d",&n);
    Log[0]=-1;
    for(int i=1;i<=512;i++) Log[i]=Log[i>>1]+1;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]),c[a[i]]++;
    for(int i=1;i<=10000000;i++)
    {
        if(mu[i]==0) continue;
        for(int j=i;j<=10000000;j+=i)
            d[i]+=c[j];
    }
    Pow[0]=1;
    for(int i=1;i<=n;i++)
        Pow[i]=(Pow[i-1]+Pow[i-1])%MOD;
    for(int i=2;i<=10000000;i++)
    {
        if(mu[i]==0) continue;
        sum=(sum+(MOD-mu[i])*(Pow[d[i]]-1+MOD))%MOD;
    }
    O[0]=1;
    for(int i=1;i<=n;i++)
    {
        vector<int> factors;
        factors.clear();
        int x=a[i];
        while(x!=1)
        {
            if(factors.empty()||factors[(int)factors.size()-1]!=factor[x])
                factors.push_back(factor[x]);
            x/=factor[x];
        }
        int Len=(int)factors.size();
        for(int i=0;i<Len;i++) Factors[i]=factors[i];
        LL res=0,s=sum;
        for(int S=1;S<(1<<Len);S++)
        {
            O[S]=O[S^lowbit(S)]*Factors[Log[lowbit(S)]];
            int o=O[S];
            res=(res+mu[o]*(Pow[d[o]-1]-1+MOD))%MOD;
            s=(s-(MOD-mu[o])*(Pow[d[o]]-Pow[d[o]-1]))%MOD;
        }
        ans=(ans+s+res)%MOD;
    }
    printf("%d\n",(int)(ans+MOD)%MOD);
    return 0;
}