#include<iostream>
#include<map>
using namespace std;
int N;
int X[2000],Y[2000];
main()
{
	cin>>N;
	for(int i=0;i<N;i++)cin>>X[i]>>Y[i];
	map<pair<int,int>,int>mp;
	long long ans=0;
	for(int i=0;i<N;i++)for(int j=i+1;j<N;j++)
	{
		int dx=X[j]-X[i],dy=Y[j]-Y[i];
		if(dx<0)dx=-dx,dy=-dy;
		else if(dx==0&&dy<0)dy=-dy;
		ans+=mp[make_pair(dx,dy)]++;
	}
	cout<<ans/2<<endl;
}