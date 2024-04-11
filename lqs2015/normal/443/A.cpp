#include<iostream>
#include<set>
#include<string>
using namespace std;
set<char> s;
string str;
int main()
{
	getline(cin,str);
	for (int i=1;i<str.size();i+=3)
	{
		if (str[i]=='}') break; 
		s.insert(str[i]);
	} 
	cout<<s.size()<<endl;
	return 0;
}