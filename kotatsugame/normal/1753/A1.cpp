#include<iostream>
#include<vector>
using namespace std;
int N,A[2<<17];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		cin>>N;
		for(int i=0;i<N;i++)
		{
			cin>>A[i];
		}
		if(N%2==1)
		{
			cout<<"-1\n";
			continue;
		}
		vector<pair<int,int> >ans;
		for(int i=0;i<N;i+=2)
		{
			if(A[i]!=A[i+1])
			{
				ans.push_back(make_pair(i,i+1));
				ans.push_back(make_pair(i+1,i+2));
			}
			else
			{
				ans.push_back(make_pair(i,i+2));
			}
		}
		cout<<ans.size()<<"\n";
		for(pair<int,int>p:ans)cout<<p.first+1<<" "<<p.second<<"\n";
	}
}