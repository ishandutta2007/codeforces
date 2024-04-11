#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<deque>
#include<queue>
using std::vector;
using std::queue;
using std::deque;
const int N=5e5+5;
int n,m;
int deg[N],dis[N];
vector<int> e[N],e2[N];
int biu;
int pre[N],bk[N],vis[N];
int dp[N][3][3][3];
int *sbfi[N][3][3][3],*sbnxt[N][3][3][3];
int spa[2][3],tpa[2][3];
int *epcfi[2][3],*epcnxt[2][3];
int *tepcfi[2][3],*tepcnxt[2][3];
queue<int> Q;
deque<int> dQ;
//inline void clear()
//{
//	register int i;
//	memset(deg+1,0,sizeof(int)*n);
//	memset(dis+1,0,sizeof(int)*n);
//	for(i=1;i<=n;i++)
//		e[i].clear(),e2[i].clear();
//	biu=0;
//	for(i=1;i<=n;i++)
//		pre[i]=bk[i]=vis[i]=0,memset(dp[i],0,sizeof(dp[i])),memset(sbfi[i],0,sizeof(sbfi[i])),memset(sbnxt[i],0,sizeof(sbnxt[i]));
//	while(!Q.empty())
//		Q.pop();
//	memset(spa,0,sizeof(spa));
//	memset(tpa,0,sizeof(tpa));
//	memset(epcfi,0,sizeof(epcfi));
//	memset(epcnxt,0,sizeof(epcnxt));
//	memset(tepcfi,0,sizeof(tepcfi));
//	memset(tepcnxt,0,sizeof(tepcnxt));
//	return;
//}
inline int find(int x)
{
	return dis[x]==x?x:(dis[x]=find(dis[x]));
}
void load(int x)
{
	if(!x)
		return;
	load(pre[x]);bk[x]=1;
	return;
}
void dfs1(int x,int tar)
{
	if(vis[x])
		return;
	vis[x]=1;
	for(int y:e[x])
		if(deg[y]%3==2)
		{
			dfs1(y,tar);
			if(biu)
			{
				bk[x]=1;
				dQ.push_front(x);
				return;
			}
		}
		else if(y==tar)
		{
			biu=1;bk[x]=1;dQ.push_front(x);return;
		}
	return;
}
int tmp[3][3][3];
int *tsbfi[3][3][3],*tsbnxt[3][3][3];
void dfs2(int x,int father)
{
	register int i,j,k,i2,j2,k2;
	dp[x][0][0][0]=1;sbfi[x][0][0][0]=sbnxt[x][0][0][0]=NULL;
	if(vis[x])
		dp[x][2][1][1]=1,sbfi[x][2][1][1]=sbnxt[x][2][1][1]=NULL;
	else
		dp[x][2][0][0]=1,sbfi[x][2][0][0]=sbnxt[x][2][0][0]=NULL;
	for(int y:e[x])
		if(deg[y]%3==2&&y!=father)
		{
			dfs2(y,x);
			memset(tmp,0,sizeof(tmp));
			memset(tsbfi,NULL,sizeof(tsbfi));
			memset(tsbnxt,NULL,sizeof(tsbnxt));
			for(k=0;k<3;k++)
				if(dp[x][0][0][k])
				{
					for(k2=0;k2<3;k2++)
						if(dp[y][0][0][k2])
						{
							tmp[0][0][(k+k2)%3]=1;
							tsbfi[0][0][(k+k2)%3]=&dp[y][0][0][k2];
							tsbnxt[0][0][(k+k2)%3]=&dp[x][0][0][k];
						}
					for(i2=1;i2<3;i2++)
						for(k2=0;k2<3;k2++)
							if(dp[y][i2][2][k2])
							{
								tmp[0][0][(k+k2)%3]=1;
								tsbfi[0][0][(k+k2)%3]=&dp[y][i2][2][k2];
								tsbnxt[0][0][(k+k2)%3]=&dp[x][0][0][k];
							}
				}
			for(i=1;i<3;i++)
				for(j=0;j<3;j++)
					for(k=0;k<3;k++)
						if(dp[x][i][j][k])
						{
							for(k2=0;k2<3;k2++)
								if(dp[y][0][0][k2])
								{
									tmp[1][j][(k+k2)%3]=1;
									tsbfi[1][j][(k+k2)%3]=&dp[y][0][0][k2];
									tsbnxt[1][j][(k+k2)%3]=&dp[x][i][j][k];
								}
							for(i2=1;i2<3;i2++)
								for(k2=0;k2<3;k2++)
								{
									if(dp[y][i2][1][k2])
									{
										tmp[(i==2&&i2==2)?2:1][(j+1)%3][(k+k2)%3]=1;
										tsbfi[(i==2&&i2==2)?2:1][(j+1)%3][(k+k2)%3]=&dp[y][i2][1][k2];
										tsbnxt[(i==2&&i2==2)?2:1][(j+1)%3][(k+k2)%3]=&dp[x][i][j][k];
									}
//									if(dp[y][i2][2][k2])
//									{
//										tmp[(i==2&&i2==2)?2:1][j][(k+k2)%3]=1;
//										tsbfi[(i==2&&i2==2)?2:1][j][(k+k2)%3]=&dp[y][i2][2][k2];
//										tsbnxt[(i==2&&i2==2)?2:1][j][(k+k2)%3]=&dp[x][i][j][k];
//										
//									}
								}
						}
			for(i=0;i<3;i++)
				for(j=0;j<3;j++)
					for(k=0;k<3;k++)
						if(!dp[x][i][j][k]&&tmp[i][j][k])
						{
							dp[x][i][j][k]=1;
							sbfi[x][i][j][k]=tsbfi[i][j][k];
							sbnxt[x][i][j][k]=tsbnxt[i][j][k];
						}
		}
	return;
}
inline void work(int x)
{
	register int i,j,k,i2,k2;
	memset(tpa,0,sizeof(tpa));
	memset(tepcfi,0,sizeof(tepcfi));
	memset(tepcnxt,0,sizeof(tepcnxt));
	
	for(k=0;k<3;k++)
		if(dp[x][1][2][k])
		{
			for(k2=0;k2<3;k2++)
			{
				if(spa[0][k2])
				{
					tpa[0][(k+k2)%3]=1;
					tepcfi[0][(k+k2)%3]=&dp[x][1][2][k];
					tepcnxt[0][(k+k2)%3]=&spa[0][k2];
				}
				if(spa[1][k2])
				{
					tpa[0][(k+k2)%3]=1;
					tepcfi[0][(k+k2)%3]=&dp[x][1][2][k];
					tepcnxt[0][(k+k2)%3]=&spa[1][k2];
				}
			}
		}
	for(k=0;k<3;k++)
		if(dp[x][0][0][k])
		{
			for(k2=0;k2<3;k2++)
			{
				if(spa[0][k2])
				{
					tpa[0][(k+k2)%3]=1;
					tepcfi[0][(k+k2)%3]=&dp[x][0][0][k];
					tepcnxt[0][(k+k2)%3]=&spa[0][k2];
				}
				if(spa[1][k2])
				{
					tpa[0][(k+k2)%3]=1;
					tepcfi[0][(k+k2)%3]=&dp[x][0][0][k];
					tepcnxt[0][(k+k2)%3]=&spa[1][k2];
				}
			}
		}
	for(k=0;k<3;k++)
		if(dp[x][2][2][k])
		{
			for(k2=0;k2<3;k2++)
			{
				if(spa[0][k2])
				{
					tpa[0][(k+k2)%3]=1;
					tepcfi[0][(k+k2)%3]=&dp[x][2][2][k];
					tepcnxt[0][(k+k2)%3]=&spa[0][k2];
				}
				if(spa[1][k2])
				{
					tpa[1][(k+k2)%3]=1;
					tepcfi[1][(k+k2)%3]=&dp[x][2][2][k];
					tepcnxt[1][(k+k2)%3]=&spa[1][k2];
				}
			}
		}
	for(i=0;i<2;i++)
		for(k=0;k<3;k++)
			if(!spa[i][k]&&tpa[i][k])
			{
				spa[i][k]=1;
				epcfi[i][k]=tepcfi[i][k];
				epcnxt[i][k]=tepcnxt[i][k];
			}
	return;
}
int sb;int dep[N];
void dfs3(int x,int father,int deep,int tar)
{
	int bkk=0,xx=0;
	vis[x]=1;pre[x]=father;dep[x]=deep;
	for(int y:e[x])
		if(deg[y]%3==2&&y!=father)
		{
			if(vis[y])
				bkk=1,xx=((xx==0||dep[y]>dep[xx])?y:xx);
		}
	if(bkk)
	{
		if(dep[xx]==1&&deep==n)
			sb=2;
		else
			sb=1;
		for(int z=x;z!=xx;z=pre[z])
			bk[z]=1;
		bk[xx]=1;
		return;
	}
	for(int y:e[x])
		if(deg[y]%3==2&&y!=father)
		{
			if(!vis[y])
			{
				dfs3(y,x,deep+1,tar);
				if(sb)
					return;
			}
		}
	return;
}
inline int getfi(int *a,int *b)
{
	return (int)(b-a)/27;
}
inline int getse(int *a,int *b)
{
	return ((int)(b-a)-getfi(a,b)*27)/9;
}
void printepc(int *a)
{
	if(a==NULL)
		return;
	if(getse(&dp[0][0][0][0],a)!=0)
		bk[getfi(&dp[0][0][0][0],a)]=1;
	printepc(*(&sbnxt[0][0][0][0]+(int)(a-&dp[0][0][0][0])));
	printepc(*(&sbfi[0][0][0][0]+(int)(a-&dp[0][0][0][0])));
	return;
}
void printsb(int *a)
{
	if(a==NULL)
		return;
	printsb(*(&epcnxt[0][0]+(int)(a-&spa[0][0])));
	printepc(*(&epcfi[0][0]+(int)(a-&spa[0][0])));
	return;
}
int sa;
inline void solve()
{
	int x,y;
	register int i,j,k;
	dQ.clear();
	scanf("%d%d",&n,&m);
	memset(deg+1,0,sizeof(int)*n);
	for(i=1;i<=n;i++)
		e[i].clear(),e2[i].clear();
	int Mr=0;
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);deg[x]++;deg[y]++;
		e[x].push_back(y);
		e[y].push_back(x);
		if(i>=10&&i<=13)
		{
			Mr=Mr*10+x;
		Mr=Mr*10+y;
		}
	}
	if(n==1)
		return puts("No"),void();
	for(i=1;i<=n;i++)
		if(deg[i]%3==0)
		{
			puts("Yes");
			printf("%d\n",n-1);
			for(j=1;j<=n;j++)
				if(i!=j)
					printf("%d ",j);
			putchar('\n');
			return;
		}
	if(n==2)
		return puts("No"),void();
	int fl1=1;
	for(i=1;i<=n;i++)
		if(deg[i]%3==1)
		{
			fl1=0;
			for(int j:e[i])
				if(deg[j]%3==1)
				{
					puts("Yes");
					printf("%d\n",n-2);
					for(k=1;k<=n;k++)
						if(k!=i&&k!=j)
							printf("%d ",k);
					putchar('\n');
					return;
				}
		}
	for(i=1;i<=n;i++)
		if(deg[i]%3==2&&deg[i]>2)
			fl1=0;
	int cir=0,size=0,cirx;
	for(i=1;i<=n;i++)
		dis[i]=i,size+=(deg[i]%3==2);
	sb=0;
	memset(bk+1,0,sizeof(int)*n);
	memset(pre+1,0,sizeof(int)*n);
	memset(vis+1,0,sizeof(int)*n);
	memset(dep+1,0,sizeof(int)*n);
	for(i=1;i<=n;i++)
		if(deg[i]%3==2)
			for(int j:e[i])
				if(i<j&&deg[j]%3==2)
				{
					if(find(i)==find(j))
					{
						cir=1;sb=0;
						dfs3(i,0,1,i);
						if(sb==1)
						{
							int cnt=0;
							for(i=1;i<=n;i++)
								if(!bk[i])
									cnt++;
							printf("Yes\n");
							printf("%d\n",cnt);
							for(i=1;i<=n;i++)
								if(!bk[i])
									printf("%d ",i);
							putchar('\n');
							return;
						}
					}
					else
						e2[i].push_back(j),e2[j].push_back(i),dis[find(i)]=find(j),size--;
				}
	if(sb==2)
	{
		
//		if(sa==65)
//			throw;
		return puts("No"),void();
	}
	memset(bk+1,0,sizeof(int)*n);
	memset(pre+1,0,sizeof(int)*n);
	memset(vis+1,0,sizeof(int)*n);
	memset(spa,0,sizeof(spa));
	memset(epcfi,NULL,sizeof(epcfi));
	memset(epcnxt,NULL,sizeof(epcnxt));
	spa[1][0]=1;
	fl1=1;
	for(i=1;i<=n;i++)
		if(deg[i]%3==2)
			fl1&=(deg[i]==2);
	int cnt=0;
	for(i=1;i<=n;i++)
		if(deg[i]%3==1)
			cnt++,fl1&=(deg[i]==1);
	fl1&=(cnt==2);
	if(fl1)
	{
		return puts("No"),void();
	}
	for(i=1;i<=n;i++)
		if(deg[i]%3==1)
			for(int j:e[i])
				if(deg[j]%3==2)
				{
					if(pre[find(j)]&&pre[find(j)]!=i)
					{
						biu=0;
						
//							if(sa==485)
//								throw;
//						for(int x:e[pre[find(j)]])
//							if(deg[x]%3==2)
//							{
//								dfs1(x,i);
//								if(biu)
//									break;
//							}
						dfs1(j,pre[find(j)]);
						if(!biu)
							throw;
						bk[pre[find(j)]]=1;bk[i]=1;
						for(int ii=0;ii<(int)dQ.size();ii++)
						{
							x=dQ[ii];
							for(int y:e[x])
								if(y==i&&ii>0)
								{
									for(k=0;k<ii;k++)
										bk[dQ.front()]=0,dQ.pop_front();
									ii=-1;
									goto end;
								}
								else if(y==pre[find(j)]&&ii<(int)dQ.size()-1)
								{
									int t=(int)dQ.size()-1-ii;
									for(k=0;k<t;k++)
										bk[dQ.back()]=0,dQ.pop_back();
									ii--;
									goto end;
								}
							end:;
						}
						cnt=0;
						for(i=1;i<=n;i++)
							if(!bk[i])
								cnt++;
						printf("Yes\n");
						printf("%d\n",cnt);
						for(i=1;i<=n;i++)
							if(!bk[i])
								printf("%d ",i);
						putchar('\n');
						return;
					}
					pre[find(j)]=i;
				}
	memset(bk+1,0,sizeof(int)*n);
	memset(vis+1,0,sizeof(int)*n);
	for(i=1;i<=n;i++)
		if(deg[i]%3==1)
			for(int j:e[i])
				vis[j]=1;
	for(i=1;i<=n;i++)
		memset(dp[i],0,sizeof(dp[i]));
	for(i=1;i<=n;i++)
		if(deg[i]%3==2&&dis[i]==i&&pre[i])
		{
			dfs2(i,0);
			work(i);
		}
	if(spa[0][1])
	{
		puts("Yes");
		printsb(&spa[0][1]);
		for(i=1;i<=n;i++)
			if(deg[i]%3==1)
				bk[i]=1;
		cnt=0;
		for(i=1;i<=n;i++)
			if(!bk[i])
				cnt++;
		printf("%d\n",cnt);
		for(i=1;i<=n;i++)
			if(!bk[i])
				printf("%d ",i);
		putchar('\n');
		return;
	}
	else
	{
		puts("No");
	}
	return;
}
signed main()
{
	int T;
	register int i;
	scanf("%d",&T);
	for(i=1;i<=T;i++)
		sa=i,solve();
	return 0;
}