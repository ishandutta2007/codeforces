#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
#define ull unsigned long long
using namespace std;
int read()
{
	char ch=getchar();int f=0,x=1;
	while(ch<'0'||ch>'9'){if(ch=='-') x=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){f=(f<<1)+(f<<3)+ch-'0';ch=getchar();}
	return f*x;
}
char s[1000005];
int n;
ll h2[1000005],h3[1000005],p2[1000005],p3[1000005],base2=233,mod=1000000009;
ull p[1000005],p1[1000005],h[1000005],h1[1000005],base=1000000009;
ull gethash(int l,int r)
{
	return h[r]-h[l-1]*p[(r-l+1)];
}
ull gethash1(int l,int r)
{
	return h1[l]-h1[r+1]*p[r-l+1];
}
ll gethash2(int l,int r)
{
	ll temp=h2[r]-h2[l-1]*p2[r-l+1]%mod;
	if(temp<0) temp+=mod;
	return temp;
}
ll gethash3(int l,int r)
{
	ll temp=h3[l]-h3[r+1]*p2[r-l+1]%mod;
	if(temp<0) temp+=mod;
	return temp;
}
int main()
{
	int T=read();
	while(T--)
	{
		scanf("%s",s+1);
		n=strlen(s+1);
		int maxx=0;bool ok=1;
		for(int i=1;i<=n;i++)
		{
			if(s[i]!=s[n-i+1]||i>n-i+1)
			{
				maxx=i-1;
				break;
			}
		}
		//cout<<maxx<<endl;
		
		if(2*maxx>=n)
		{
			for(int i=1;i<=n;i++)
			printf("%c",s[i]);
			puts("");
			continue;
		}
		p[0]=1,p2[0]=1;
		for(int i=1;i<=n;i++) p[i]=p[i-1]*base,p2[i]=p2[i-1]*base2%mod;
		h[maxx]=h2[maxx]=0;
		for(int i=maxx+1;i<=n-maxx;i++)
		{
			h[i]=h[i-1]*base+s[i]-'a'+1;
			h2[i]=h2[i-1]*base2+s[i]-'a'+1;
			h2[i]%=mod;
		}
		h1[n-maxx+1]=h3[n-maxx+1]=0;
		for(int i=n-maxx;i>=maxx+1;i--)
		{
			h1[i]=h1[i+1]*base+s[i]-'a'+1;
			h3[i]=h3[i+1]*base2+s[i]-'a'+1;
			h3[i]%=mod;
		}
		int len=1,op=0;
		for(int i=1;i<=n;i++)
		{
			if(2*i>n-maxx-(maxx+1)+1) break;
			if(gethash(maxx+1,maxx+i)==gethash1(maxx+i+1,maxx+2*i)&&gethash2(maxx+1,maxx+i)==gethash3(maxx+i+1,maxx+2*i))
			{
				if(2*i>len) len=2*i,op=0;
			}
			if(gethash1(n-maxx-i+1,n-maxx)==gethash(n-maxx-2*i+1,n-maxx-i)&&gethash3(n-maxx-i+1,n-maxx)==gethash2(n-maxx-2*i+1,n-maxx-i))
			{
				if(2*i>len) len=2*i,op=1;
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(2*i+1>n-maxx-(maxx+1)+1) break;
			if(gethash(maxx+1,maxx+i)==gethash1(maxx+i+2,maxx+2*i+1)&&gethash2(maxx+1,maxx+i)==gethash3(maxx+i+2,maxx+2*i+1))
			{
				if(2*i+1>len) len=2*i+1,op=0;
			}
			if(gethash1(n-maxx-i+1,n-maxx)==gethash(n-maxx-2*i,n-maxx-i-1)&&gethash3(n-maxx-i+1,n-maxx)==gethash2(n-maxx-2*i,n-maxx-i-1))
			{
				if(2*i+1>len) len=2*i+1,op=1;
			}
		}
		//cout<<len<<" "<<op<<endl;
		for(int i=1;i<=maxx;i++) printf("%c",s[i]);
		if(op==0) for(int i=1;i<=len;i++) printf("%c",s[i+maxx]);
		else for(int i=len;i>=1;i--) printf("%c",s[n-maxx-i+1]);
		for(int i=maxx;i>=1;i--) printf("%c",s[i]);
		puts("");
	}
}