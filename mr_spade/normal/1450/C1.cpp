#include<cstdio>
#include<cstring>
#include<vector>
using std::vector;
const int N=305,inf=0x3f3f3f3f;
int n;
char s[N][N];
int cnt[N][3][3];
int dp[N][9][9],pre[N][9][9];
vector<int> V;
inline int no(char c)
{
	switch(c)
	{
		case '.':return 0;
		case 'X':return 1;
		case 'O':return 2;
	}
	return -1;
}
inline bool can(int x,int y)
{
	return x/3!=y&&x%3!=y;
}
inline int trans(int x,int y)
{
	return (x%3)*3+y;
}
inline int num(int x,int y)
{
	return x*100+y;
}
inline int fi(int x)
{
	return x/100;
}
inline int se(int x)
{
	return x%100;
}
void pr(int t,int x,int y)
{
	if(t==-1)
		return;
	register int i;
	for(i=0;i<n;i++)
		if(i%3==x%3&&s[t][i]=='O')
			s[t][i]='X';
	for(i=0;i<n;i++)
		if(i%3==y%3&&s[t][i]=='X')
			s[t][i]='O';
	pr(t-1,fi(pre[t][x][y]),se(pre[t][x][y]));
	return;
}
inline void solve()
{
	register int i,j,k;
	scanf("%d",&n);
	for(i=0;i<=n;i++)
	{
		memset(cnt[i],0,sizeof(cnt[i]));
		memset(dp[i],0x3f,sizeof(dp[i]));
		memset(pre[i],0x3f,sizeof(pre[i]));
	}
	for(i=0;i<n;i++)
	{
		scanf("%s",s[i]);
		for(j=0;j<n;j++)
			cnt[i][j%3][no(s[i][j])]++;
	}
	for(int x:V)
		for(int y:V)
		{
			for(j=0;j<3;j++)
				if(can(x,j))
					for(k=0;k<3;k++)
						if(j!=k&&can(y,k))
						{
							if(dp[0][trans(x,j)][trans(y,k)]>cnt[0][j][2]+cnt[0][k][1])
							{
								dp[0][trans(x,j)][trans(y,k)]=cnt[0][j][2]+cnt[0][k][1];
								pre[0][trans(x,j)][trans(y,k)]=num(x,y);
							}
						}
		}
	for(i=0;i<n-1;i++)
		for(int x:V)
			for(int y:V)
			{
				for(j=0;j<3;j++)
					if(can(x,j))
						for(k=0;k<3;k++)
							if(j!=k&&can(y,k))
							{
								if(dp[i+1][trans(x,j)][trans(y,k)]>dp[i][x][y]+cnt[i+1][j][2]+cnt[i+1][k][1])
								{
									dp[i+1][trans(x,j)][trans(y,k)]=dp[i][x][y]+cnt[i+1][j][2]+cnt[i+1][k][1];
									pre[i+1][trans(x,j)][trans(y,k)]=num(x,y);
								}
							}
			}
	int ans=0;
	for(int x:V)
		for(int y:V)
			if(!ans||dp[n-1][x][y]<dp[n-1][fi(ans)][se(ans)])
				ans=num(x,y);
	pr(n-1,fi(ans),se(ans));
	for(i=0;i<n;i++)
		printf("%s\n",s[i]);
	return;
}
signed main()
{
	int T;
	register int i,j;
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			if(i!=j)
				V.push_back(i*3+j);
	scanf("%d",&T);
	while(T--)
		solve();
	return 0;
}