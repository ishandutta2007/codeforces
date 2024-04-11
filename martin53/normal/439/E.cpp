#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+42,mod=1e9+7;
vector<int> divisors[nmax];
long long fact[nmax],inv[nmax];
long long my_pow(long long a,long long b)
{
    if(b==0)return 1;
    long long c=my_pow(a,b/2);
    if(b%2==0)return c*c%mod;
    return c*c%mod*a%mod;
}
map<int,int> seen[nmax];
int C(int a,int b)
{
return fact[a]*inv[b]%mod*inv[a-b]%mod;
}
int rec(int n,int f)
{
    if(n<f)return 0;
    if(seen[f].count(n))return seen[f][n];
    int ans=C(n-1,f-1);
    for(auto d:divisors[n])
    {
    ans=ans-rec(n/d,f);
    if(ans<0)ans=ans+mod;
    }
    seen[f][n]=ans;
    return ans;
}
int main()
{
for(int d=2;d<nmax;d++)
    for(int i=d;i<nmax;i=i+d)
        divisors[i].push_back(d);
fact[0]=1;
for(int i=1;i<nmax;i++)fact[i]=(fact[i-1]*i)%mod;
for(int i=0;i<nmax;i++)inv[i]=my_pow(fact[i],mod-2);

ios_base::sync_with_stdio(false);
cin.tie();
cout.tie();

int q,n,f;
cin>>q;
for(int i=1;i<=q;i++)
{
cin>>n>>f;
cout<<rec(n,f)<<endl;
}
return 0;
}