#include<bits/stdc++.h>
using namespace std;
int const N=233333;
int t,cur,n[N];
char c[N];
vector<int>p[N],e[N];
map<int,int>cnt,pre;
void dfs(int x,int col){
	c[x]=col;
	for(int y:e[x])
		if(!c[y])dfs(y,col^30);
}
int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n[i],p[i].resize(n[i]);
		for(int&x:p[i])
			cin>>x,cnt[x]++;
	}
	for(auto i:cnt)
		if(i.second&1)
			cout<<"NO\n",exit(0);
	cnt.clear();
	cout<<"YES\n";
	for(int i=1;i<=t;i++)
		for(int j=0;j<n[i];j++){
			int o=++cur,x=p[i][j];
			if(j&1)
				e[o].push_back(o-1),
				e[o-1].push_back(o);
			if(cnt[x]&1)
				e[o].push_back(pre[x]),
				e[pre[x]].push_back(o);
			cnt[x]++,pre[x]=o;
		}
	for(int i=1;i<=cur;i++)
		if(!c[i])dfs(i,76);
	for(int i=1,cur=0;i<=t;i++,cout<<"\n")
		while(n[i]--)cout<<c[++cur];
}