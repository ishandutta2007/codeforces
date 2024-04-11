#include<iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		int N,K;
		cin>>N>>K;
		bool fn=false;
		for(int i=0;i<N;i++)
		{
			int A;cin>>A;
			if(A==1)fn=true;
		}
		cout<<(fn?"YES\n":"NO\n");
	}
}