#include<iostream>
using namespace std;
string S;
bool f(char c)
{
	static const string T="AHIMOoTUVvWwXxY";
	for(char d:T)if(d==c)return true;
	return false;
}
main()
{
	cin>>S;
	for(int i=0;i<S.size();i++)
	{
		int j=S.size()-i-1;
		if(S[i]==S[j]&&f(S[i]));
		else if(S[i]=='b'&&S[j]=='d'||S[i]=='d'&&S[j]=='b'||S[i]=='p'&&S[j]=='q'||S[i]=='q'&&S[j]=='p');
		else
		{
			puts("NIE");
			return 0;
		}
	}
	puts("TAK");
}