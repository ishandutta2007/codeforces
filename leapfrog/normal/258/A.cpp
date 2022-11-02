#include<bits/stdc++.h>
using namespace std;
char c[1000005];int n,f=0;
int main()
{
	scanf("%s",c+1),n=strlen(c+1);
	for(int i=1;i<=n;i++) if(c[i]=='0') {f=i;break;}
	if(!f) for(int i=2;i<=n;i++) putchar(c[i]);
	else for(int i=1;i<=n;i++) if(f!=i) putchar(c[i]);
	return puts(""),0;
}