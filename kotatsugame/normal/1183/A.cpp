#include<iostream>
using namespace std;
int N;
bool f(int a)
{
	int ret=0;
	while(a)
	{
		ret+=a%10;
		a/=10;
	}
	return ret%4==0;
}
main()
{
	cin>>N;
	while(!f(N))N++;
	cout<<N<<endl;
}