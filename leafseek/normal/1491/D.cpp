#include<bits/stdc++.h>
#define rep(a,b,c) for(register int a=(b);a<=(c);++a)
#define dow(a,b,c) for(register int a=(b);a>=(c);--a)
using namespace std;
const int MaxN=100000+5,Bit=29;
bool isx[Bit+10],isy[Bit+10];
int sumx[Bit+10],sumy[Bit+10];
int main()
{
	register int T;
	scanf("%d",&T);
	while(T--)
	{
		register int u,v;
		scanf("%d%d",&u,&v);
		dow(i,Bit,0)
			isx[i]=(u>>i)&1;
		dow(i,Bit,0)
			isy[i]=(v>>i)&1;
		sumx[0]=isx[0];
		rep(i,1,Bit)
			sumx[i]=sumx[i-1]+isx[i];
		sumy[0]=isy[0];
		rep(i,1,Bit)
			sumy[i]=sumy[i-1]+isy[i];
		register bool flag=true;
		rep(i,0,Bit)
			if(sumy[i]>sumx[i])
				flag=false;
		if(flag&&(u<=v))
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}