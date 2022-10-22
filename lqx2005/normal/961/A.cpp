#include<bits/stdc++.h>
using namespace std;
const int maxn=1000;
int n,m;
int a[maxn+5];
int main()
{
	scanf("%d%d",&n,&m);
	int col;
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&col);
		a[col]++;
	}
	int ans=maxn;
	for(int i=1;i<=n;i++) ans=min(ans,a[i]);
	printf("%d\n",ans);
	return 0;
}