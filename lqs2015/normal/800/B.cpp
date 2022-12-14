#include<bits/stdc++.h>
using namespace std;
int n,a,b,c;
long double x[1111],y[1111],A,B,C,p,S,ans;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%Lf%Lf",&x[i],&y[i]);
	}
	ans=1e18;
	for (int i=1;i<=n;i++)
	{
		a=i;b=i+1;
		if (b>n) b=1;
		for (c=1;c<=n;c++)
		{
			if (c==a || c==b) continue;
			A=sqrt((x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b]));
			B=sqrt((x[a]-x[c])*(x[a]-x[c])+(y[a]-y[c])*(y[a]-y[c]));
			C=sqrt((x[c]-x[b])*(x[c]-x[b])+(y[c]-y[b])*(y[c]-y[b]));
			S=(x[b]-x[a])*(y[c]-y[a])-(x[c]-x[a])*(y[b]-y[a]);
			S/=2.00;
			if (S<0) S=-S;
			ans=min(ans,S/max(A,max(B,C)));
		}
	}
	printf("%.9Lf\n",ans);
	return 0;
}