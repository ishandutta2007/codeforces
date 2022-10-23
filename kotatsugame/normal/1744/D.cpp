#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		cin>>N;
		int all=0;
		vector<int>T;T.reserve(N);
		for(int i=1;i<=N;i++)
		{
			int A;cin>>A;
			while(A%2==0)A/=2,all++;
			int t=i;
			T.push_back(0);
			while(t%2==0)t/=2,T.back()++;
		}
		sort(T.begin(),T.end());
		int ans=0;
		for(int i=N;i--;)if(all<N)
		{
			all+=T[i];
			ans++;
		}
		cout<<(all<N?-1:ans)<<"\n";
	}
}