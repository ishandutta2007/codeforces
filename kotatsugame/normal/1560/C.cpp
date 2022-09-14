#include<iostream>
#include<cmath>
using namespace std;
int T,K;
main()
{
	cin>>T;
	for(;T--;)
	{
		cin>>K;
		int x=sqrt(K);
		while(x*x<K)x++;
		if(x*x-x<K)cout<<x<<" "<<x*x-K+1<<endl;
		else cout<<x-(x*x-K-x)-1<<" "<<x<<endl;
	}
}