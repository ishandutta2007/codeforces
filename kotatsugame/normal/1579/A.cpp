#include<iostream>
using namespace std;
int t;
string S;
main()
{
	cin>>t;
	for(;t--;)
	{
		cin>>S;
		int a=0,b=0,c=0;
		for(char d:S)
		{
			if(d=='A')a++;
			else if(d=='B')b++;
			else if(d=='C')c++;
		}
		cout<<(a+c==b?"YES\n":"NO\n");
	}
}