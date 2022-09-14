#include<iostream>
using namespace std;
int T,S;
main()
{
	cin>>T;
	for(;T--;)
	{
		cin>>S;
		S--;
		int cnt=1;
		int mx=1;
		while(S>0)
		{
			mx+=2;
			if(mx<=S)
			{
				S-=mx;
				cnt++;
			}
			else
			{
				S=0;
				cnt++;
			}
		}
		cout<<cnt<<endl;
	}
}