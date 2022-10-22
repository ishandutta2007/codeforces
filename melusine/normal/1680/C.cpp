#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
inline int read()
{
	int n=0,f=1,ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		n=n*10+ch-'0';
		ch=getchar();
	}
	return n*f;
}
char s[200005];
int qzh[200005];
int tl[200005],cnt;
int n;
bool check(int k)
{
	if(k>cnt)return true;
	for(int i=1;i<=cnt-k+1;i++)
	{
		if(qzh[tl[i+k]-1]-qzh[tl[i-1]]>=qzh[n]-k)return true;
	}
	return false;
}
int main()
{
	int t,l,r,mid;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		scanf("%s",s+1);
		n=strlen(s+1);
		cnt=0;
		for(int i=1;i<=n;i++)if(s[i]=='0')tl[++cnt]=i;
		tl[0]=0;
		tl[cnt+1]=n+1;
		qzh[0]=0;
		for(int i=1;i<=n;i++)qzh[i]=qzh[i-1]+s[i]-'0';
		l=0;
		r=n;
		//printf("%lld\n",(int)(check(1)));
		while(l<=r)
		{
			mid=(l+r)>>1;
			if(check(mid))r=mid-1;
			else l=mid+1;
		}
		printf("%d\n",l);
	}
	return 0;
}