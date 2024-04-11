#include <bits/stdc++.h>
using namespace std;
#define N 105
int T,n;bool fl;char a[N],b[N],c[N];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		fl=0;scanf("%s %s %s",a+1,b+1,c+1);n=strlen(a+1);
		for(int i=1;i<=n;++i) if(a[i]!=c[i] && b[i]!=c[i])
		{fl=1;puts("NO");break;}if(!fl) puts("YES"); 
	}return 0;
}