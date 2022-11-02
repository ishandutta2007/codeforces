#include<bits/stdc++.h>
using namespace std;
int t,n,cnt=0,s[105];char c[105];
int main()
{
	for(scanf("%d",&t);t--;)
	{
		scanf("%s",c+1),n=strlen(c+1),cnt=0;int r=0;
		for(int i=1;i<=n;i++) if(c[i]=='1') r++;else if(r) s[++cnt]=r,r=0;
		s[++cnt]=r,r=0;
//		for(int i=1;i<=cnt;i++) printf("%d%c",s[i],i==cnt?'\n':' ');
		sort(s+1,s+cnt+1,greater<int>());
		for(int i=1;i<=cnt;i+=2) r+=s[i];
		printf("%d\n",r);
	}
	return 0;
}