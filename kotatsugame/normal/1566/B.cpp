#include<iostream>
using namespace std;
int T;
string S;
main()
{
	cin>>T;
	for(;T--;)
	{
		cin>>S;
		int id=0;
		while(id<S.size()&&S[id]!='0')id++;
		if(id==S.size())cout<<"0\n";
		else
		{
			while(id<S.size()&&S[id]=='0')id++;
			while(id<S.size()&&S[id]!='0')id++;
			if(id==S.size())cout<<"1\n";
			else cout<<"2\n";
		}
	}
}