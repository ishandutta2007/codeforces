#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool nop[100010];int p[10010],cnt;
void init()
{
	for (int i=2;i<=100000;i++)
	{
		if (!nop[i]) p[++cnt]=i;
		for (int j=1;j<=cnt && i*p[j]<=100000;j++)
		{
			nop[i*p[j]]=1;
			if (i%p[j]==0) break;
		}
	}
}
int a[1111];
int main()
{
	int T;cin>>T;init();
	while (T--)
	{
		int n,i,j,k,s=0;cin>>n;
		for (i=1;i<=n;i++) scanf("%d",&a[i]),s+=a[i];
		if (nop[s])
		{
			cout<<n<<endl;
			for (i=1;i<=n;i++) cout<<i<<' ';puts("");
			continue;
		}
		int tp=1;
		for (i=1;i<=n && tp;i++) if (nop[s-a[i]])
		{
			tp=0;
			cout<<n-1<<endl;
			for (j=1;j<=n;j++) if (j!=i)cout<<j<<' ';puts("");
		}
		for (i=1;i<=n && tp;i++) for (j=i+1;j<=n && tp;j++) if (nop[s-a[i]-a[j]])
		{
			tp=0;
			cout<<n-2<<endl;
			for (k=1;k<=n;k++) if (k!=i && k!=j)cout<<k<<' ';puts("");
		}
	}
}