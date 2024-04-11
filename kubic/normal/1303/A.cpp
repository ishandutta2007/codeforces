#include <bits/stdc++.h>
using namespace std;
#define N 105
int T,n,ps1,ps2,ans;char a[N];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		ans=0;ps1=0;ps2=0;scanf("%s",a+1);n=strlen(a+1);
		for(int i=1;i<=n;++i) if(a[i]=='1') {if(!ps1) ps1=i;ps2=i;}
		if(ps1) for(int i=ps1;i<=ps2;++i) ans+=(a[i]=='0');printf("%d\n",ans);
	}return 0;
}