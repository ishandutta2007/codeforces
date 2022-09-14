#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N,M;
vector<pair<int,int> >A[100000];
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>N>>M;
	for(int i=0;i<N;i++)for(int j=0;j<M;j++)
	{
		int c;cin>>c;
		A[c-1].push_back(make_pair(i,j));
	}
	vector<int>X,Y;
	long long ans=0;
	for(int c=0;c<100000;c++)
	{
		X.clear();
		Y.clear();
		for(pair<int,int>p:A[c])
		{
			X.push_back(p.first);
			Y.push_back(p.second);
		}
		sort(X.begin(),X.end());
		sort(Y.begin(),Y.end());
		long long s=0,cnt=0;
		for(int x:X)
		{
			s+=x;
			ans+=x*++cnt-s;
		}
		s=cnt=0;
		for(int y:Y)
		{
			s+=y;
			ans+=y*++cnt-s;
		}
	}
	cout<<ans<<endl;
}