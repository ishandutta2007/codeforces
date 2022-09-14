#include<iostream>
using namespace std;
int T;
long long X,N;
main()
{
	cin>>T;
	for(;T--;)
	{
		cin>>X>>N;
		long long T=N/4*4;
		while(T<N)
		{
			T++;
			if(X%2==0)X-=T;
			else X+=T;
		}
		cout<<X<<"\n";
	}
}