#include<iostream>
using namespace std;
int T;
main()
{
	cin>>T;
	for(;T--;)
	{
		int N;cin>>N;
		int a=N/3,b=N/3;
		if(N%3==1)a++;
		else if(N%3==2)b++;
		cout<<a<<" "<<b<<endl;
	}
}