#include<iostream>
using namespace std;
string a,b,c;
int T;
main()
{
	cin>>T;
	for(;T--;)
	{
		cin>>a>>b>>c;
		bool flag=true;
		for(int i=0;i<a.size();i++)
		{
			if(!(a[i]==c[i]||b[i]==c[i]))flag=false;
		}
		cout<<(flag?"YES":"NO")<<endl;
	}
}