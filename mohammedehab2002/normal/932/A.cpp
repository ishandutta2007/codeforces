#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	string s;
	cin >> s;
	string a=s;
	reverse(a.begin(),a.end());
	cout << s << a;
}