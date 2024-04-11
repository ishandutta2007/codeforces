#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,sum,se;
int a[N],bk[N],vis[N];
vector<int> gg[N];
int e[N];
inline int re(int x)
{
	if(x<=n)
		x+=n;
	else
		x-=n;
	return x;
}
inline void run(int x)
{
	int m=1,y;
	vis[x]=vis[re(x)]=1;
	bk[x]=1;(sum+=x)%=2*n;
	y=e[x];
	while((y-1)%n+1!=x)
	{
		m++;vis[y]=vis[re(y)]=1;y=re(y);
		bk[y]=1;(sum+=y)%=2*n;
		y=e[y];
	}
	if(m&1)
		se=x;
	return;
}
inline void flip(int x)
{
	int y;
	bk[x]^=1;bk[re(x)]^=1;
	y=e[x];
	while((y-1)%n+1!=x)
	{
		y=re(y);
		bk[y]^=1;bk[re(y)]^=1;
		y=e[y];
	}
	return;
}
signed main()
{
	int t,_;
	register int i;
	scanf("%d",&n);
	if(n&1)
	{
		printf("Second\n");fflush(stdout);
		for(i=1;i<=2*n;i++)
			scanf("%d",&a[i]),gg[a[i]].push_back(i);
		for(i=1;i<=n;i++)
			e[gg[i][0]]=gg[i][1],e[gg[i][1]]=gg[i][0];
		for(i=1;i<=n;i++)
			if(!vis[i])
				run(i);
		if(sum)
			flip(se);
		for(i=1;i<=2*n;i++)
			if(bk[i])
				printf("%d ",i);
		puts("");fflush(stdout);
	}
	else
	{
		printf("First\n");fflush(stdout);
		for(i=1;i<=n;i++)
			printf("%d ",i);
		for(i=1;i<=n;i++)
			printf("%d ",i);
		printf("\n");fflush(stdout);
	}
	return scanf("%d",&_),_;
}