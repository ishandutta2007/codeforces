#include<bits/stdc++.h>
using namespace std;
const int maxn=1000;
int n,m;
int a[maxn+5],b[maxn+5];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=m;i++) scanf("%d",&b[i]);
	int now=1,ans=0;
	for(int i=1;i<=n;i++) if(b[now]>=a[i]) ans++,now++;
	printf("%d\n",ans);
	return 0;
}