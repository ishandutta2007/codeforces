#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int read()
{
	char ch=getchar();int f=0;
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9'){f=(f<<1)+(f<<3)+ch-'0';ch=getchar();}
	return f;
}
int a[200005];char s[200005];
int l1[200005],tot1,tot2,r1[200005];
int main()
{
	int n=read();
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)
	a[i]=read();
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='L')
		l1[++tot1]=a[i];
		else 
		r1[++tot2]=a[i];
	}
	int ans=2000000000,l=1;
	for(int i=1;i<=tot2;i++)
	{
		while(l<=tot1&&l1[l]<r1[i])
		{
			l++;
		}
		if(l1[l]>r1[i]&&l<=tot1)
		{
			ans=min(ans,((l1[l]-r1[i])>>1));
		}
	}
	if(ans==2000000000) printf("-1");
	else printf("%d",ans);
}