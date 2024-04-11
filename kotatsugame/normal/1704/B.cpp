#include<iostream>
using namespace std;
int N,X;
int A[2<<17];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		cin>>N>>X;
		for(int i=0;i<N;i++)cin>>A[i];
		int l=1,r=0;
		int ans=0;
		for(int i=0;i<N;i++)
		{
			int nl=A[i]-X,nr=A[i]+X;
			if(l<nl)l=nl;
			if(r>nr)r=nr;
			if(r<l)
			{
				ans++;
				l=nl,r=nr;
			}
		}
		cout<<ans-1<<"\n";
	}
}