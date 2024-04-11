#include<cstdio>
#include<vector>
using namespace std;

vector<int>g[300001];
int ans[300001];
int main(){
	int t;
	scanf("%d",&t);
	for(int tt=1;tt<=t;tt++){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			g[i].clear();
			ans[i]=2e9;
		}
		for(int i=1;i<=n;i++){
			int z;
			scanf("%d",&z);
			g[z].push_back(i);
		}
		for(int i=1;i<=n;i++){
			int s=-1;
			if(g[i].size()!=0)
				s=max(g[i][0]-1,n-g[i][g[i].size()-1])+1;
			for(int j=0;j+1<g[i].size();j++)
				s=max(s,g[i][j+1]-g[i][j]);
			ans[s]=min(ans[s],i);
		}
		for(int i=2;i<=n;i++)
			ans[i]=min(ans[i],ans[i-1]);
		for(int i=1;i<=n;i++)
			printf("%d%c",ans[i]==2e9?-1:ans[i],i==n?'\n':' ');
	}
}