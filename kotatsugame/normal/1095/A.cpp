#include<iostream>
using namespace std;
main()
{
	int N;
	string S;
	cin>>N>>S;
	string T="";
	for(int i=0;i<N;)
	{
		T+=S[i];
		i+=T.size();
	}
	cout<<T<<endl;
}