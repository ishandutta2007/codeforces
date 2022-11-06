#include<bits/stdc++.h>
using namespace std;
#define re register
int a[110],b[110];
int main()
{
	re int n,ans=0;
	scanf("%d",&n);
	for(re int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(b[a[i]])i--,n--;
		else b[a[i]]=1;
	}
	for(re int i=1;i<=n;i++)
	{
		ans++;
		for(re int j=1;j<=n;j++)if(j!=i&&(!(a[i]%a[j]))){ans--;break;}
	}
	printf("%d\n",ans);
}