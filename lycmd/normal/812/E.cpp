#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=100010;
int n,ans,xs,mx,c,a[N],d[N];
vector<int>e[N],b;
map<int,int>f;
void dfs(int x,int dep){
	mx=max(mx,d[x]=dep);
	for(int y:e[x])dfs(y,dep+1);
}
signed main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=2,x;i<=n;i++)
		cin>>x,e[x].push_back(i);
	dfs(1,0);
	for(int i=1;i<=n;i++){
		int t=(mx-d[i])&1,k=a[i];
		if(t)c++,f[k]++;
		else xs^=k,b.push_back(k);
	}
	if(!xs)ans=c*(c-1)/2+(n-c)*(n-c-1)/2;
	for(int x:b)ans+=f[x^xs];
	cout<<ans<<"\n";
}