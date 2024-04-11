#include<bits/stdc++.h>
using namespace std;
char s[111111],p[111111];
int n,cnt,ct;
bool f;
int main()
{
	scanf("%s",s);
	n=strlen(s);
	for (int i=0;i<n;i++)
	{
		if (s[i]=='1') cnt++;
		else p[++ct]=s[i];
	}
	for (int i=1;i<=ct;i++)
	{
		if (p[i]=='2' && !f)
		{
			f=1;
			for (int j=1;j<=cnt;j++) printf("1");
		}
		printf("%c",p[i]);
	}
	if (!f)
	{
		for (int j=1;j<=cnt;j++) printf("1");
	}
	return 0;
}