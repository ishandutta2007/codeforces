#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const long long pa=2,pb=3,mod=1e9+7;
long long n,m,hasa[222222][28],hasb[222222][28],pwa[222222],pwb[222222],x,y,len,a[28],b[28],c[28],d[28];
char s[222222];
bool used[28],f,cur;
int main()
{
	pwa[0]=1;
	for (long long i=1;i<=200000;i++) pwa[i]=pwa[i-1]*pa%mod;
	pwb[0]=1;
	for (long long i=1;i<=200000;i++) pwb[i]=pwb[i-1]*pb%mod;
	scanf("%I64d%I64d%s",&n,&m,s);
	hasa[1][s[0]-'a']=1;hasb[1][s[0]-'a']=1;
	for (long long i=1;i<n;i++)
	{
		for (long long j=0;j<26;j++)
		{
			if ('a'+j==s[i]) hasa[i+1][j]=(hasa[i][j]*pa+1)%mod;
			else hasa[i+1][j]=hasa[i][j]*pa%mod;
			if ('a'+j==s[i]) hasb[i+1][j]=(hasb[i][j]*pb+1)%mod;
			else hasb[i+1][j]=hasb[i][j]*pb%mod;
		}
	}
	while(m--)
	{
		scanf("%I64d%I64d%I64d",&x,&y,&len);
		for (long long i=0;i<26;i++)
		{
			a[i]=(hasa[x+len-1][i]-hasa[x-1][i]*pwa[len])%mod;
			b[i]=(hasa[y+len-1][i]-hasa[y-1][i]*pwa[len])%mod;
			c[i]=(hasb[x+len-1][i]-hasb[x-1][i]*pwb[len])%mod;
			d[i]=(hasb[y+len-1][i]-hasb[y-1][i]*pwb[len])%mod;
			if (a[i]<0) a[i]+=mod;
			if (b[i]<0) b[i]+=mod;
			if (c[i]<0) c[i]+=mod;
			if (d[i]<0) d[i]+=mod;
 		}
		memset(used,0,sizeof(used));
		f=0;
		for (long long i=0;i<26;i++)
		{
			cur=0;
			for (long long j=0;j<26;j++)
			{
				if (a[i]==b[j] && c[i]==d[j] && !used[j])
				{
					used[j]=1;
					cur=1;
					break;
				}
			}
			if (!cur)
			{
				f=1;
				break;
			}
		}
		if (!f) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}