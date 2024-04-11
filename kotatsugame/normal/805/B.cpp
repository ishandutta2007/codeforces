#include<iostream>
using namespace std;
main()
{
	int n;cin>>n;
	bool f=true;int i=2;
	for(;i<=n;i+=2,f=!f)cout<<(f?"aa":"bb");
	i-=2;if(n-i)cout<<(f?"a":"b");
	cout<<endl;
}