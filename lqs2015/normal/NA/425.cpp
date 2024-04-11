#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
const long double pi=acos(-1),eps=1e-7;
int n,cnt,r;
long long ans;
long double x[3333],y[3333];
int A[3333],b[3333];
pair<long double,int> a[6666];
long long cross(int x1,int x2,int x3,int x4)
{
	return (1ll*x1*x4-1ll*x2*x3);
}
long long c4(int x)
{
	if (x<0) return 0;
	return (1ll*x*(x-1)*(x-2)*(x-3)/24);
}
long long c3(int x)
{
	if (x<0) return 0;
	return (1ll*x*(x-1)*(x-2)/6);
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d%d",&A[i],&b[i]);
		x[i]=(long double)A[i];y[i]=(long double)b[i];
	}
	for (int i=1;i<=n;i++)
	{
		cnt=0;
		for (int j=1;j<=n;j++)
		{
			if (i==j) continue;
			a[++cnt]=make_pair(atan2(y[j]-y[i],x[j]-x[i]),j);
		}
		for (int j=1;j<=cnt;j++) 
		{
			a[cnt+j]=a[j];
			a[cnt+j].first+=2.00*pi;
		}
		sort(a+1,a+2*cnt+1);
		ans+=c4(cnt);
		r=1;
		for (int j=1;j<=cnt;j++)
		{
			while(r<=2*cnt && (cross(A[a[j].second]-A[i],b[a[j].second]-b[i],A[a[r].second]-A[i],b[a[r].second]-b[i])>0 || r<=j)) r++;
			ans-=c3(r-j-1);
		}
	}
	printf("%lld\n",ans);
	return Accepted;
}