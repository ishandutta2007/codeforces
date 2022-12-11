#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

struct ed{int v,c;};
vector<ed>g[300001];
int w[300001];
long long ans=-2e9;
long long dfs(int u,int f){
	vector<long long>s;
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i].v;
		if(v==f)continue;
		s.push_back(dfs(v,u)+g[u][i].c);
	}
	sort(s.begin(),s.end());
	if(s.size()>=2)
		ans=max(ans,w[u]+s[s.size()-1]+s[s.size()-2]);
	long long o=w[u]+max(0ll,s.size()==0?0:s[s.size()-1]);
	ans=max(ans,o);
	return o;
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&w[i]),ans=max(ans,1ll*w[i]);
	for(int i=1;i<n;i++){
		int u,v,c;
		scanf("%d%d%d",&u,&v,&c);
		g[u].push_back((ed){v,-c});
		g[v].push_back((ed){u,-c});
	}
	dfs(1,0);
	printf("%I64d\n",ans);
}