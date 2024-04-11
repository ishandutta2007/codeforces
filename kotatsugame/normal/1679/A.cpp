#include<iostream>
using namespace std;
int T;
long long N;
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N;
		if(N%2==1||N==2)
		{
			cout<<"-1\n";
			continue;
		}
		N/=2;
		long long L,R;
		if(N%2==0)R=N/2;
		else R=1+(N-3)/2;
		if(N%3==0)L=N/3;
		else if((N-2)%3==0)L=1+(N-2)/3;
		else L=2+(N-4)/3;
		cout<<L<<" "<<R<<"\n";
	}
}