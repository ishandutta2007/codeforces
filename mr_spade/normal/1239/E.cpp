#include<cstdio>
#include<algorithm>
using std::max;
using std::min;
using std::sort;
const int N=30,M=5e4+5;
int n,sum,pos;
int b[N<<1],bk[N<<1];
int dp[N][N*M],lst[N][N*M];
void print(int cnt,int sum)
{
	if(cnt==0)
		return;
	print(cnt-1,sum-b[lst[cnt][sum]]);
	bk[lst[cnt][sum]]=1;
	printf("%d ",b[lst[cnt][sum]]);
	return;
}
signed main()
{
	register int i,j,k;
	scanf("%d",&n);
	for(i=1;i<=2*n;i++)
		scanf("%d",&b[i]),sum+=b[i];
	sort(b+1,b+2*n+1);sum-=b[1]+b[2];
	dp[0][0]=1;
	for(i=3;i<=2*n;i++)
		for(k=min(n-1,i-2);k>0;k--)
			for(j=sum;j>=b[i];j--)
				if(!dp[k][j]&&dp[k-1][j-b[i]])
					dp[k][j]=1,lst[k][j]=i;
	for(i=1;i<=sum;i++)
		if(dp[n-1][i]&&max(sum-i,i)<=max(sum-pos,pos))
			pos=i;
	printf("%d ",b[1]);
	print(n-1,pos);
	putchar('\n');
	for(i=2*n;i>=3;i--)
		if(!bk[i])
			printf("%d ",b[i]);
	printf("%d\n",b[2]);
	return 0;
}