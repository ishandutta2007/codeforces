#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<map>
#include<stack>
using namespace std;
const double eps=1e-10;
int read()
{
	char ch=getchar();int f=0;
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') {f=f*10+(ch^48);ch=getchar();}
	return f;
}
int n,a[105],s[1000005],head;
map<int,int> mp;
int sqr(int x)
{
	return x*x;
}

int get_sg(int x,int maxx)
{
	if(mp.find(x)!=mp.end()) return mp[x];
	while(maxx&&(x&(1<<(maxx-1)))==0) maxx--;
	if(!maxx) return maxx;
	bool vis[30]={0};
	for(int i=1;i<=maxx;i++)
	{
		int now=x>>i;
		now|=x&((1<<(i-1))-1);
		vis[get_sg(now,max(maxx-i,i-1))]=1;
	}
	for(int i=0;;i++)
	if(!vis[i]) return mp[x]=i;
}
int ans;
void doit(int x)
{int t=0,maxx=0;
	for(int i=1;i<=n;i++)
	{
		int temp=a[i],temp2=0;
		while(!(temp%x))
		{
			temp/=x,temp2++;
		}
		if(temp2) t|=1<<(temp2-1);
		maxx=max(maxx,temp2);
	}
	ans^=get_sg(t,maxx);
}
int main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();int x=a[i],x1=x;
		for(int j=2;sqr(j)<=x1;j++)
		{
			if(!(x%j))
			{
				s[++head]=j;
				while(!(x%j))
				x/=j;
			}
		}
		if(x>1) s[++head]=x;
	}
	sort(s+1,s+head+1);
	for(int i=1;i<=head;i++)
	{
		if(s[i]!=s[i-1])
		doit(s[i]);
	}
	if(!ans)
	puts("Arpa");
	else puts("Mojtaba");
}