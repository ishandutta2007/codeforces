#include<iostream>
using namespace std;
string S;
main()
{
	cin>>S;
	string T="";
	if(S.size()%2==0)
	{
		for(int i=0;i<S.size()/2;i++)
		{
			T+=S[S.size()/2-i-1];
			T+=S[S.size()/2+i];
		}
	}
	else
	{
		T+=S[S.size()/2];
		for(int i=0;i<S.size()/2;i++)
		{
			T+=S[S.size()/2+i+1];
			T+=S[S.size()/2-i-1];
		}
	}
	cout<<T<<endl;
}