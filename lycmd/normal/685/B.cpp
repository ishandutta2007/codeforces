#include<bits/stdc++.h>
using namespace std;
int const N=300010;
int n,q,x,fa[N],sz[N],mx[N],ans[N];
vector<int>e[N];
void solve(int x){
	sz[x]=1;
	for(int y:e[x])
		solve(y),sz[x]+=sz[y],mx[x]=max(mx[x],sz[y]);
	if(mx[x]<=sz[x]/2)
		return ans[x]=x,void();
	for(int y:e[x])
		if(sz[y]==mx[x]){
			int p=ans[y];
			while(max(mx[p],sz[x]-sz[p])>sz[x]/2)
				p=fa[p];
			return ans[x]=p,void();
		}
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>q;
	for(int i=2;i<=n;i++)
		cin>>fa[i],e[fa[i]].push_back(i);
	for(solve(1);q--;)
		cin>>x,cout<<ans[x]<<"\n";
}