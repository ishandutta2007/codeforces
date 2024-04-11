#include<bits/stdc++.h>
using namespace std;
#define re register
int main()
{
	re int n;
	scanf("%d",&n);
	for(re int i=1;i<=n;i++)
	{
		re int a,b,t,ans=0;
		scanf("%d%d%d",&a,&b,&t);
		t%=3;
		for(re int i=0;i<=30;i++)if((a&(1<<i))||(b&(1<<i)))
		{
			if(a&(1<<i))
			{
				if(b&(1<<i))
				{
					if(t!=2)ans+=1<<i;
				}else if(t!=1)ans+=1<<i;
			}else if(t!=0)ans+=1<<i;
		}
		printf("%d\n",ans);
	}
}