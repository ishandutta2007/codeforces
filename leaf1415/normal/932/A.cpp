#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string s;

int main(void)
{
	cin >> s;
	string t = s;
	reverse(t.begin(), t.end());
	
	cout << s + t << endl;
	return 0;
}