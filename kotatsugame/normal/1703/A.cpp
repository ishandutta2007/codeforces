#include<iostream>
using namespace std;
string S;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin>>T;
	for(;T--;)
	{
		cin>>S;
		cout<<((S[0]=='Y'||S[0]=='y')&&(S[1]=='E'||S[1]=='e')&&(S[2]=='S'||S[2]=='s')?"YES\n":"NO\n");
	}
}