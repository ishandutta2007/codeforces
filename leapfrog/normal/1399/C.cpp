#include<bits/stdc++.h>
using namespace std;
int T,n,a[105],s[105],t[105],tt[105];
int main()
{
	for(scanf("%d",&T);T--;)
	{
		scanf("%d",&n),memset(t,0,sizeof(t));int res=0;
		for(int i=1;i<=n;i++) scanf("%d",a+i),t[a[i]]++;
		for(int i=1;i<=100;i++)
		{
			memcpy(tt,t,sizeof(tt));int r=0;
			for(int j=1;j<=i/2;j++) if(i-j>=0&&j!=i-j&&tt[i-j]&&tt[j]) r+=min(tt[i-j],tt[j]),tt[i-j]-=min(tt[i-j],tt[j]),tt[j]-=min(tt[i-j],tt[j]);
			if(i%2==0) r+=tt[i/2]/2;
			res=max(r,res);
		}
		printf("%d\n",res);
	}
	return 0;
}