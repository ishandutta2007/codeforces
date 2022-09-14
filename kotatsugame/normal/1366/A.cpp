#include<cstdio>
using namespace std;
int T,A,B;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d",&A,&B);
		int ans=0;
		if(A>B)
		{
			int d=A-B;
			if(d*2>A)d=A/2;
			if(d>B)d=B;
			ans+=d;
			A-=d*2;
			B-=d;
		}
		else
		{
			int d=B-A;
			if(d*2>B)d=B/2;
			if(d>A)d=A;
			ans+=d;
			B-=d*2;
			A-=d;
		}
		if(A>=3&&B>=3)
		{
			int t=A/3;
			if(t*3>B)t=B/3;
			ans+=2*t;
			A-=3*t;
			B-=3*t;
		}
		while((A>=2&&B>=1)||(A>=1&&B>=2))
		{
			if(A>=2&&B>=1)
			{
				ans++;
				A-=2;
				B--;
			}
			else
			{
				ans++;
				A--;
				B-=2;
			}
		}
		printf("%d\n",ans);
	}
}