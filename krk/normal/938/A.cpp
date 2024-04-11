#include <bits/stdc++.h>
using namespace std;

const string wovs = "aeiouy";

int n;
string s;

int main()
{
	cin >> n;
	cin >> s;
	bool ch = true;
	while (ch) {
		ch = false;
		for (int i = 1; i < s.length() && !ch; i++)
			if (wovs.find(s[i]) != string::npos && wovs.find(s[i - 1]) != string::npos) {
				s.erase(s.begin() + i); ch = true;
			}
	}
	cout << s << endl;
	return 0;
}