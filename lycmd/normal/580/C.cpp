#include<bits/stdc++.h>
using namespace std;
int const N=233333;
int n,m,top,ans,mx,a[N],s[N],cnt[N];
vector<int>e[N];
void dfs(int x,int fa){
	top++,cnt[s[top]=a[x]?s[top-1]+1:0]++;
	if(cnt[mx+1])mx++;
	if(x>1&&e[x].size()==1)
		ans+=mx<=m;
	for(int y:e[x])
		if(y^fa)dfs(y,x);
	cnt[s[top--]]--,mx-=!cnt[mx];
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<n;i++){
		int x,y;cin>>x>>y;
		e[x].push_back(y);
		e[y].push_back(x);
	}
	dfs(1,0);
	cout<<ans<<"\n";
}