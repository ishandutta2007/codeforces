#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int a,b,c,N;
main()
{
	cin>>a>>b>>c>>N;
	vector<int>U,P;
	for(int i=0;i<N;i++)
	{
		int x;string s;
		cin>>x>>s;
		if(s[0]=='U')U.push_back(x);
		else P.push_back(x);
	}
	sort(U.begin(),U.end());
	sort(P.begin(),P.end());
	int iu=0,ip=0;
	long long ans=0;
	int cnt=0;
	while(iu<U.size()&&iu<a)
	{
		ans+=U[iu++];
		cnt++;
	}
	while(ip<P.size()&&ip<b)
	{
		ans+=P[ip++];
		cnt++;
	}
	while(c>0&&(iu<U.size()||ip<P.size()))
	{
		c--;
		if(iu<U.size()&&(ip==P.size()||U[iu]<P[ip]))
		{
			ans+=U[iu++];
			cnt++;
		}
		else
		{
			ans+=P[ip++];
			cnt++;
		}
	}
	cout<<cnt<<" "<<ans<<endl;
}