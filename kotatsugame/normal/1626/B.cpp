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
		int id=S.size()-1;
		while(id>=1&&(S[id-1]-'0')+(S[id]-'0')<10)id--;
		if(id==0)
		{
			S[1]+=S[0]-'0';
			cout<<S.substr(1)<<"\n";
		}
		else
		{
			int t=(S[id-1]-'0')+(S[id]-'0');
			S[id-1]=t/10+'0';
			S[id]=t%10+'0';
			cout<<S<<"\n";
		}
	}
}