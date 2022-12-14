#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int n,p,cur,ans,cnt;
int main()
{
	scanf("%d%d",&n,&p);
	ans=1e9;
	for (int i=1;i<=50;i++)
	{
		cur=n-p*i;
		if (cur<i) continue;
		cnt=0;
		for (int j=0;j<=30;j++)
		{
			if (cur&(1<<j)) cnt++;
		}
		if (cnt<=i) ans=min(ans,i);
	}
	if (ans>1e8) printf("-1\n");
	else printf("%d\n",ans);
	return Accepted;
}