#include <iostream>
using namespace std;
int cnt[30005],d;
int m[30005][700],vis[30005][700];
int solve(int idx,int l)
{
	if (l<=0 || idx>30000)
	return 0;
	int ll=l-d+300;
	if (vis[idx][ll])
	return m[idx][ll];
	vis[idx][ll]=1;
	return m[idx][ll]=cnt[idx]+max(solve(idx+l-1,l-1),max(solve(idx+l,l),solve(idx+l+1,l+1)));
}
int main()
{
	int n;
	scanf("%d%d",&n,&d);
	while (n--)
	{
		int a;
		scanf("%d",&a);
		cnt[a]++;
	}
	printf("%d",solve(d,d));
}