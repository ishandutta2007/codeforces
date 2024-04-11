#include<iostream>
#include<map>
using namespace std;
int T,N,K;
map<int,int>L,R;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N>>K;
		L.clear();
		R.clear();
		for(int i=0;i<N;i++)
		{
			int u;cin>>u;
			R[u]=i;
			if(L.find(u)==L.end())L[u]=i;
		}
		for(;K--;)
		{
			int a,b;cin>>a>>b;
			int l=L.find(a)==L.end()?N:L[a];
			int r=R.find(b)==R.end()?-1:R[b];
			cout<<(l<=r?"Yes\n":"No\n");
		}
	}
}