#include<bits/stdc++.h>
#define N 400010
using namespace std;
int a[N],nop[N],p[N],cnt;
void mem(int n)
{
	for (int i=2;i<=n;i++)
	{
		if (!nop[i]) p[++cnt]=i;
		for (int j=1;j<=cnt && i*p[j]<=n;j++)
		{
			nop[i*p[j]]=1;if (i%p[j]==0) break;
		}
	}
}
int main()
{
	int n,i,s=0,s1=0,s2=0,ans=0;mem(N-10);cin>>n;
	for (i=1;i<=n;i++) {cin>>a[i],s+=a[i];if (a[i]==1) s1++;else s2++;}
	if (!s1 || !s2) {for (i=1;i<=n;i++) cout<<a[i]<<' ';exit(0);}
	s2--;int nw=2;s1--;cout<<2<<' '<<1<<' ';
	while (s2) cout<<2<<' ',s2--;while (s1) cout<<1<<' ',s1--;
	
}