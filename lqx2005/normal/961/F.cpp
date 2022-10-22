#include<bits/stdc++.h>
typedef unsigned long long ll;
using namespace std;
const int maxn=1000000;
const ll mod=999999937;
int n;
char s[maxn+5];
int ans[maxn+5];
struct Hash
{
	ll key1,key2;
}one,h[maxn+5],p[maxn+5];
Hash operator + (Hash a,Hash b)
{
	Hash c;
	c.key1=(a.key1+b.key1)%mod;
	c.key2=(a.key2+b.key2)%mod;
	return c;
}	
Hash operator - (Hash a,Hash b)
{
	Hash c;
	c.key1=(a.key1-b.key1+mod)%mod;
	c.key2=(a.key2-b.key2+mod)%mod;
	return c;
}	
Hash operator * (Hash a,Hash b)
{
	Hash c=a;
	c.key1=(c.key1*b.key1)%mod;
	c.key2=(c.key2*b.key2)%mod;
	return c;
}
bool operator ==(Hash a,Hash b)
{
	return a.key1==b.key1&&a.key2==b.key2;
}
Hash que(int l,int r)
{
	return h[r]-h[l-1]*p[r-l+1];
}
int check(int l,int r,int len)
{

	int la=l,ra=l+len-1,lb=r-len+1,rb=r;
	if(que(la,ra)==que(lb,rb)) return 1;
	return 0;
}
int main()
{
	one.key1=131;
	one.key2=199;
	scanf("%d",&n);
	scanf("%s",s+1);
	p[0]=(Hash){1,1};
	for(int i=1;i<=n;i++) p[i]=p[i-1]*one;
	for(int i=1;i<=n;i++) h[i]=h[i-1]*one+(Hash){(ll)s[i],(ll)s[i]};
	int en=(n+1)/2;
	ans[en+1]=0;
	for(int i=en;i>=1;i--)
	{
		ans[i]=ans[i+1]+2;
		ans[i]=min(ans[i],n+1-i*2);
		while((!check(i,n+1-i,ans[i])||ans[i]%2==0)&&ans[i]>0) ans[i]--;
	}
	for(int i=1;i<=en;i++) 
	{
		if(!ans[i]) printf("-1 ");
		else printf("%d ",ans[i]);
	}
	printf("\n");
	return 0;
}