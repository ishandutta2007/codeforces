#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=300010;
int n,m,k,s,l,r,a[N],vis[N],ans[N];
vector<pair<int,int> >e[N];
void solve(int x){
	vis[x]=1;
	for(auto i:e[x]){
		int y=i.first,op=i.second;
		if(vis[y])continue;
		solve(y);
		if(a[x]+a[y]>=k)
			ans[++l]=op,a[x]+=a[y]-k;
		else
			ans[--r]=op;
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i],s+=a[i];
	for(int i=1;i<=m;i++){
		int x,y;cin>>x>>y;
		e[x].push_back({y,i});
		e[y].push_back({x,i});
	}
	if(s<(n-1)*k)
		cout<<"NO\n",exit(0);
	r=n,solve(1);
	cout<<"YES\n";
	for(int i=1;i<n;i++)
		cout<<ans[i]<<"\n";
}