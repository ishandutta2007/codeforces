#include<bits/stdc++.h>
using namespace std;
const int nmax=3e5+42,stop=550;
struct query
{
int a,b,ind;
};
int n;
int arr[nmax];
int p;
query inp[nmax];
bool cmp(query u,query v)
{
if(u.b!=v.b)return u.b<v.b;
return u.a<v.a;
}
long long sum[nmax];
long long outp[nmax];
int main()
{
scanf("%i",&n);
for(int i=1;i<=n;i++)scanf("%i",&arr[i]);
scanf("%i",&p);
for(int i=1;i<=p;i++)
{
scanf("%i%i",&inp[i].a,&inp[i].b);
inp[i].ind=i;
}
sort(inp+1,inp+p+1,cmp);
int ind=1;
for(int i=1;i<=stop;i++)
{
    for(int pos=n;pos>=1;pos--)
    {
        if(pos+i-1>n)sum[pos]=arr[pos];
        else sum[pos]=sum[pos+i]+arr[pos];
    }
    while(ind<=p&&inp[ind].b==i)
    {
        outp[inp[ind].ind]=sum[inp[ind].a];
        ind++;
    }
}
for(int i=ind;i<=p;i++)
{
    long long s=0;
    for(int j=inp[i].a;j<=n;j=j+inp[i].b)
        s=s+arr[j];
    outp[inp[i].ind]=s;
}
for(int i=1;i<=p;i++)printf("%lld\n",outp[i]);
return 0;
}