#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using std::min;
using std::vector;
const int N=3005;
int n,cur;
int a[N];
vector<int> V;
int bk[N];
inline void play(int x)
{
	register int i;
	memset(bk,0,sizeof(int)*(n+1));
	for(i=1;i<=n;i++)
		bk[a[i]]=1;
	for(i=0;bk[i];i++);
	a[x]=i;V.push_back(x);
	return;
}
inline void solve()
{
	int cur;
	register int i,j;
	scanf("%d",&n);V.clear();
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	cur=n;
	for(i=1;i<=2*n;i++)
	{
		memset(bk,0,sizeof(int)*(n+1));
		for(j=1;j<=n;j++)
			bk[a[j]]=1;
		for(j=0;bk[j];j++);
		if(j<cur)
			play(j+1);
		else
			play(cur),cur--;
		if(cur<=0)
			break;
	}
	printf("%d\n",(int)V.size());
	for(int x:V)
		printf("%d ",x);
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