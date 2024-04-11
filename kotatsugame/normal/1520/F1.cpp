#include<iostream>
using namespace std;
int N,T,K;
int ask(int l,int r)
{
	cout<<"? "<<l<<" "<<r<<endl;
	int x;cin>>x;
	return x;
}
main()
{
	cin>>N>>T;
	for(;T--;)
	{
		cin>>K;
		int L=0,R=N;
		while(R-L>1)
		{
			int mid=(L+R)/2;
			int x=ask(1,mid);
			if(mid-x>=K)R=mid;
			else L=mid;
		}
		cout<<"! "<<R<<endl;
	}
}