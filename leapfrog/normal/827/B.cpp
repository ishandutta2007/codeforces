#include<bits/stdc++.h>
using namespace std;
int n,k,ans;
int main()
{
	scanf("%d%d",&n,&k),ans=(n-1)/k*2;
	if((n-1)%k==1) ans++;else if((n-1)%k) ans+=2;
	printf("%d\n",ans);
	for(int i=2;i<=k;i++) printf("1 %d\n",i);
	for(int i=k+1;i<=n;i++) printf("%d %d\n",i,i-k);
	return 0;
}