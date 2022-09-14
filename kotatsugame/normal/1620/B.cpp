#include<iostream>
using namespace std;
int T,W,H;
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>W>>H;
		long long ans=0;
		for(int i=0;i<4;i++)
		{
			int k;cin>>k;
			int l=i<2?W:H,r=0;
			for(;k--;)
			{
				int x;cin>>x;
				if(l>x)l=x;
				if(r<x)r=x;
			}
			long long now=(long long)(i<2?H:W)*(r-l);
			if(ans<now)ans=now;
		}
		cout<<ans<<"\n";
	}
}