#include<bits/stdc++.h>
using namespace std;
int t,b,p,f,h,c;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d%d%d",&b,&p,&f,&h,&c);
		int sum=b/2,ans=0;
		for(int i=0;i<=sum;i++)
		{
			if(i>p) continue;
			int oth=sum-i;
			if(oth>f) oth=f;
			ans=max(ans,h*i+oth*c);
		}
		printf("%d\n",ans);
	}
	return 0;
}