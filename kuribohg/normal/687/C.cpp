#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
int n,K,c[510],f[2][510][510];
vector<int> ans;
int main()
{
	scanf("%d%d",&n,&K);
	for(int i=1;i<=n;i++) scanf("%d",&c[i]);
	f[0][0][0]=1;
	for(int i=1;i<=n;i++)
	{
		int cur=i&1,pre=cur^1;
		for(int j=0;j<=K;j++)
			for(int k=0;k<=K;k++)
			{
				f[cur][j][k]|=f[pre][j][k];
				if(j>=c[i]) f[cur][j][k]|=f[pre][j-c[i]][k];
				if(j>=c[i]&&k>=c[i]) f[cur][j][k]|=f[pre][j-c[i]][k-c[i]];
			}
	}
	for(int i=0;i<=K;i++)
		if(f[n&1][K][i]) ans.push_back(i);
	printf("%d\n",(int)ans.size());
	for(int i=0;i<ans.size();i++)
		printf("%d ",ans[i]);
	puts("");
	return 0;
}