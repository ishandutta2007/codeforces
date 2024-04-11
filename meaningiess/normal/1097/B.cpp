#include<bits/stdc++.h>
#define maxn 20
using namespace std;
int n,a[maxn],p[maxn];
void work(int x)
{
	if (x==n+1)
	{
		int ans=0,i;
		for (i=1;i<=n;i++) ans+=a[i]*p[i];
		if (!(ans%360)) {printf("YES");exit(0);}
		return;
	}
	p[x]=1;work(x+1);
	p[x]=-1;work(x+1);
}
int main()
{
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	work(1);
	printf("NO");
}