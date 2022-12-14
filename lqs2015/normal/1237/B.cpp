#include<bits/stdc++.h>
using namespace std;
int n,a[111111],b[111111],pos[111111],mx,ans;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) scanf("%d",&b[i]);
	for (int i=1;i<=n;i++) pos[b[i]]=i;
	mx=-1;
	for (int i=1;i<=n;i++)
	{
		if (mx>pos[a[i]]) ans++;
		mx=max(mx,pos[a[i]]);
	}
	printf("%d\n",ans);
	return 0;
}