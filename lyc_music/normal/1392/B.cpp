#include<bits/stdc++.h>
#define N 500005
#define int long long
using namespace std;
struct nmsl
{
	int x,y;
}a[N];
bool Cmp(nmsl xx,nmsl yy)
{
	return xx.x>yy.x;
}
int b[N],ans[N],T,n,k,mx;
signed main()
{
	cin>>T;
	while (T--)
	{
		cin>>n>>k;k&=1;mx=-9999999999;
		for (int i=1;i<=n;i++) cin>>b[i],mx=max(mx,b[i]);
		if (!k) 
		{
			for (int i=1;i<=n;i++) b[i]=mx-b[i];
			mx=-9999999999;
			for (int i=1;i<=n;i++) mx=max(mx,b[i]);
			for (int i=1;i<=n;i++) b[i]=mx-b[i];
		} else
		for (int i=1;i<=n;i++) b[i]=mx-b[i];
		for (int i=1;i<=n;i++) cout<<b[i]<<" ";
		cout<<endl;
	}
}