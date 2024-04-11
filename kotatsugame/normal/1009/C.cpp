#include<iostream>
#include<iomanip>
using namespace std;
long long ans,n,m,x,d;
main()
{
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		cin>>x>>d;
		ans+=x*n;
		if(d<0)
		{
			if(n%2)ans+=d*(n/2*(n/2+1));
			else ans+=d*(n/2)*(n/2);
		}
		else ans+=d*(n*(n-1)/2);
	}
	cout<<fixed<<setprecision(9)<<(double)ans/(double)n<<endl;
}