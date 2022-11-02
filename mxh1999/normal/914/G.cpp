#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mo=1e9+7;
const ll inv_2=(1e9+8)/2;
const int maxn=150010;
//1 = xor
//2 = and
//3 = or
int n;
void FWT(ll *a,int n,int op)
{
	for (int h=2;h<=n;h<<=1)
		for (int j=0;j<n;j+=h)
			for (int k=j;k<j+h/2;k++)
			{
				int u=a[k],v=a[k+h/2];
				if (op==1)	{a[k]=(u+v)%mo; a[k+h/2]=(u-v+mo)%mo;}
				if (op==2)	{a[k]=(u+v)%mo; a[k+h/2]=v;}
				if (op==3)	{a[k]=u; a[k+h/2]=(u+v)%mo;}
			}
}
void IFWT(ll *a,int n,int op)
{
	for (int h=2;h<=n;h<<=1)
		for (int j=0;j<n;j+=h)
			for (int k=j;k<j+h/2;k++)
			{
				int u=a[k],v=a[k+h/2];
				if (op==1)	{a[k]=((u+v)*1LL*inv_2)%mo; a[k+h/2]=((u-v)*1LL*inv_2 %mo + mo)%mo;}
				if (op==2)	{a[k]=(u-v+mo)%mo; a[k+h/2]=v;}
				if (op==3)	{a[k]=u; a[k+h/2]=(u-v+mo)%mo;}
			}
}
ll A[maxn],B[maxn];
void cheng(ll *a,ll *b,ll *c,int len,int op)
{
	for (int i=0;i<len;i++)
		A[i]=a[i],B[i]=b[i];
	FWT(A,len,op);
	FWT(B,len,op);
	for (int i=0;i<len;i++)
		c[i]=(A[i]*1LL*B[i])%mo;
	IFWT(c,len,op);
}
ll st[maxn],b[maxn],a[maxn],c[maxn],d[maxn],e[maxn];
ll f[maxn];
const int maxlen=131072;
const int all=maxlen-1;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		st[x]++;
	}
	cheng(st,st,b,maxlen,1);
	for (int i=0;i<maxlen;i++)
	if (st[i])
	{
		for (int j=(all^i);j;j=(j-1)&(all^i))
		if (st[j])
		{
			a[i|j]=(a[i|j]+st[i]*1LL*st[j])%mo;
		}
		if (st[0])	a[i]=(a[i]+st[i]*1LL*st[0])%mo;
	}
	for (int i=0;i<maxlen;i++)	c[i]=st[i];
	f[0]=0;
	f[1]=1;
	for (int i=2;i<maxlen;i++)
		f[i]=(f[i-1]+f[i-2])%mo;
	for (int i=0;i<maxlen;i++)
	{
		a[i]=(a[i]*f[i])%mo;
		b[i]=(b[i]*f[i])%mo;
		c[i]=(c[i]*f[i])%mo;
	}
	cheng(a,b,d,maxlen,2);
	cheng(d,c,e,maxlen,2);
	int ans=0;
	for (int i=1;i<maxlen;i*=2)
		ans=(ans+e[i])%mo;
	cout<<ans<<endl;
	return 0;
}