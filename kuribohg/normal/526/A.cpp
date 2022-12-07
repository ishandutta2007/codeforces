#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=100010;
int n,a[MAXN];
char str[MAXN];
int main()
{
	scanf("%d",&n);
	scanf("%s",str);
	for(int i=0;i<n;i++)
		for(int j=1;j<n;j++)
			if(str[i]=='*'&&str[i+j]=='*'&&str[i+2*j]=='*'&&str[i+3*j]=='*'&&str[i+4*j]=='*')
			{puts("yes");return 0;}
	puts("no");
	return 0;
}