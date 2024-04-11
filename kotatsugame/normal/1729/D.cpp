#include<iostream>
#include<deque>
#include<algorithm>
using namespace std;
int N,X[1<<17],Y[1<<17];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		cin>>N;
		for(int i=0;i<N;i++)cin>>X[i];
		for(int i=0;i<N;i++)cin>>Y[i];
		deque<int>Q;
		for(int i=0;i<N;i++)Q.push_back(Y[i]-X[i]);
		sort(Q.begin(),Q.end());
		int ans=0;
		while(Q.size()>=2)
		{
			int l=Q.front(),r=Q.back();
			if(l+r>=0)
			{
				ans++;
				Q.pop_front();
				Q.pop_back();
			}
			else Q.pop_front();
		}
		cout<<ans<<"\n";
	}
}