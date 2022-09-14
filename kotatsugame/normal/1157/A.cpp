#include<iostream>
#include<map>
using namespace std;
string s;
main()
{
	cin>>s;
	map<string,bool>M;
	while(!M[s])
	{
		M[s]=1;
		if(s[s.size()-1]!='9')
		{
			s[s.size()-1]++;
		}
		else
		{
			while(s.size()>0&&s[s.size()-1]=='9')
			{
				s.pop_back();
			}
			if(s.size()==0)s.push_back('1');
			else s[s.size()-1]++;
		}
	}
	cout<<M.size()<<endl;
}