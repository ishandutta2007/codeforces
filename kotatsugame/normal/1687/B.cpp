#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N,M;
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>N>>M;
	vector<pair<int,int> >E(M);
	string s(M,'0');
	for(int i=0;i<M;i++)
	{
		s[i]='1';
		cout<<"? "<<s<<endl;
		s[i]='0';
		cin>>E[i].first;
		E[i].second=i;
	}
	sort(E.begin(),E.end());
	int cur=0;
	for(int i=0;i<M;i++)
	{
		int id=E[i].second;
		s[id]='1';
		cout<<"? "<<s<<endl;
		int now;
		cin>>now;
		if(cur+E[i].first==now)cur=now;
		else s[id]='0';
	}
	cout<<"! "<<cur<<endl;
}