#include<iostream>
#include<map>
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
		map<int,int>mp;
		mp[0]=0;
		int cur=0;
		int cummax=0;
		for(int i=0;i<N;i++)
		{
			cur^=A[i];
			if(mp.find(cur)!=mp.end())cummax=max(cummax,mp[cur]+1);
			mp[cur]=cummax;
		}
		cout<<N-cummax<<"\n";
	}
}