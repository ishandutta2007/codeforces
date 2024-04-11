#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
int n,m,fa[100010],in1,in2,p;
bool used[100010];
long long ans;
int find(int x){return (fa[x]==x)?x:(fa[x]=find(fa[x]));}
inline void uni(int i,int j){fa[find(i)]=find(j);}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&in1,&in2);
		uni(in1,in2);
	}
	for(int i=1;i<=n;i++) used[find(i)]=true;
	for(int i=1;i<=n;i++) if(used[i]) p++;
	ans=1LL<<(n-p);
	printf("%I64d\n",ans);
	return 0;
}