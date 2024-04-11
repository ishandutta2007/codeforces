#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main()
{
	string a,b;
	cin >> a >> b;
	reverse (b.begin(),b.end());
	if (a==b)
	cout << "YES";
	else
	cout << "NO";
}