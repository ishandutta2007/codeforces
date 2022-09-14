#include<iostream>
using namespace std;
int T,L,R;
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>L>>R;
		R++;
		int ans=0;
		for(int k=0;;k++)
		{
			int b=1<<k+1;
			int l=L/b,r=R/b;
			int now=0;
			if(l==r)
			{
				l=L%b,r=R%b;
				if(l<b/2)l=b/2;
				now=r-l;
			}
			else
			{
				now=b/2*(r-l-1);
				l=L%b,r=R%b;
				if(l<b/2)l=b/2;
				now+=b-l;
				if(r>=b/2)now+=r-b/2;
			}
			if(ans<now)ans=now;
			if(R<=b)break;
		}
		cout<<R-L-ans<<"\n";
	}
}