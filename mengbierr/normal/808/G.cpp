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
char s[100005],t[100005];
int nxt[100005],f[100005],cnt[100005];
int n,m;
void kmp(char x[],int m,int nxt[])
{
	int i,j;
	nxt[0]=j=-1;
	i=0;
	while(i<m)
	{
		while(j!=-1&&x[i]!=x[j]) j=nxt[j];
		nxt[++i]=++j;
	}
}
int main()
{
	scanf("%s",s);
	scanf("%s",t);
	n=strlen(s);m=strlen(t);
	kmp(t,m,nxt);
	if(m>n) puts("0");
	else
	{
		for(int i=m-1;i<n;i++)
		{
			bool ac=1;
			for(int k=0;k<m;k++)
			{
				if(s[i-k]!=t[m-1-k]&&s[i-k]!='?')
				{
					ac=0;
					break;
				}
			}
			f[i]=f[i-1];
			if(ac)
			{
				cnt[i]=f[i-m];
				for(int k=nxt[m];k!=-1;k=nxt[k])
				{
					cnt[i]=max(cnt[i],cnt[(i-(m-k))]);
				}
				cnt[i]++;
				f[i]=max(f[i],cnt[i]);
			}
		}
		printf("%d\n",f[n-1]);
	}
}