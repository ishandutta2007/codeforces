#include<bits/stdc++.h>
#define int long long
using namespace std;
const int nmax=1e5+42;
int n,m,k;
int arr[nmax];
bool can(int le)
{
    int cover=0;
    int ret=0;
    for(int i=1;i<=n;i++)
        if(cover<arr[i])cover=arr[i]+le-1,ret++;
    return ret<=k;
}
int d[nmax];
signed main()
{
cin>>n>>m>>k;
for(int i=1;i<=n;i++)cin>>arr[i];
for(int i=1;i<n;i++)d[i]=arr[i+1]-arr[i];
sort(d+1,d+n);
/*
int ok=m+1,not_ok=-1;
while(ok-not_ok>1)
{
    int av=(ok+not_ok)/2;
    if(can(av))ok=av;
    else not_ok=av;
}
*/
int ok=k;
for(int i=n-k;i>=1;i--)ok=ok+d[i];
cout<<ok<<endl;
return 0;
}