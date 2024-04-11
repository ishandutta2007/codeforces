#include<stdio.h>
#include<map>
#include<vector>
using namespace std;
const int maxn=200005;
int n,ans,tot;
int a[maxn],idx[maxn],sz[maxn],iptson[maxn],dis[maxn];
vector<int>v[maxn];
map<int,int>mp[maxn];
void dfs1(int x,int last){
	sz[x]=1;
	for(int i=0;i<v[x].size();i++)
		if(v[x][i]!=last){
			dis[v[x][i]]=dis[x]^a[v[x][i]],dfs1(v[x][i],x),sz[x]+=sz[v[x][i]];
			if(sz[v[x][i]]>sz[iptson[x]])
				iptson[x]=v[x][i];
		}
}
void dfs2(int x,int last){
	if(iptson[x]==0){
		idx[x]=++tot,mp[tot][dis[x]]=1;
		return ;
	}
	dfs2(iptson[x],x),idx[x]=idx[iptson[x]];
	int flg=0;
	for(int i=0;i<v[x].size();i++)
		if(v[x][i]!=last&&v[x][i]!=iptson[x]){
			int y=v[x][i];
			dfs2(y,x);
			for(map<int,int>::iterator it=mp[idx[y]].begin();it!=mp[idx[y]].end();it++)
				if(mp[idx[x]].count((it->first)^a[x])){
					flg=1;
					break;
				}
			for(map<int,int>::iterator it=mp[idx[y]].begin();it!=mp[idx[y]].end();it++)
				mp[idx[x]][it->first]=1;
		}
	if(mp[idx[x]].count(dis[x]^a[x]))
		flg=1;
	else mp[idx[x]][dis[x]]=1;
	if(flg)
		mp[idx[x]].clear(),ans++;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1,x,y;i<n;i++)
		scanf("%d%d",&x,&y),v[x].push_back(y),v[y].push_back(x);
	dis[1]=a[1],dfs1(1,0),dfs2(1,0);
	printf("%d\n",ans);
	return 0;
}