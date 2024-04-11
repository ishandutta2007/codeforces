#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N;
int K[500];
main()
{
	cin>>N;
	for(int i=0;i<N;i++)cin>>K[i];
	vector<pair<int,pair<int,int> > >A;
	for(int i=0;i<N;i++)for(int j=i+1;j<N;j++)
	{
		if(K[i]<=K[j])
		{
			A.push_back(make_pair(K[j]-K[i],make_pair(j,i)));
		}
		else
		{
			A.push_back(make_pair(K[i]-K[j],make_pair(i,j)));
		}
	}
	sort(A.begin(),A.end());
	for(int i=A.size();i--;)
	{
		int u=A[i].second.first,v=A[i].second.second;
		cout<<"? "<<u+1<<" "<<v+1<<endl;
		string s;cin>>s;
		if(s=="Yes")
		{
			cout<<"! "<<u+1<<" "<<v+1<<endl;
			return 0;
		}
	}
	cout<<"! 0 0"<<endl;
}