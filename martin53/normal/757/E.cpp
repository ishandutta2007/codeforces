#include<bits/stdc++.h>
using namespace std;
const int nmax=1e6+42,mod=1e9+7;
vector<int> powers[nmax];
long long inv[30];
int query()
{
int r,n;
scanf("%i%i",&r,&n);
if(n==1)return 1;
long long ans=1;
long long now;
for(auto i:powers[n])
{
    //cout<<"i= "<<i<<" ";
    now=1;
    for(int j=1;j<i;j++)
        now=now*(r+j)%mod;
    now=now*(r+2*i)%mod;
    now=now*inv[i]%mod;
    ans=ans*now%mod;
}
//cout<<endl;
return ans;
}
long long my_pow(long long a,long long b)
{
    if(b==0)return 1;
    long long c=my_pow(a,b/2);
    if(b%2==0)return c*c%mod;
    return c*c%mod*a%mod;
}
bool prime[nmax];//0->prime
void pre()
{
    long long f=1;
    inv[0]=1;
    for(int i=1;i<30;i++)
    {
        f=f*i%mod;
        inv[i]=my_pow(f,mod-2);
    }
    prime[0]=1;
    prime[1]=1;
    int p=2;
    while(p*p<nmax)
    {
        for(int j=p*p;j<nmax;j=j+p)prime[j]=1;
        p++;
        while(prime[p])p++;
    }
    int ci,now;
    for(p=2;p<nmax;p++)
        if(prime[p]==0)
        for(int i=p;i<nmax;i=i+p)
        {
            ci=i;
            now=0;
            while(ci%p==0)
            {
            ci=ci/p;
            now++;
            }
            powers[i].push_back(now);
        }

}
int main()
{

pre();
int q;
scanf("%i",&q);
for(int i=1;i<=q;i++)
    printf("%i\n",query());
return 0;
}