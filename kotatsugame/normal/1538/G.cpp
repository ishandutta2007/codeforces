#include<cstdio>
#include<algorithm>
using namespace std;
int T,X,Y,A,B;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d%d%d",&X,&Y,&A,&B);
		int ans=max(min(X/A,Y/B),min(X/B,Y/A));
		long long L=0,R=min(X/A,Y/B);
		while(R-L>2)
		{
			long long x1=(L+L+R)/3,x2=(L+R+R)/3;
			double f1=x1+min((X-A*x1)/(double)B,(Y-B*x1)/(double)A);
			double f2=x2+min((X-A*x2)/(double)B,(Y-B*x2)/(double)A);
			if(f1<f2)L=x1;
			else R=x2;
		}
		for(long long x=L;x<=R;x++)
		{
			if(x<0)continue;
			ans=max((long long)ans,x+min((X-A*x)/B,(Y-B*x)/A));
		}
		printf("%d\n",ans);
	}
}