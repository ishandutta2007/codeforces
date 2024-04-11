#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=200010;
int k,m,n,t,ans,x[N],y[N],a[N],s[N],vis[N];
pair<int,int>p[N];
priority_queue<pair<int,int> >q;
signed main(){
	ios::sync_with_stdio(0);
	cin>>k>>n,m=1;
	for(int i=1;i<=k;i++)
		p[i].first=(i-1)*100,cin>>p[i].second;
	for(int i=1;i<=k;i++)
		x[i]=p[i].first,y[i]=p[i].second,s[i]=s[i-1]+y[i];
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=k;i++)
		if(x[i]<a[1])t+=y[i];
	q.push({t,0}),t=0;
	for(int i=1;i<=k;i++)
		if(x[i]>a[n])t+=y[i];
	q.push({t,0});
	int pre=-1;
	for(int i=1;i<n;i++){
		int l=a[i],r=a[i+1],xl=upper_bound(x+1,x+1+k,l)-x,
			xr=lower_bound(x+1,x+1+k,r)-x-1,mx=0;
		if(xl>xr)continue;
		for(int j=xl;j<=xr;j++)
			mx=max(mx,s[j]-s[upper_bound(x+1,x+1+k,max(x[j]-(r-l+1)/2,l))-x-1]);
		q.push({mx,i}),vis[i]=s[xr]-s[xl-1]-mx;
		assert(pre<=xl);
		pre=xr;
	}
	while(!q.empty()&&m--){
		auto i=q.top();q.pop();
		ans+=i.first;
		if(vis[i.second])
			q.push({vis[i.second],0});
	}
	cout<<ans<<"\n";
}