#include<iostream>
using namespace std;
bool isp[1000];
int main()
{
int aval[1000];
int z=0,n,res=0,k;
    cin>>n>>k;
  for(int i=2;i<=n;i++)
    {
      if(isp[i]==0)
{
aval[z++]=i;
for (int j=i*i;j<=n;j+=i)
isp[j]=1;}
    }
for(int i=5;i<=n;i++)
{
        if(isp[i]==0)
for(int j=0;j<z;j++)
{
if(aval[j]+aval[j+1]+1==i)
{res++; break;}
if(aval[j]>i)
break;
}
}
if(res>=k)
cout<<"Yes";
else
cout<<"No";
}