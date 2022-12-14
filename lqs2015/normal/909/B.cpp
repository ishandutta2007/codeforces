#include<bits/stdc++.h>
using namespace std;
int n,ans;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) ans=max(ans,i*(n-i+1));
	printf("%d\n",ans);
	return 0;
}