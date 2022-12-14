#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int n,pos,a[222222],cnt,sum;
char s[222222];
bool f;
int main()
{
	scanf("%d",&n);
	scanf("%s",s);
	n=strlen(s);pos=-1;
	for (int i=0;i<n;i++)
	{
		if (s[i]==')') 
		{
			pos=i;
			break;
		}
	}
	if (pos==-1)
	{
		printf("No\n");
		return 0;
	}
	for (int i=0;i<n;i++)
	{
		if (i==pos) continue;
		a[++cnt]=(s[i]=='(');
	}
	a[n]=0;
	for (int i=1;i<=n;i++)
	{
		if (a[i]) sum++;
		else sum--;
		if (sum<0) f=1;
	}
	if (sum || f) printf("No\n");
	else printf("Yes\n");
	return Accepted;
}