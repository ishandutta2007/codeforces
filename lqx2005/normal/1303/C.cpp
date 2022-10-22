#include<bits/stdc++.h>
using namespace std;
const int maxn=40;
const int maxm=210;
int T,n;
int mp[maxn][maxn],deg[maxn];
char s[maxm];
int checkList()
{
	int ca=0,cb=0,cc=0;
	for(int i=0;i<=25;i++)
	{
		if(deg[i]==0) cc++;
		if(deg[i]==1) ca++;
		if(deg[i]==2) cb++;
	}
	if(ca==2&&ca+cb+cc==26) return 1;
	return 0;
}
void dfs(int u,int fa)
{
	printf("%c",(char)('a'+u));
	for(int i=0;i<=25;i++)
	{
		if(i==u) continue;
		if(i==fa) continue;
		if(!mp[u][i]) continue;
		dfs(i,u);
	}
	return;
}
signed main()
{
	scanf("%d",&T);
	for(int tt=1;tt<=T;tt++)
	{
		memset(deg,0,sizeof(deg));
		memset(mp,0,sizeof(mp));
		scanf("%s",s+1);
		n=strlen(s+1);
		for(int i=2;i<=n;i++)
		{
			mp[s[i]-'a'][s[i-1]-'a']=1;
			mp[s[i-1]-'a'][s[i]-'a']=1;
		}
		for(int i=0;i<=25;i++)
		{
			for(int j=0;j<=25;j++)
			{
				if(!mp[i][j]) continue;
				if(i==j) continue;
				deg[j]++;
			}
		}
		if(!checkList()&&n!=1)
		{
			printf("NO\n");
			continue;
		}
		printf("YES\n");
		for(int i=0;i<=25;i++)
		{
			if(deg[i]==1)
			{
				dfs(i,-1);
				break;
			}
		}
		for(int i=0;i<=25;i++)
		{
			if(deg[i]==0) printf("%c",(char)('a'+i));
		}
		printf("\n");
	}
	return 0;
}