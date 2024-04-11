#include<iostream>
using namespace std;
int T;
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		string s;cin>>s;
		int c=0;
		for(int i=0;i<6;i++)
		{
			int d=s[i]-'0';
			if(i<3)c+=d;
			else c-=d;
		}
		cout<<(c?"NO\n":"YES\n");
	}
}