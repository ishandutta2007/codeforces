#include<bits/stdc++.h>
using namespace std;
#define int long long
pair<int,int>g[200001];
main()
{
    int n,a,b;
    cin>>n>>a>>b;
    int ch=(1<<a);
    for(int y=1;y<=n;y++)
    {
        cin>>g[y].first>>g[y].second;
    }
    sort(g+1,g+1+n,[](pair<int,int>a,pair<int,int>b){return a.second-a.first<b.second-b.first;});
    int sum=0;
    for(int x=1;x<=b;x++)sum+=max(g[x].first,g[x].second);
    for(int x=b+1;x<=n;x++)sum+=g[x].second;
	int ans=sum;
    for(int x=1;x<=b;x++)
    ans=max(ans,sum-max(g[x].first,g[x].second)+ch*g[x].first);
    sum=sum+g[b].second-max(g[b].second,g[b].first);
    if(b)
    for(int x=b+1;x<=n;x++)
    ans=max(ans,sum-g[x].second+g[x].first*ch);
    cout<<ans<<endl;
}