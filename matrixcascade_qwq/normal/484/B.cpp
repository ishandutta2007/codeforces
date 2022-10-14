#include <iostream>
#include <algorithm>
using namespace std;
int a[200001],mx=0,mn=9999999,f[20000001],n,pas;
main()
{
	cin>>n;
    for(int i=1;i<=n;i++)
    {cin>>a[i];f[a[i]]=a[i]; mn=min(mn,a[i]);
        mx=max(mx,a[i]);}
pas=mx%mn;
for(int i=1;i<=2*mx;i++)
if(f[i]==0)
f[i]=f[i-1];
for(int i=1;i<=2*mx;i++)

if(f[i]!=0)
for(int k=2*i-1;k<=2*mx;k+=i)
if(f[k]!=0 && pas<=f[k]%f[i])
pas=f[k]%f[i];
cout<<pas<<endl;
//system("pause");
return 0;

}