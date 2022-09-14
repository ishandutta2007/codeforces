#include<iostream>
using namespace std;
int N,V;
main()
{
	cin>>N>>V;
	int rest=N-1;
	if(V>=rest)
	{
		cout<<rest<<endl;
		return 0;
	}
	int ans=V;
	rest-=V;
	for(int i=2;rest-->0;i++)ans+=i;
	cout<<ans<<endl;
}