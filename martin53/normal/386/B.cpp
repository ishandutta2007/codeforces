#include<bits/stdc++.h>
using namespace std;
const int nmax=1e2+42;
int n,arr[nmax],t;
int main()
{
scanf("%i",&n);
for(int i=1;i<=n;i++)
    scanf("%i",&arr[i]);
scanf("%i",&t);

int ans=0;
sort(arr+1,arr+n+1);
for(int i=1;i<=n;i++)
    for(int j=i;j<=n;j++)
    if(arr[j]-arr[i]<=t)ans=max(ans,j-i+1);
printf("%i\n",ans);
return 0;
}