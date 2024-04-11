#include<bits/stdc++.h>
using namespace std;
char s[111111];
int n;
int main()
{
	scanf("%d",&n);
	scanf("%s",s);
	sort(s,s+n);
	for (int i=0;i<n;i++) printf("%c",s[i]);
	printf("\n");
	return 0;
}