#include<bits/stdc++.h>
using namespace std;
char s[200000];
int main()
{
	int n,m;
	int l,r;
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++) scanf("%d %d",&l,&r);
	for(int i=0;i<n;i++) s[i]='0'+i%2;
	printf("%s",s);
	return 0;
}