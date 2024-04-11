#include<iostream>
using namespace std;
int t;
int A,B,C;
int x[7][3]={
	{1,0,0},
	{0,1,0},
	{0,0,1},
	{1,1,0},
	{0,1,1},
	{1,0,1},
	{1,1,1},
};
main()
{
	cin>>t;
	for(;t--;)
	{
		cin>>A>>B>>C;
		int ans=0;
		for(int i=0;i<1<<7;i++)
		{
			int a=0,b=0,c=0;
			for(int j=0;j<7;j++)
			{
				if(i>>j&1)
				{
					a+=x[j][0];
					b+=x[j][1];
					c+=x[j][2];
				}
			}
			if(A>=a&&B>=b&&C>=c)
			{
				int t=__builtin_popcount(i);
				if(ans<t)ans=t;
			}
		}
		cout<<ans<<endl;
	}
}