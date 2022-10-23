#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N,A[1<<17];
int X[1<<17];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		cin>>N;
		for(int i=0;i<N;i++)cin>>A[i];
		vector<pair<int,int> >T;
		for(int i=1;i<N;i++)if(A[i-1]>A[i])
		{
			T.push_back(make_pair(A[i-1]-A[i],i+1));
		}
		sort(T.begin(),T.end());
		for(int i=N;i>=1;i--)
		{
			if(!T.empty())
			{
				X[i]=T.back().second;
				T.pop_back();
			}
			else
			{
				X[i]=1;
			}
		}
		for(int i=1;i<=N;i++)cout<<X[i]<<(i==N?"\n":" ");
	}
}