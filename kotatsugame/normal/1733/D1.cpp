#include<iostream>
#include<vector>
using namespace std;
string A,B;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		int N,X,Y;
		cin>>N>>X>>Y;
		cin>>A>>B;
		vector<int>ids;
		for(int i=0;i<N;i++)if(A[i]!=B[i])
		{
			ids.push_back(i);
		}
		if(ids.size()%2==1)
		{
			cout<<"-1\n";
			continue;
		}
		if(ids.size()==2&&ids[0]+1==ids[1])
		{
			cout<<min(Y*2,X)<<"\n";
		}
		else cout<<(long long)Y*(ids.size()/2)<<"\n";
	}
}