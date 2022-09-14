#include<iostream>
using namespace std;
int N;
main()
{
	cin>>N;
	int s=0;
	for(int i=N;i--;)
	{
		int a;cin>>a;
		s+=a;
	}
	cout<<((N==1?s==1:s+1==N)?"YES":"NO")<<endl;
}