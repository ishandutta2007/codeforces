#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
char s[222222];
int n,md,pre[222222],a[222222],crt,l1,r1,l2,r2;
int ct[200005*402+10];
long long ans;
long long c1(int x,int i)
{
	if (x<0) return 0;
	int cr;
	if (x%i>=md) cr=x/i;
	else cr=x/i-1;
	if (cr<0) return 0;
	return 1ll*md*(cr+1)+1ll*i*cr*(cr+1)/2+cr+1;
}
long long calc1(int l,int r,int i)
{
	if (l>r) return 0;
	return c1(r,i)-c1(l-1,i);
}
long long c2(int x,int i,int R)
{
	if (x<0) return 0;
	int cr;
	if (x%i>=md) cr=x/i;
	else cr=x/i-1;
	if (cr<0) return 0;
	return 1ll*R*(cr+1);
}
long long calc2(int l,int r,int i,int R)
{
	if (l>r) return 0;
	return c2(r,i,R)-c2(l-1,i,R);
}
long long c3(int x,int i,int R)
{
	if (x<0) return 0;
	int cr;
	if (x%i>=md) cr=x/i;
	else cr=x/i-1;
	if (cr<0) return 0;
	return -1ll*md*(cr+1)-1ll*i*cr*(cr+1)/2+1ll*R*(cr+1);
}
long long calc3(int l,int r,int i,int R)
{
	if (l>r) return 0;
	return c3(r,i,R)-c3(l-1,i,R);
}
long long calc(int l,int r,int c,int i)//x in [0,l],y in [0,r],i|x+y+c,x+y+c>400i
{
	if (l>r) swap(l,r);
	int thre=401*i-c;//x+y>=thre
	md=(i-c%i)%i;
	return 1ll*calc1(max(thre,0),l-1,i)+calc2(max(thre,l),r,i,l+1)+calc3(max(r+1,thre),l+r,i,l+r+1);
}
int main()
{
	scanf("%s",s);
	n=strlen(s);
	for (int i=1;i<=n;i++)
	{
		pre[i]=pre[i-1]+(s[i-1]=='1');
	}
	for (int i=1;i<=n;i++)
	{
		if (s[i-1]=='1') 
		{
			crt++;
			a[crt]=i;
		}
	}
	for (int i=1;i<=400;i++)
	{
		ct[n]++;
		for (int j=1;j<=n;j++)
		{
			ans+=ct[pre[j]*i+n-j];
			ct[pre[j]*i+n-j]++;
		}
		ct[n]--;
		for (int j=1;j<=n;j++)
		{
			ct[pre[j]*i+n-j]--;
		}
	}
	for (int i=1;i<=500;i++)
	{
		for (int j=i;j<=crt;j++)
		{
			l1=(j-i==0 ? 1 : a[j-i]+1);r1=a[j-i+1];l2=a[j];r2=(j==crt ? n : a[j+1]-1);
			ans+=calc(r1-l1,r2-l2,l2-r1+1,i);
		}
	}
	printf("%lld\n",ans);
	return Accepted;
}