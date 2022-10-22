#include <bits/stdc++.h>
using namespace std;
#define N 300005
int T,n;char a[N];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %s",&n,a+1);bool vs1=1,vs2=1;
		for(int i=1;i<=n;++i) {if(a[i]=='<') vs1=0;if(a[i]=='>') vs2=0;}
		if(vs1 || vs2) {printf("%d\n",n);continue;}int ans=0;
		for(int i=1;i<=n;++i) if(a[i]=='-' || a[i%n+1]=='-') ++ans;
		printf("%d\n",ans);
	}return 0;
}