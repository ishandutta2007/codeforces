#include<iostream>
#include<set>
#include<queue>
using namespace std;
long long x,y;
set<long long>S;
long long f(long long x,int t)
{
	x=x*2+t;
	long long ret=0;
	while(x>0)
	{
		ret<<=1;
		ret+=x%2;
		x/=2;
	}
	return ret;
}
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>x>>y;
	S.insert(x);
	queue<long long>P;
	P.push(x);
	while(!P.empty())
	{
		long long x=P.front();P.pop();
		if(x>=1LL<<60)continue;
		for(int t=0;t<2;t++)
		{
			long long v=f(x,t);
			if(S.find(v)==S.end())
			{
				S.insert(v);
				P.push(v);
			}
		}
	}
	cout<<(S.find(y)==S.end()?"NO":"YES")<<endl;
}