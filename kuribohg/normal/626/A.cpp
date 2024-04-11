#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,ans;
char s[210];
int main()
{
	scanf("%d%s",&n,s);
	for(int i=0;i<n;i++)
		for(int j=i;j<n;j++)
		{
			int x=0,y=0;
			for(int k=i;k<=j;k++)
				if(s[k]=='U') y++;
				else if(s[k]=='D') y--;
				else if(s[k]=='L') x++;
				else if(s[k]=='R') x--;
			if(x==0&&y==0) ans++;
		}
	printf("%d\n",ans);
	return 0;
}