#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	size_t pos;
	int i;
	string s;
	cin >> s;
	if (s[0]=='h')
	{
		cout << "http://";
		for (i=0;i<4;i++)
		s.erase(s.begin());
	}
	else
	{
		cout << "ftp://";
		for (i=0;i<3;i++)
		s.erase(s.begin());
	}
	pos=s.find("ru");
	if (pos==0)
	{
		cout << "ru";
		s.erase(s.begin());
		s.erase(s.begin());
	}
	pos=s.find("ru");
	for (i=0;i<pos;i++)
	cout << s[i];
	cout << ".ru";
	if (pos!=s.size()-2)
	cout << '/';
	for (i=pos+2;i<s.size();i++)
	cout << s[i];
}