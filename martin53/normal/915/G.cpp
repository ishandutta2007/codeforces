#include<bits/stdc++.h>
using namespace std;
const int nmax=2*1e6+42,mod=1e9+7;
int n,k;
vector<int> divs[nmax];
int mob[nmax];

int st[nmax];

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
long long now[nmax];
int main()
{
cin>>n>>k;

for(int i=1;i<=k;i++)
    mob[i]=1;

for(int i=1;i<nmax;i++)
{
    for(int j=i;j<=k;j=j+i)
    divs[j].push_back(i);

    if(divs[i].size()==2)
    {
        if(i<=2000)
        {
        for(int j=i*i;j<=k;j=j+i*i)
            mob[j]=0;
        }

            for(int j=i;j<=k;j=j+i)
                mob[j]=-mob[j];

    }
}

for(int i=1;i<=k;i++)
    st[i]=my_pow(i,n);

long long output=0,sum=0;

for(int i=1;i<=k;i++)
{
    for(auto d:divs[i])
    {
        sum=sum-mob[d]*now[d];

        sum=(sum+mod)%mod;

        now[d]=st[i/d];

        sum=sum+mob[d]*now[d];

        sum=(sum+mod)%mod;
    }

    //cout<<i<<" -> "<<sum<<endl;

    output=(output+(sum^i))%mod;
}
cout<<output<<endl;
return 0;
}