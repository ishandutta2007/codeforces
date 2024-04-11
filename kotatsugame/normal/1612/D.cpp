#include<iostream>
using namespace std;
int T;
long long A,B,X;
main()
{
	cin>>T;
	for(;T--;)
	{
		cin>>A>>B>>X;
		if(A<B)swap(A,B);
		bool fn=false;
		while(B>0)
		{
			if(A>=X&&(A-X)%B==0)
			{
				fn=true;
				break;
			}
			A%=B;
			swap(A,B);
		}
		cout<<(fn?"YES\n":"NO\n");
	}
}