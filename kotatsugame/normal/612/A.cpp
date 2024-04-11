#include<iostream>
using namespace std;
string S;
int N,a,b;
main()
{
	cin>>N>>a>>b>>S;
	for(int i=0;i*a<=N;i++)if((N-i*a)%b==0)
	{
		int j=(N-i*a)/b;
		cout<<i+j<<endl;
		int id=0;
		for(int k=0;k<i;k++)
		{
			cout<<S.substr(id,a)<<endl;
			id+=a;
		}
		for(int k=0;k<j;k++)
		{
			cout<<S.substr(id,b)<<endl;
			id+=b;
		}
		return 0;
	}
	cout<<-1<<endl;
}