#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,num[33],k,mn;
char s[111111];
int main()
{
	scanf("%d%d",&n,&k);
	scanf("%s",s);
	for (int i=0;i<n;i++) num[s[i]-'A'+1]++;
	mn=1e9;
	for (int i=1;i<=k;i++) mn=min(mn,num[i]);
	printf("%d\n",mn*k);
	return 0;
}