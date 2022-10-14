#include<bits/stdc++.h>
using namespace std;
int const N=23333;
int tot,ans1,ans2,sz[N],cnt[N];
string s;
vector<int>e[N];
map<string,int>ord;
int getord(const string&s){
	return ord[s]?ord[s]:ord[s]=++tot;
}
void solve(int x){
	sz[x]=!!e[x].size(),cnt[x]=!e[x].size();
	sort(e[x].begin(),e[x].end());
	e[x].erase(unique(e[x].begin(),e[x].end()),e[x].end());
	for(int y:e[x])
		solve(y),sz[x]+=sz[y],cnt[x]+=cnt[y];
	if(x)ans1=max(ans1,sz[x]-1),ans2=max(ans2,cnt[x]);
}
int main(){
	ios::sync_with_stdio(0);
	while(cin>>s){
		int pre=0,t=s.size();
		for(int i=3;i<=t;i++)
			if(i==t||s[i]=='\\'){
				int x=getord(s.substr(0,i));
				e[pre].push_back(x),pre=x;
			}
	}
	solve(0);
	cout<<ans1<<" "<<ans2<<"\n";
}