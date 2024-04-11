#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=233333;
int t,n,ans,cnt[N];
vector<int>e[N];
string s;
void dfs(int x){
	cnt[x]=s[x]=='W'?-1:1;
	for(int y:e[x])
		dfs(y),cnt[x]+=cnt[y];
	ans+=!cnt[x];
}
signed main(){
	ios::sync_with_stdio(0);
	for(cin>>t;t--;){
		cin>>n;
		for(int i=1;i<=n;i++)
			e[i].clear();
		for(int i=2,x;i<=n;i++)
			cin>>x,e[x].push_back(i);
		cin>>s,s=" "+s;
		ans=0,dfs(1);
		cout<<ans<<"\n";
	}
	return 0;
}