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
		if(S.size()%2==1)
		{
			cout<<"NO"<<endl;
			continue;
		}
		int cnt=S.size()-2;
		int now=0;
		for(int i=0;i<S.size();i++)if(S[i]=='?')
		{
			if(now*2<cnt)S[i]='(';
			else S[i]=')';
			now++;
		}
		bool ok=true;
		int ret=0;
		for(int i=0;i<S.size();i++)
		{
			if(S[i]=='(')ret++;
			else ret--;
			if(ret<0)ok=false;
		}
		cout<<(ok&&ret==0?"YES":"NO")<<endl;
	}
}