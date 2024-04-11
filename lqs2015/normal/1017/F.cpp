#include<iostream>
#include<cstdio>
#include<bitset>
using namespace std;
unsigned int n,a,b,c,d,cur,nw,ans,kp;
bitset<100000005> msk;
int main()
{
	scanf("%u%u%u%u%u",&n,&a,&b,&c,&d);
	msk.set();
	for (int i=1;i<=n/3+1;i++)
	{
		if (msk[i])
		{
			cur=(i/2)*6;
			if (i&1) cur+=5;
			else cur++;
			for (int j=2*cur;j<=n;j+=cur)
			{
				if (j%6==1) msk.reset((j/6)*2);
				else if (j%6==5) msk.reset((j/6)*2+1);
			}
		}
	}
	cur=a*8+b*4+c*2+d;
	nw=n;
	while(nw)
	{
		nw/=2;
		ans=ans+nw*cur;
	}
	cur=a*27+b*9+c*3+d;
	nw=n;
	while(nw)
	{
		nw/=3;
		ans=ans+nw*cur;
	}
	for (int i=1;i<=n/3+1;i++)
	{
		if (msk[i])
		{
			kp=(i/2)*6;
			if (i&1) kp+=5;
			else kp++;
			cur=a*kp*kp*kp+b*kp*kp+c*kp+d;
			nw=n;
			while(nw)
			{
				nw/=kp;
				ans=ans+nw*cur;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}