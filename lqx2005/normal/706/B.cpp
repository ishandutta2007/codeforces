#include<bits/stdc++.h>
using namespace std;
const int maxn=100000;
int x[maxn+5];
int n,m;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&x[i]);
	sort(x+1,x+n+1);
	scanf("%d",&m);
	int q;
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&q);
		int pos=upper_bound(x+1,x+n+1,q)-x;
		pos--;
		printf("%d\n",pos);
	}
	return 0;
}