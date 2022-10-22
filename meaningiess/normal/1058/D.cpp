#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#define ll long long
int f1[100010],f2[100010];
using namespace std;
int fx(ll &x,ll p)
{
	int t=0;
	while (x%p==0) {t++;x/=p;}
	return t;
}
ll qsm(ll a,int b)
{
	ll t=1;
	while (b>0){if(b&1) t*=a;a*=a;b>>=1;}
	return t;
}
int main()
{
	ll n,m,k;int i,f=0;cin>>n>>m>>k;
	if (2*n*m%k!=0||k==1) {printf("NO\n");return 0;}
	ll S=2*n*m/k,mx=max(sqrt(n),max(sqrt(m),sqrt(k)));
	for (i=2;i<=mx;i++)
	{
		int c1=fx(n,i),c2=fx(m,i),c3=fx(k,i);
		if (i==2&&c1+c2<c3) {f1[i]=0;f2[i]=0;f=1;continue;}
		f1[i]=max(c1-c3,0);f2[i]=c1+c2-c3-f1[i];
		if (!f && f1[i]!=c1) {f1[2]++;f=1;}
		if (!f && f2[i]!=c2) {f2[2]++;f=1;}
	}
	if (k!=1)
	{
		if (n==k) {n=1;if(!f) f1[2]++;}
		else if (m==k) {m=1;if(!f) f2[2]++;}
	}
	ll ans1=1,ans2=1;
	for (i=2;i<=mx;i++)
	{
		if (f1[i]) ans1*=qsm(i,f1[i]);
		if (f2[i]) ans2*=qsm(i,f2[i]);
	}
	printf("YES\n0 0\n%I64d 0\n0 %I64d",ans1*n,ans2*m);
}