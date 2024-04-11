#include <iostream>
#include <string.h>
using namespace std;
string func(string s)
{
	if (s.size()%2)
	return s;
	string s1=func(s.substr(0,s.length()/2)),s2=func(s.substr(s.length()/2,s.length()));
	if (s1<s2)
	return s1+s2;
	return s2+s1;
}
int main()
{
	string s1,s2;
	cin >> s1 >> s2;
	if (func(s1)==func(s2))
	cout << "YES";
	else
	cout << "NO";
}