#include<bits/stdc++.h>
using namespace std;
const int nmax=2*1e5+42;
int n,arr[nmax];
int main()
{
cin>>n;
for(int i=1;i<=2*n;i++)cin>>arr[i];

sort(arr+1,arr+2*n+1);

long long h=arr[n]-arr[1],w=arr[2*n]-arr[n+1];

long long ans=h*w;
for(int i=2;i<=n;i++)
{
    h=arr[n-1+i]-arr[i];
    w=arr[2*n]-arr[1];
    ans=min(ans,h*w);
}
cout<<ans<<endl;

return 0;
}