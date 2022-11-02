#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
void read(int &digit)
{
	digit=0;
	char c;
	for (c=getchar();(c<'0' || c>'9') && c!='-';c=getchar());
	bool type=false;
	if (c=='-')
		type=true,c=getchar();
	for (;c>='0' && c<='9';digit=digit*10+c-'0',c=getchar());
	if (type==true)
		digit=-digit;
}
#define maxn 5010
const ll INF=1LL<<40;
int n,b;
vector<int> son[maxn];
ll f[maxn][maxn][2];
int size[maxn],fa[maxn];
ll tmp[maxn][2];
ll c[maxn],d[maxn];

void dfs(int t)
{
	size[t]=1;
	f[t][1][0]=f[t][1][1]=c[t];f[t][0][1]=INF;
	for (int _=0;_<son[t].size();_++)
	{
		int v=son[t][_];
		dfs(v);
		for (int i=0;i<=size[t]+size[v];i++)	tmp[i][0]=tmp[i][1]=INF;
		for (int i=0;i<=size[t];i++)
			for (int j=0;j<=size[v];j++)
			{
				tmp[i+j][1]=min(tmp[i+j][1],f[t][i][1]+f[v][j][1]-d[v]);
				tmp[i+j][1]=min(tmp[i+j][1],f[t][i][1]+f[v][j][0]);
				tmp[i+j][0]=min(tmp[i+j][0],f[t][i][0]+f[v][j][0]);
			}
		size[t]+=size[v];
		for (int i=0;i<=size[t];i++)	f[t][i][0]=tmp[i][0],f[t][i][1]=tmp[i][1];
	}
}
int main()
{
	read(n);read(b);
	scanf("%I64d%I64d",&c[1],&d[1]);
	for (int i=2;i<=n;i++)
	{
		scanf("%I64d%I64d",&c[i],&d[i]);read(fa[i]);
		son[fa[i]].push_back(i);
	}
	c[1]-=d[1];
	dfs(1);
	int ans=0;
	for (int i=n;i>=1;i--)
	if (b>=f[1][i][0] || b>=f[1][i][1])
	{
		ans=i;
		break;
	}
	printf("%d\n",ans);
	return 0;
}