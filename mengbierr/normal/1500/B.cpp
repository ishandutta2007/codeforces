#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
int read()
{
	char ch=getchar();int f=0,x=1;
	while(ch<'0'||ch>'9'){if(ch=='-') x=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){f=(f<<1)+(f<<3)+ch-'0';ch=getchar();}
	return f*x;
}
ll exgcd(ll a,ll b,ll &x,ll &y)
{
	if(!b) return x=1,y=0,a;
	ll d=exgcd(b,a%b,x,y),t=x;
	return x=y,y=t-a/b*y,d;
}
ll ans;bool ok=0;
void cal(ll a,ll b,ll n)
{
	ll x,y,d=exgcd(a,n,x,y);
	if(b%d)
	{
		ok=0;return;
	}
	ok=1;
	x=(x%n+n)%n;
	ans=x*(b/d)%(n/d);
}
ll n,m,pla1[1000005],pla2[1000005];ll k;
ll len[1000005],s[1000005];
ll p[1000005],cnt;
ll gcd(ll x,ll y)
{
	return !y?x:gcd(y,x%y);
}
ll lcm(ll x,ll y)
{
	return x*y/gcd(x,y);
}
int main()
{
	n=read();m=read();cin>>k;
	for(int i=1;i<=n;i++)
	{
		int x=read();
		pla1[x]=i;
	}
	for(int i=1;i<=m;i++)
	{
		int x=read();
		pla2[x]=i;
	}
	for(int i=1;i<=2*max(n,m);i++)
	{
		if(pla1[i]&&pla2[i])
		{
			
			cal(n,((pla2[i]-pla1[i])%m+m)%m,m);
			if(ok)
			{
				ll tmp=ans*n+pla1[i];
				ll q=lcm(n,m);
				tmp%=q;
				tmp+=q;tmp%=q;
				if(tmp==0) tmp=lcm(n,m);
				p[++cnt]=tmp;
				//cout<<tmp<<" ";
			}
		}
	}
	sort(p+1,p+cnt+1);
	ll u=lcm(n,m);
	k--;
	ll tans=k/(lcm(n,m)-cnt)*lcm(n,m);
	k%=(lcm(n,m)-cnt);
	k++;
	//cout<<tans<<" "<<k<<endl;
	for(int i=1;i<=cnt;i++)
	{
		if(k>p[i]-p[i-1]-1) k-=p[i]-p[i-1]-1,tans+=p[i]-p[i-1];
		else
		{
			tans+=k;
			k=0;
			break;
		}
	}
	if(k) tans+=k;
	cout<<tans;
}