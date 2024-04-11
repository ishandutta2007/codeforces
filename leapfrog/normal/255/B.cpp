#include<bits/stdc++.h>
using namespace std;
int n,a[2];char c[1000005];
int main()
{
	scanf("%s",c+1),n=strlen(c+1),a[0]=a[1]=0;
	for(int i=1;i<=n;i++) a[c[i]-'x']++;
	if(a[0]>=a[1]) for(int i=1;i<=a[0]-a[1];i++) putchar('x');
	else for(int i=1;i<=a[1]-a[0];i++) putchar('y');
	return puts(""),0;
}