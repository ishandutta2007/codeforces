#include<iostream>
using namespace std;
int N,K;
int S[1<<17];
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		cin>>N>>K;
		for(int i=0;i<K;i++)cin>>S[i];
		bool out=false;
		for(int i=0;i+2<K;i++)
		{
			int y=S[i+2]-S[i+1],x=S[i+1]-S[i];
			if(x>y)out=true;
		}
		if(out)
		{
			cout<<"No\n";
			continue;
		}
		if(K==1)
		{
			cout<<"Yes\n";
			continue;
		}
		long long s=S[0],a=S[1]-S[0],c=N-K+1;
		cout<<(a*c>=s?"Yes\n":"No\n");
	}
}