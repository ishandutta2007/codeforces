#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
int main()
{
	bool b1=false,b2=false;
	string a,b;
	cin >> a >> b;
	if (count(a.begin(),a.end(),'1'))
	b1=true;
	if (count(b.begin(),b.end(),'1'))
	b2=true;
	if (a.size()==1)
	b1=false;
	if (a.size()!=b.size())
	b1=false;
	if (a==b)
	b1=b2=true;
	if (b1 && b2)
	cout << "YES";
	else
	cout << "NO";
}