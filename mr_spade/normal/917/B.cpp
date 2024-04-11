#include<cstdio>
#include<cstring>
const int N=105;
int n,m;
char s[100];
int v[N*N],w[N*N],first[N],next[N*N];
int memo[N][N][30];
int f(int x,int y,int c)
{
	if(~memo[x][y][c])
		return memo[x][y][c];
	register int go;
	memo[x][y][c]=0;
	for(go=first[x];go;go=next[go])
		if(w[go]>=c)
			memo[x][y][c]|=!f(y,v[go],w[go]);
	return memo[x][y][c];
}
signed main()
{
	int u;
	register int i,j;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++)
	{
		scanf("%d%d%s",&u,&v[i],s);
		w[i]=s[0]-'a'+1;
		next[i]=first[u];first[u]=i;
	}
	memset(memo,-1,sizeof(memo));
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
			putchar(f(i,j,0)?'A':'B');
		putchar('\n');
	}
	return 0;
}