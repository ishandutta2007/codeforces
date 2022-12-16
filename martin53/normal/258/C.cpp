#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+42,LIM=1e5+42,mod=1e9+7;
int n,a[nmax];
vector<int> divisors[LIM];
int at_least[LIM];
long long my_pow(long long a,long long b)
{
if(b==0)return 1;
long long c=my_pow(a,b/2);
if(b%2==0)return c*c%mod;
return ((c*c)%mod)*a%mod;
}
int main()
{
cin>>n;
for(int i=1;i<=n;i++)cin>>a[i];
for(int i=1;i<LIM;i++)
    for(int j=1;i*j<LIM;j++)
    divisors[i*j].push_back(i);
sort(a+1,a+n+1);
int p=1;
for(int i=1;i<=a[n];i++)
{
    at_least[i]=n+1-p;
    while(i==a[p])p++;
}
long long ans=0;

for(int i=1;i<=a[n];i++)
{
    //if(i<=a[1])ans=(ans-(n-1)+mod)%mod;
    long long ways=my_pow(divisors[i].size(),at_least[i])-my_pow(divisors[i].size()-1,at_least[i]);
    ways=(ways+mod)%mod;

    int k=divisors[i].size();
    for(int j=0;j<k-1;j++)
        ways=ways*my_pow(j+1,at_least[divisors[i][j]]-at_least[divisors[i][j+1]])%mod;

    ans=(ans+ways)%mod;
    //cout<<i<<" -> "<<ans<<endl;
}

cout<<ans<<endl;
return 0;
}