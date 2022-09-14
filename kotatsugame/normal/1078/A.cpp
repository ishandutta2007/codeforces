#include<iostream>
#include<iomanip>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
int a,b,c;
int x,y,z,w;
main()
{
	cin>>a>>b>>c>>x>>y>>z>>w;
	double ans=(long long)abs(x-z)+(long long)abs(y-w);
	vector<pair<pair<double,double>,double> >A,B;
	if(b!=0)
	{
		pair<double,double>now;
		now.first=x;
		now.second=(c+a*now.first)/-b;
		A.push_back(make_pair(now,abs(now.second-y)));
	}
	if(a!=0)
	{
		pair<double,double>now;
		now.second=y;
		now.first=(c+b*now.second)/-a;
		A.push_back(make_pair(now,abs(now.first-x)));
	}
	if(b!=0)
	{
		pair<double,double>now;
		now.first=z;
		now.second=(c+a*now.first)/-b;
		B.push_back(make_pair(now,abs(now.second-w)));
	}
	if(a!=0)
	{
		pair<double,double>now;
		now.second=w;
		now.first=(c+b*now.second)/-a;
		B.push_back(make_pair(now,abs(now.first-z)));
	}
	for(pair<pair<double,double>,double>s:A)
	{
		for(pair<pair<double,double>,double>t:B)
		{
			ans=min(ans,s.second+t.second+hypot(s.first.first-t.first.first,s.first.second-t.first.second));
		}
	}
	cout<<fixed<<setprecision(16)<<ans<<endl;
}