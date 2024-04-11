#include <iostream>
#include <string.h>
#include <sstream>
using namespace std;
string f()
{
	string s="";
	int i=1;
	while (s.size()<1001)
	{
		stringstream a;
		a << i;
		s+=a.str();
		i++;
	}
	return s;
}
int main()
{
	int n;
	cin >> n;
	string s=f();
	cout << s[n-1];
}