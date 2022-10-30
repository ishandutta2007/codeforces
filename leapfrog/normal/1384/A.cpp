#include<bits/stdc++.h>
using namespace std;
int t,n,a[105],l[105];char c[105][105];
int main()
{
	for(scanf("%d",&t);t--;)
	{
		scanf("%d",&n),a[n+1]=0,a[0]=0,l[1]=0;
		for(int i=1;i<=n;i++) scanf("%d",a+i);
		for(int i=1;i<=a[1];i++) c[1][++l[1]]='a';
		for(int i=1;i<=n;i++)
		{
			int t=max(a[i],a[i+1]);t=max(t,1),l[i+1]=0;
			for(int j=1;j<=a[i];j++) c[i+1][++l[i+1]]=c[i][j];
			for(int j=a[i]+1;j<=t;j++) c[i+1][++l[i+1]]=(c[i][j]=='a'?'b':'a');
		}
		for(int i=1;i<=n+1;i++)
		{
			if(!l[i]) putchar('c');
			for(int j=1;j<=l[i];j++) putchar(c[i][j]);
			puts("");
		}
	}
	return 0;
}