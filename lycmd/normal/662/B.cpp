#include<bits/stdc++.h>
using namespace std;
int const N=233333;
int n,m,x,y,cnt,res[2],c[N],vis[N];
char w;
vector<int>p,ans[2];
vector<pair<int,int> >e[N];
void dfs(int x,int col){
	cnt+=c[x],vis[x]=1,p.push_back(x);
	for(auto i:e[x]){
		int y=i.first,w=i.second^col;
		if(!vis[y])
			c[y]=c[x]^w,dfs(y,col);
		else if(c[y]^c[x]^w)
			res[col]=0;
	}
}
int main(){
	ios::sync_with_stdio(0);
	for(cin>>n>>m;m--;){
		cin>>x>>y>>w;
		e[x].push_back({y,w=='B'});
		e[y].push_back({x,w=='B'});
	}
	for(int i=0;i<2;i++){
		memset(c,0,sizeof c);
		memset(vis,0,sizeof vis),res[i]=1;
		for(int j=1;j<=n;j++)
			if(!vis[j]){
				p.clear(),cnt=0,dfs(j,i);
				for(int x:p)
					if(c[x]==(cnt*2<p.size()))
						ans[i].push_back(x);
			}
	}
	if(!res[0]&&!res[1])
		cout<<"-1\n",exit(0);
	int t=res[1]&&(!res[0]||ans[1].size()<ans[0].size());
	sort(ans[t].begin(),ans[t].end());
	cout<<ans[t].size()<<"\n";
	for(int i:ans[t])
		cout<<i<<" ";
	cout<<"\n";
}