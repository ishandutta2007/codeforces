#include<iostream>
#include<iomanip>
using namespace std;
int x[1<<17],t[1<<17];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		int N;cin>>N;
		for(int i=0;i<N;i++)cin>>x[i];
		for(int i=0;i<N;i++)cin>>t[i];
		int L=1e9,R=-1e9;
		for(int i=0;i<N;i++)
		{
			L=min(L,x[i]-t[i]);
			R=max(R,x[i]+t[i]);
		}
		cout<<fixed<<setprecision(16)<<(double)(L+R)/2<<"\n";
	}
}