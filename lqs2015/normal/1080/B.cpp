#include<bits/stdc++.h>
using namespace std;
int q,l,r,ans;
int main()
{
	scanf("%d",&q);
	for (int i=1;i<=q;i++)
	{
		scanf("%d%d",&l,&r);
		ans=0;
		if (l%2==0) 
		{
			ans+=l;
			l++;
		}
		if (r%2==1)
		{
			ans-=r;
			r--;
		}
		ans+=(r-l+1)/2;
		printf("%d\n",ans);
	}
	return 0;
}