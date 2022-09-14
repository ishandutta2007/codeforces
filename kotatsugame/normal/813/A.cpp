#include<iostream>
using namespace std;
int N,M;
main()
{
	cin>>N;
	int S=0;
	for(int i=0;i<N;i++)
	{
		int A;cin>>A;
		S+=A;
	}
	cin>>M;
	int ans=1e9;
	for(int i=0;i<M;i++)
	{
		int l,r;cin>>l>>r;
		if(S<=r)
		{
			if(l<S)l=S;
			if(ans>l)ans=l;
		}
	}
	if(ans==(int)1e9)ans=-1;
	cout<<ans<<endl;
}