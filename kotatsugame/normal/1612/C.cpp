#include<iostream>
using namespace std;
int T;
long long K,X;
main()
{
	cin>>T;
	for(;T--;)
	{
		cin>>K>>X;
		long long ans=0;
		if(K*(K+1)/2<X)
		{
			X-=K*(K+1)/2;
			ans+=K;
			if(K*(K-1)/2<X)
			{
				ans+=K-1;
			}
			else
			{
				long long L=0,R=K-1;
				while(R-L>1)
				{
					long long mid=(L+R)/2;
					if(mid*K-mid*(mid+1)/2>=X)R=mid;
					else L=mid;
				}
				ans+=R;
			}
		}
		else
		{
			long long L=0,R=K;
			while(R-L>1)
			{
				long long mid=(L+R)/2;
				if(mid*(mid+1)/2>=X)R=mid;
				else L=mid;
			}
			ans+=R;
		}
		cout<<ans<<"\n";
	}
}