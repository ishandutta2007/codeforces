#include<iostream>
using namespace std;
int K;long long p,ans;
main()
{
	cin>>K>>p;
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
		{
			for(int k=0;k<10;k++)
			{
				for(int l=0;l<10;l++)
				{
					for(int m=0;m<10;m++)
					{
						if(!(i||j||k||l||m))continue;
						long long now=i+j*10+k*1e2+l*1e3+m*1e4+m*1e5+l*1e6+k*1e7+j*1e8+1L*i*1e9;
						while(now%10==0)now/=10;
						ans=(ans+now)%p;
						K--;
						if(K<=0)
						{
							cout<<ans<<endl;
							return 0;
						}
					}
				}
			}
		}
	}
	ans=(long long)(ans+1e11+1)%p;
	cout<<ans<<endl;
}