#include<iostream>
#include<vector>
using namespace std;
int N;
main()
{
	cin>>N;
	vector<pair<int,int> >A[2];
	for(int i=1;i<=N;i++)for(int j=1;j<=N;j++)A[i+j&1].push_back(make_pair(i,j));
	for(int t=0;t<N*N;t++)
	{
		int a;cin>>a;a--;
		if(A[0].empty())
		{
			int b=a==1?2:1;
			int i=A[1].back().first,j=A[1].back().second;
			A[1].pop_back();
			cout<<b+1<<" "<<i<<" "<<j<<endl;
		}
		else if(A[1].empty())
		{
			int b=a==0?2:0;
			int i=A[0].back().first,j=A[0].back().second;
			A[0].pop_back();
			cout<<b+1<<" "<<i<<" "<<j<<endl;
		}
		else
		{
			int b=a==0?1:0;
			int i=A[b].back().first,j=A[b].back().second;
			A[b].pop_back();
			cout<<b+1<<" "<<i<<" "<<j<<endl;
		}
	}
}