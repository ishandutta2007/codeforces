#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
int n,m,T,flg;
int dsu[maxn],ans[maxn],deg[maxn],vis[maxn];
vector<int>v[maxn],w[maxn];
vector< pair<int, pair<int,int> > >edg;
int find(int x){
	return dsu[x]==x? x:dsu[x]=find(dsu[x]);
}
void findedg(int x,int goal){
	vis[x]=1;
	for(int i=0;i<v[x].size();i++){
		int y=v[x][i];
		if(vis[y]==0&&ans[w[x][i]]==0){
			if(y==goal){
				ans[w[x][i]]=1,flg=1;
				return ;
			}
			else{
				findedg(y,goal);
				if(flg)
					return ;
			}
		}
	}
}
int main(){
	scanf("%d",&T);
	while(T--){
		edg.clear(),flg=0;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			dsu[i]=i;
		for(int i=1,x,y;i<=m;i++){
			scanf("%d%d",&x,&y),v[x].push_back(y),v[y].push_back(x),w[x].push_back(i),w[y].push_back(i);
			if(find(x)!=find(y))
				dsu[find(x)]=find(y);
			else edg.push_back(make_pair(i,make_pair(x,y))),deg[x]++,deg[y]++,ans[i]=1;
		}
		int huan=0;
		for(int i=1;i<=n;i++)
			huan+=deg[i]==2;
		if(huan==3){
			findedg(edg[0].second.first,edg[0].second.second);
			ans[edg[0].first]=0;
		}
		for(int i=1;i<=m;i++)
			printf("%d",ans[i]),ans[i]=0;
		puts("");
		for(int i=1;i<=n;i++)
			v[i].clear(),w[i].clear(),deg[i]=vis[i]=0;
	}
	return 0;
}