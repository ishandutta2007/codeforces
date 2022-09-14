#include<iostream>
using namespace std;
int T,a,b;
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>a>>b;
		int ans=b-a;
		{
			int t=0;
			bool ok=false;
			for(int k=20;k--;)
			{
				if(a>>k&1&&!(b>>k&1))ok=true;
				if(ok)t|=a&1<<k;
				else t|=b&1<<k;
			}
			ans=min(ans,t-b+1);
		}
		{
			int t=0,p=0;
			for(int k=20;k--;)
			{
				int ab=a>>k&1,bb=b>>k&1;
				if(ab==bb)t|=ab<<k;
				else
				{
					if(bb)p=1<<k;
					else
					{
						t|=p;
						t&=~(p-1);
						break;
					}
				}
			}
			ans=min(ans,t-a+1);
		}
		cout<<ans<<"\n";
	}
}