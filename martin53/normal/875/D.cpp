#include<bits/stdc++.h>
using namespace std;
const int nmax=2*1e5+42,C=31;
int n,arr[nmax];
int seen[C];
int le[nmax],ri[nmax];
map<int,int> there;
int main()
{
scanf("%i",&n);
for(int i=1;i<=n;i++)scanf("%i",&arr[i]);
for(int i=1;i<=n;i++)
{
    int maxi=0;
    for(int j=0;j<C;j++)
        if((arr[i]&(1<<j))==0)
        maxi=max(maxi,seen[j]);
    le[i]=maxi;
    for(int j=0;j<C;j++)
        if((arr[i]&(1<<j)))
        seen[j]=i;
}
for(int i=0;i<C;i++)seen[i]=n+1;
for(int i=n;i>=1;i--)
{
    int mini=n+1;
    for(int j=0;j<C;j++)
        if((arr[i]&(1<<j))==0)
        mini=min(mini,seen[j]);
    if(there.count(arr[i]))mini=min(mini,there[arr[i]]);
    there[arr[i]]=i;
    ri[i]=mini;
    for(int j=0;j<C;j++)
        if((arr[i]&(1<<j)))
        seen[j]=i;
}
long long ans=1LL*n*(n+1)/2;
for(int i=1;i<=n;i++)
    ans=ans-1LL*(ri[i]-i)*(i-le[i]);
printf("%lld\n",ans);
return 0;
}