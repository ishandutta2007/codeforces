#include <bits/stdc++.h>
using namespace std;
#define N 1000005
int n,cnt,nw,t,ans;char a[N];bool fl;
int main()
{
	scanf("%d %s",&n,a+1);
	for(int i=1;i<=n;++i)
	{
		if(a[i]=='(') ++cnt;else --cnt;if(cnt<0) fl=1;
		if(fl)
		{
			if(a[i]=='(') ++nw;else --nw;++t;
			if(!nw) ans+=t,fl=t=0;
		}
	}if(cnt) puts("-1");else printf("%d\n",ans);return 0;
}