#include<bits/stdc++.h>
using namespace std;
int n;
char s[200000];
int main()
{
	scanf("%d",&n);
	scanf("%s",s);
	sort(s,s+n);
	printf("%s\n",s);
	return 0;
}