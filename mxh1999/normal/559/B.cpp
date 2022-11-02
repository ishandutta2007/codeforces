#include<bits/stdc++.h>
using namespace std;
void read(int &digit)
{
	digit=0;
	char c;
	for (c=getchar();(c<'0' || c>'9') && c!='-';c=getchar());
	bool type=false;
	if (c=='-')
		type=true,c=getchar();
	for (;c>='0' && c<='9';digit=digit*10+c-'0',c=getchar());
	if (type==true)
		digit=-digit;
}
#define maxn 200010
int n;
char s1[maxn];
char s2[maxn];

void dfs(int l,int r)
{
	if ((r-l+1)&1)	return;
	int mid=(l+r)>>1;
	dfs(l,mid);
	dfs(mid+1,r);
	int bo1=0,bo2=0;
	for (int i=0;i<mid-l+1;i++)
	{
		if (s1[l+i]<s1[mid+1+i])	{bo1=1;break;}
		if (s1[l+i]>s1[mid+1+i])	{bo1=2;break;}
	}
	if (bo1==2)
	{
		for (int i=0;i<mid-l+1;i++)
			swap(s1[l+i],s1[mid+1+i]);
	}
	for (int i=0;i<mid-l+1;i++)
	{
		if (s2[l+i]<s2[mid+1+i])	{bo2=1;break;}
		if (s2[l+i]>s2[mid+1+i])	{bo2=2;break;}
	}
	if (bo2==2)
	{
		for (int i=0;i<mid-l+1;i++)
			swap(s2[l+i],s2[mid+1+i]);
	}
}
int main()
{
	scanf("%s",s1+1);
	scanf("%s",s2+1);
	n=strlen(s1+1);
	dfs(1,n);
	for (int i=1;i<=n;i++)
	if (s1[i]!=s2[i])	{printf("NO\n");return 0;}
	printf("YES\n");
	return 0;
}