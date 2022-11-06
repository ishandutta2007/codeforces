#include<cstdio>
#include<algorithm>
using std::swap;
const int N=1005,M=1e5+5;
int n,m;
int a[N][N],b[N][N];
int qa[3],qb[3],p[3],c[3];
char s[M];
inline void solve()
{
	register int i,j,k;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]),a[i][j]--;
	for(i=0;i<3;i++)
		p[i]=i,c[i]=0;
	scanf("%s",s+1);
	for(i=1;i<=m;i++)
		switch(s[i])
		{
			case 'U':c[0]=(c[0]+n-1)%n;break;
			case 'D':c[0]=(c[0]+1)%n;break;
			case 'R':c[1]=(c[1]+1)%n;break;
			case 'L':c[1]=(c[1]+n-1)%n;break;
			case 'I':swap(p[1],p[2]);swap(c[1],c[2]);break;
			case 'C':swap(p[0],p[2]);swap(c[0],c[2]);break;
			default:throw;
		}
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			qa[0]=i;qa[1]=j;qa[2]=a[i][j];
			for(k=0;k<3;k++)
				qb[k]=(qa[p[k]]+c[k])%n;
			b[qb[0]][qb[1]]=qb[2];
		}
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			printf("%d%c",b[i][j]+1,j==n-1?'\n':' ');
	putchar('\n');
	return;
}
signed main()
{
	int T;
	scanf("%d",&T);
	while(T--)
		solve();
	return 0;
}