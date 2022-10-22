#include<bits/stdc++.h>
using namespace std;
int n,m;
char s[1005];
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<1000;i++) s[i]='5';
	printf("%s\n",s);
	for(int i=0;i<999;i++) s[i]='4';
	printf("%s\n",s);
	return 0;
}