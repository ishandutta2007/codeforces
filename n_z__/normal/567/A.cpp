#include<bits/stdc++.h>
#define int long long
using namespace std;
pair<int,int>a[100002];
int ans[100001][2];
signed main()
{
    int n;
    cin>>n;
    for(int x=1;x<=n;x++)
    cin>>a[x].first,a[x].second=x;
    sort(a+1,a+1+n);
    a[0].first=a[1].first-10000000000;
    a[n+1].first=a[n].first+10000000000;
	for(int x=1;x<=n;x++)
	ans[a[x].second][0]=min(a[x].first-a[x-1].first,a[x+1].first-a[x].first),ans[x][1]=max(a[x].first-a[1].first,a[n].first-a[x].first);
	for(int x=1;x<=n;x++)
	cout<<ans[x][0]<<' '<<ans[x][1]<<endl;
}