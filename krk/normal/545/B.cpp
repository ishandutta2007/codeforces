#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

string s, t;
string res;

int main()
{
	cin >> s;
	cin >> t;
	res = s;
	bool num = false;
	for (int i = 0; i < s.length(); i++)
		if (s[i] != t[i]) {
			res[i] = num? t[i]: s[i];
			num = !num;
		}
	if (num) printf("impossible\n");
	else cout << res << endl;
	return 0;
}