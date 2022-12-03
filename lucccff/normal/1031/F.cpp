#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
const int N=1e6;
int q,cnta,cntb;
int vis[1000010];
int id[1000010];
int pri[7]={2,3,5,7,11,13,17};
int a[1000010],b[1000010];
int dis[310][910],ans[310][310];
vector<int>f[1000010];
void dfs(int t,int v,int x,int y,int cnt1,int cnt2){
	if (!a[x]) a[x]=++cnta;
	if (!b[y]) b[y]=++cntb;
	if (dis[a[x]][b[y]]<=v)return;
	if (t==7){
		dis[a[x]][b[y]]=v;
		return;
	}
	for (int i=0;i<=cnt1;i++)
		if (x<=N)
		{
			for (int j=0;j<=cnt2;j++)
				if (v+abs(i-j)<=10) dfs(t+1,v+abs(i-j),x,y*(j+1),i,j);
			x*=pri[t];
		}
}
int main(){
	for (int i=2;i<=N;i++)
	{
		if (vis[i]) continue;
		for(int j=i;j<=N;j+=i)
		{
			int t=j,c=0;
			vis[j]=1;
			while (t%i==0)t/=i,c++;
			f[j].push_back(c);
		}
	}
	for (int i=1;i<=N;i++)
	{
		sort(f[i].begin(),f[i].end());
		reverse(f[i].begin(),f[i].end());
		id[i]=1;
		for (int j=0;j<(int)f[i].size();j++)
			for (int k=0;k<f[i][j];k++)
				id[i]*=pri[j];
	}
	memset(dis,63,sizeof(dis));
	dfs(0,0,1,1,20,20);
	scanf("%d",&q);
	while (q--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		x=a[id[x]];
		y=a[id[y]];
		if (x>y) swap(x,y);
		if (x==y||ans[x][y])
		{
			printf("%d\n",ans[x][y]);
			continue;
		}
		ans[x][y]=100;
		for (int i=1;i<=cntb;i++)ans[x][y]=min(ans[x][y],dis[x][i]+dis[y][i]);
		printf("%d\n",ans[x][y]);
	}
	return 0;
}