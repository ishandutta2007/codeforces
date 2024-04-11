#include<iostream>
#include<algorithm>
using namespace std;
int T;
int A[3];
main()
{
	cin>>T;
	for(;T--;)
	{
		cin>>A[0]>>A[1]>>A[2];
		sort(A,A+3);
		bool f=A[0]+A[1]==A[2];
		f=f||A[0]==A[1]&&A[2]%2==0;
		f=f||A[0]==A[2]&&A[1]%2==0;
		f=f||A[1]==A[2]&&A[0]%2==0;
		cout<<(f?"YES\n":"NO\n");
	}
}