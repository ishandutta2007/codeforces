#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
long long x,y,L,R;
main()
{
	cin>>x>>y>>L>>R;
	long long a=1;
	vector<long long>A;
	while(a<=R)
	{
		long long b=1;
		while(a+b<=R)
		{
			if(L<=a+b)A.push_back(a+b);
			if(b<=R/y)b*=y;
			else break;
		}
		if(a<=R/x)a*=x;
		else break;
	}
	A.push_back(L-1);
	A.push_back(R+1);
	sort(A.begin(),A.end());
	long long ans=0;
	for(int i=1;i<A.size();i++)
	{
		long long d=A[i]-A[i-1]-1;
		if(ans<d)ans=d;
	}
	cout<<ans<<endl;
}