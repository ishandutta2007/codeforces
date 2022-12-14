#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int n,test,pre[1111111],pr,pos,ans;
char s[1111111];
int main()
{
	scanf("%d",&n);
	scanf("%s",s);
	for (int i=1;i<=n;i++)
	{
		if (s[i-1]=='(') pre[i]=pre[i-1]+1;
		else pre[i]=pre[i-1]-1;
	}
	if (pre[n]!=0) 
	{
		printf("-1\n");
		return 0;
	}
	for (int i=1;i<=n;i++)
	{
		if (pre[i]<0)
		{
			ans++;
			if (pre[i-1]>=0) ans++; 
		}
	}
	printf("%d\n",ans);
	return Accepted;
}