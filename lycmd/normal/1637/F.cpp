#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=200010;
int n,ans,rt,h[N];
vector<int>e[N];
int up(int&x,int y){
	return x<y&&(ans+=y-x,(x=y)),x;
}
int dfs(int x,int fa){
	int mx1=0,mx2=0;
	for(int y:e[x]){
		if(y==fa)
			continue;
		int t=dfs(y,x);
		if(t>mx1)
			swap(t,mx1);
		if(t>mx2)
			swap(t,mx2);
	}
	return !fa&&up(mx2,h[x]),up(mx1,h[x]);
}
signed main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>h[i];
	for(int i=1,x,y;i<n;i++)
		cin>>x>>y,e[x].push_back(y),e[y].push_back(x);
	for(int i=1;i<=n;i++)
		if(h[i]>h[rt])
			rt=i;
	dfs(rt,0);
	cout<<ans<<"\n";
}