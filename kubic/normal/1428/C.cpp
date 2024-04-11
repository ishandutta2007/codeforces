#include <bits/stdc++.h>
using namespace std;
#define N 200005
int T,n,ans;char a[N];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",a+1);n=ans=strlen(a+1);int r=0,cnt1=0,cnt2=0;
		for(int i=1;i<=n;++i)
		{
			if(a[i]=='A') {++cnt1;if(cnt2) cnt2=0,++r;}
			if(a[i]=='B')
			{
				if(cnt1) --cnt1,ans-=2;
				else {++cnt2;if(cnt2>1) cnt2-=2,ans-=2;}
			}
		}r+=cnt2;printf("%d\n",ans-r/2*2);
	}return 0;
}