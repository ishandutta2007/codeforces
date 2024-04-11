#include<iostream>
#include<cstdio>
#include<bitset>
using namespace std;
bitset<100000233> bs;
unsigned int ans=0,A,B,C,D,n;
unsigned int f(unsigned int p)
{
	return A*p*p*p+B*p*p+C*p+D;
}
void solve()
{
	for(unsigned int i=2;i<=n;i++)
	{
		if(((i%6==1||i%6==5)&&!bs[i/3])||i==2||i==3)
		{
			for(unsigned int j=i;j<=n;j*=i)
			{
				ans+=n/j*f(i);
				if(n/j<i)break;
			}
			for(unsigned int j=2*i;j<=n;j+=i)
				if(j%6==1||j%6==5)bs[j/3]=1;
		}
	}
}
int main()
{
	scanf("%u%u%u%u%u",&n,&A,&B,&C,&D);
	solve();printf("%u\n",ans);
	return 0;
 }