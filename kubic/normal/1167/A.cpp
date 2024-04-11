#include <bits/stdc++.h>
using namespace std;
#define N 105
int T,n,t;char a[N];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %s",&n,a+1);t=n;
		for(int i=1;i<=n;++i) if(a[i]=='8') {t=i;break;}
		puts(n-t>=10?"YES":"NO");
	}
}