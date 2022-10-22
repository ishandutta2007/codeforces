#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int n;
string s;

int main(void)
{
	cin >> n;
	cin >> s;
	sort(s.begin(), s.end());
	cout << s << endl;
	return 0;
}