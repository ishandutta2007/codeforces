#include<iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		int N,H,M;
		cin>>N>>H>>M;
		int ans=1e9;
		for(int i=0;i<N;i++)
		{
			int h,m;
			cin>>h>>m;
			int d=(h*60+m)-(H*60+M);
			if(d<0)d+=24*60;
			ans=min(ans,d);
		}
		cout<<ans/60<<" "<<ans%60<<"\n";
	}
}