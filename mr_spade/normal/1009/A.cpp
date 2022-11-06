#include<cstdio>
#include<queue>
using std::queue;
const int N=1005;
int n,m,ans;
int c[N];
queue<int> Q;
signed main()
{
	int x;
	register int i;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		scanf("%d",&c[i]);
	for(i=1;i<=m;i++)
	{
		scanf("%d",&x);
		Q.push(x);
	}
	for(i=1;i<=n;i++)
		if(Q.size()&&Q.front()>=c[i])
			ans++,Q.pop();
	printf("%d\n",ans);
	return 0;
}