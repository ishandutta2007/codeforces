#include<iostream>
using namespace std;
string s;
main()
{
	cin>>s;
	for(int a=1;;a++)
	{
		int b=(s.size()+a-1)/a;
		if(b<=20)
		{
			cout<<a<<" "<<b<<endl;
			int u=a*b-s.size();
			int f=0;
			for(int i=0;i<a;i++)
			{
				int l=b;
				if(i<u)l--;
				cout<<s.substr(f,l);
				if(i<u)cout<<'*';
				cout<<endl;
				f+=l;
			}
			return 0;
		}
	}
}