#include <iostream>
using namespace std;
int g[200005],ans[200005],arr[100005];
void go(int x,int c)
{
	if (ans[x])
	return;
	ans[x]=c+1;
	if (g[x])
	go(g[x],!c);
	go(x+(x%2? 1:-1),!c);
}
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		int a,b;
		scanf ("%d%d",&a,&b);
		g[a]=b;
		g[b]=a;
		arr[i]=a;
	}
	for (int i=1;i<=2*n;i++)
	{
		if (!ans[i])
		go(i,0);
	}
	for (int i=0;i<n;i++)
	printf("%d %d\n",ans[arr[i]],ans[g[arr[i]]]);
}