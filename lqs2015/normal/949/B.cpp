#include<iostream>
#include<cstdio>
using namespace std;
long long n,q,x,ans,f,all,ff;
int main()
{
	scanf("%I64d%I64d",&n,&q);
	while(q--)
	{
		scanf("%I64d",&x);
		f=1;ans=0;all=n;
		while(1)
		{
			if (x%2==f) 
			{
				ans+=((x+1)/2);
				break;
			}
			ans+=((all+f)/2);
			ff=f^(all%2);
			all-=((all+f)/2);
			f=ff;
			x=(x+1)/2;
		}
		printf("%I64d\n",ans);
	}
	return 0;
}