#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,d,m,r,ca,cb,a[10000005],b[10000005];
inline bool cmp(int a,int b) {return a>b;}
signed main()
{
	scanf("%lld%lld%lld",&n,&d,&m),r=0,srand(time(0));
	for(int i=1,x;i<=n;i++)
	{
		scanf("%lld",&x);
		if(x<=m) a[++ca]=x;else b[++cb]=x;
	}
	sort(a+1,a+ca+1,cmp),sort(b+1,b+cb+1,cmp);
	for(int i=1;i<=ca;i++) a[i]+=a[i-1];
	for(int i=1;i<=cb;i++) b[i]+=b[i-1];
	r=0;
	for(int i=0;i<=ca;i++)
	{
		int q=(n-i-1)/(d+1)+1;r=max(a[i]+b[q],r);
	}
	return printf("%lld\n",r),0;
}