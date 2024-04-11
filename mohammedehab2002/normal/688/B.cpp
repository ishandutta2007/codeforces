#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
int main()
{
	string s;
	cin >> s;
	string rs=s;
	reverse(rs.begin(),rs.end());
	cout << s+rs;
}