#include<iostream>
#include<vector>
using namespace std;
int A[1<<17];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		int N;cin>>N;
		for(int i=0;i<N;i++)cin>>A[i];
		vector<pair<int,int> >op;
		vector<int>A0,A1;
		for(int i=0;i<N;i++)
		{
			if(A[0]%2==A[i]%2)A0.push_back(i);
			else A1.push_back(i);
		}
		for(int i=(int)A0.size()-2;i>=0;i--)op.push_back(make_pair(A0[i],A0[i+1]));
		for(int id:A1)op.push_back(make_pair(0,id));
		cout<<op.size()<<"\n";
		for(pair<int,int>p:op)cout<<p.first+1<<" "<<p.second+1<<"\n";
	}
}