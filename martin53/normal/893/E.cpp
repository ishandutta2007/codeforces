#include<bits/stdc++.h>
using namespace std;
const int nmax=1e6+42,mod=1e9+7;
vector<int> divs[nmax];
int st[nmax];
int inv[30];
int my_pow(int a,int b)
{
    if(b==0)return 1;
    int c=my_pow(a,b/2);
    if(b%2==0)return 1LL*c*c%mod;
    return 1LL*c*c%mod*a%mod;
}
int main()
{
for(int i=2;i<nmax;i++)
    if(divs[i].size()==0)
    {
        for(int j=i;j<nmax;j=j+i)
            divs[j].push_back(i);
    }
st[0]=1;
for(int i=1;i<nmax;i++)st[i]=(st[i-1]*2)%mod;

for(int i=0;i<30;i++)inv[i]=my_pow(i,mod-2);
int q;
int prod,nums;
scanf("%i",&q);
for(int i=1;i<=q;i++)
{
    scanf("%i%i",&prod,&nums);
    int p=st[nums-1];
    int q=1;

    int c=prod;
    for(auto k:divs[prod])
    {
        int t=0;
        while(c%k==0)
        {
            c=c/k;
            t++;
            q=(1LL*q*(nums-1+t))%mod;
            q=(1LL*q*inv[t])%mod;
        }
    }
    //cout<<p<<" "<<q<<endl;
    printf("%i\n",1LL*p*q%mod);
}
return 0;
}