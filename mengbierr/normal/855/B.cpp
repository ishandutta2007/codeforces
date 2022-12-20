#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int read()
{
	char ch=getchar();int f=0;
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') {f=f*10+(ch^48);ch=getchar();}
	return f;
}
long long a[100005],p,q,r,x[100005],y[100005],z[100005],f1[100005],f2[100005],f3[100005];int n;
int main()
{
	n=read();cin>>p>>q>>r;
	f1[0]=f2[0]=f3[0]=x[0]=y[0]=z[0]=-3000000000000000000LL;
	//cout<<x[0];
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		x[i]=a[i]*p;
		y[i]=a[i]*q;
		z[i]=a[i]*r;
	}
	for(int i=1;i<=n;i++)
	{
		f1[i]=max(x[i],f1[i-1]);
		long long t=y[i];
		f2[i]=max(y[i]+f1[i-1],y[i]+f1[i]);
		f2[i]=max(f2[i],f2[i-1]);
		f3[i]=max(z[i]+f2[i-1],z[i]+f2[i]);
		f3[i]=max(f3[i],f3[i-1]);
	}
	cout<<f3[n];
}