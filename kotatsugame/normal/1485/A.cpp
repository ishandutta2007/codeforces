#include<cstdio>
using namespace std;
int T,A,B;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d",&A,&B);
		int ans=1e9;
		for(int t=0;t<100;t++)
		{
			int b=B+t;
			int now=t;
			if(b==1)continue;
			int a=A;
			while(a)a/=b,now++;
			if(ans>now)ans=now;
		}
		printf("%d\n",ans);
	}
}