#include <iostream>
#include <string.h>
using namespace std;
string func(string s)
{
	string ans1,ans2;
	if (s.length()%2)
	return s;
	ans1=func(s.substr(0,s.length()/2));
	ans2=func(s.substr(s.length()/2,s.length()));
	if (ans1<ans2)
	return ans1+ans2;
	return ans2+ans1;
}
int main()
{
	string a,b;
	cin >> a >> b;
	a=func(a);
	b=func(b);
	if (a==b)
	cout << "YES";
	else
	cout << "NO";
}