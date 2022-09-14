#include<iostream>
#include<algorithm>
using namespace std;
int T,N;
string s;
bool ok(int d)
{
	int R=d;
	for(int i=1;i<=N;i++)
	{
		if(i<=R&&s[i-1]=='R')R=max(R,i+d);
	}
	return R>N;
}
main()
{
	cin>>T;
	for(;T--;)
	{
		cin>>s;
		N=s.size();
		int L=0,R=N+1;
		while(R-L>1)
		{
			int M=(L+R)/2;
			if(ok(M))R=M;
			else L=M;
		}
		cout<<R<<"\n";
	}
}