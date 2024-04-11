#include<bits/stdc++.h>
using namespace std;

#define maxn 1000010
const int mo=1000000007;
int n,m,len;
char s[maxn];
int next[maxn];
bool ok[maxn];

void build_kmp()
{
	int j=0;
	for (int i=2;i<=n;i++)
	{
		while (j>0 && s[j+1]!=s[i])	j=next[j];
		if (s[j+1]==s[i])	j++;
		next[i]=j;
	}
	j=next[n];
	ok[0]=true;
	while (j>0)
	{
		ok[n-j]=true;
		j=next[j];
	}
}
int main()
{
	scanf("%d%d",&len,&m);
	scanf("%s",s+1);
	n=strlen(s+1);
	build_kmp();
	int l=0,r=0,ans=0;
	for (int i=1;i<=m;i++)
	{
		int x;
		scanf("%d",&x);
		if (x>r)	ans+=(x-1)-r,l=x,r=l+n-1;else
		{
			if (ok[x-l])	l=x,r=l+n-1;else {printf("0\n");return 0;}
		}
	}
	ans+=len-r;
	int ans1=1;
	for (int i=1;i<=ans;i++)	ans1=(1LL*ans1*26)%mo;
	printf("%d\n",ans1);
	return 0;
}