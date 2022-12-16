#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7,kmax=1e4+42,LIM=1e5+42,P=55;
long long n;
int OP;
vector<long long> s;
vector<long long> pr;
long long inv(long long a)
{
    a=a%mod;
    long long b=mod-2;
    long long ret=1;
    while(b)
    {
        if(b%2)ret=ret*a%mod;
        a=a*a%mod;
        b=b/2;
    }
    return ret;
}
int help[LIM];
int dp[P][P][2];
set<int> possible;
int main()
{
for(int i=1;i<LIM;i++)help[i]=inv(i);
/*
fact[0]=1;
for(int i=1;i<kmax;i++)fact[i]=fact[i-1]*i%mod;
long long nn;
*/
cin>>n>>OP;
/*
if(n==1)
{
    cout<<1<<endl;
    return 0;
}
*/
for(long long i=1;i*i<=n;i++)
    if(n%i==0)
    {
        s.push_back(i);
        if(n/i!=i)s.push_back(n/i);
    }
sort(s.begin(),s.end());
long long nn=n;
for(long long i=2;i*i<=n;i++)
    if(n%i==0)
    {
        pr.push_back(i);
        int t=0;
        while(n%i==0)n=n/i,t++;
        possible.insert(t);
    }
if(n!=1){pr.push_back(n);possible.insert(1);}

long long add=0;
for(auto power:possible)
    {
    dp[power][power][0]=1;
    for(int turn=1;turn<=OP;turn++)
        {
        for(int i=0;i<=power;i++)
            dp[power][i][turn&1]=0;
        for(int power_now=0;power_now<=power;power_now++)
            for(int i=0;i<=power_now;i++)
            {
                add=/*(power+1)**/help[power_now+1];
                add=add%mod;
                add=add*dp[power][power_now][!(turn&1)];
                add=add%mod;
                //cout<<add<<endl;
                dp[power][i][turn&1]+=add;
                if(dp[power][i][turn&1]>=mod)dp[power][i][turn&1]-=mod;
            }
        /*
        cout<<turn<<" -> ";
        for(int i=0;i<=power;i++)
            cout<<dp[power][i][turn&1]<<" ";cout<<endl;
        */
        }
    }
//cout<<s.size()<<endl;
long long ans=0;
for(auto k:s)
{
    long long prod=k;
    prod=prod%mod;
    int t=0,other=0;
    long long cop;
        for(auto p:pr)
        {
            cop=k;
            t=0;
            while(cop%p==0)
            {
                cop=cop/p;
                t++;
            }
            other=0;
            cop=nn;
            while(cop%p==0)
            {
                cop=cop/p;
                other++;
            }
        //cout<<k<<" -> "<<prod<<" "<<p<<" "<<other<<" "<<t<<" "<<dp[other][t][OP&1]<<endl;
        prod=prod*dp[other][t][OP&1]%mod;
        }
    ans=ans+prod;
    ans=ans%mod;
}
//cout<<ans<<endl;
//for(int j=1;j<=OP;j++)ans=ans*inv(s.size())%mod;
cout<<ans<<endl;
/*
cout<<11LL*inv(18)%mod<<endl;
cout<<5LL*inv(18)%mod<<endl;
cout<<2LL*inv(18)%mod<<endl;
*/
return 0;
}