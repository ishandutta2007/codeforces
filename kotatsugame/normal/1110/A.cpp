#include<iostream>
using namespace std;
int b,k,a,s;
main()
{
	cin>>b>>k;
	for(int i=0;i<k;i++)
	{
		cin>>a;
		s=(s*b+a)%2;
	}
	cout<<(s>0?"odd":"even")<<endl;
}