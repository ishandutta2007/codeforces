#include<bits/stdc++.h>
using namespace std;

const int nmax=1e5+42,mod=998244353;

int n;

int cnt[nmax];

int dp[nmax];

long long my_pow(long long a,long long b)
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
long long coeff_sq(long long d)
{
    if(d==1)return 0;
    if(d==2)return 1;

    return (d-1)%mod*my_pow(2,d-2)%mod;
}

long long coeff_two(long long d)
{
    d=d-2;

    if(d==0)return 1;

    return (my_pow(2,d)+d%mod*my_pow(2,d-1)%mod)%mod;
}
int eval(int to_div)
{
    /*
    vector<int> v={};

    for(int i=to_div;i<nmax;i=i+to_div)
        for(int j=1;j<=cnt[i];j++)
            v.push_back(i);

    if(v.size()==0)return 0;

    long long ret=0;

    for(int i=0;i<v.size();i++)
    {
        ret=(ret+v[i]*v[i]%mod*coeff_sq(v.size()))%mod;
        //cout<<"ret= "<<ret<<" "<<coeff_sq(v.size())<<endl;
    }
    for(int i=0;i<v.size();i++)
        for(int j=i+1;j<v.size();j++)
        {
            long long cur=coeff_two(v.size());

            cur=cur*v[i]%mod*v[j]%mod*2%mod;

            ret=(ret+cur)%mod;
        }
    */

    long long sum=0,sum_sq=0;

    long long sum_0=0;

    for(int i=to_div;i<nmax;i=i+to_div)
    {
        sum_0=sum_0+cnt[i];

        sum=(sum+1LL*cnt[i]*i)%mod;
        sum_sq=(sum_sq+1LL*i*i%mod*cnt[i]%mod)%mod;
    }

    long long sum_two=(sum*sum+mod-sum_sq)%mod;

    long long ret=0;

    ret=(ret+sum_sq*coeff_sq(sum_0))%mod;

    ret=(ret+sum_two*coeff_two(sum_0))%mod;

    return ret;
}
int main()
{
    scanf("%i",&n);
    for(int i=1;i<=n;i++)
    {
        int pos;
        scanf("%i",&pos);
        scanf("%i",&cnt[pos]);
    }

    for(int i=nmax-1;i>=1;i--)
    {
        dp[i]=eval(i);

        for(int d=i+i;d<nmax;d=d+i)
        {
            dp[i]=(dp[i]-dp[d]+mod)%mod;
        }
    }

    printf("%i\n",dp[1]);
    return 0;
}