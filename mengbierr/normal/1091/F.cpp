#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
ll read()
{
	char ch=getchar();ll f=0,x=1;
	while(ch<'0'||ch>'9'){if(ch=='-') x=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){f=(f<<1ll)+(f<<3ll)+ch-'0';ch=getchar();}
	return f*x;
}
char s[100005];
ll a[100005];
int n;
int main()
{
	n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	scanf("%s",s+1);
	ll ans=0,now=0,temp=0;bool w=0;
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='G')
		{
			ans+=5LL*a[i];
			now+=a[i];
			temp+=2LL*a[i];
		}
		else if(s[i]=='W')
		{
			ans+=3*a[i];
			now+=a[i];
			w=1;
		}
		else
		{
			ans+=a[i];
			now-=a[i];
			if(now<0)
			{
				ans-=now*(w?3:5);
				now=0;
			}
		}
		temp=min(temp,now);
	}
	if(now>0)
	{
		ans-=2LL*temp;
		ans-=now-temp;
	}
	cout<<ans;
}