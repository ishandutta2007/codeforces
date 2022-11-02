#include<bits/stdc++.h>
using namespace std;

char s[10010];
int n;
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	for (int i=1;i<=n;i++)
		printf("%c",s[i]);
	for (int i=n;i>=1;i--)
		printf("%c",s[i]);
	return 0;
}