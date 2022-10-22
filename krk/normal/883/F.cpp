#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;

int n;
string t, s;
set <string> S;

int main()
{
	scanf("%d", &n);
	while (n--) {
		cin >> t;
		s = "";
		for (int i = 0; i < t.length(); i++)
			if (t[i] == 'u') s += "oo";
			else s += t[i];
		bool ch = true;
		while (ch) {
			ch = false;
			for (int i = 0; i + 1 < s.length() && !ch; i++)
				if (s[i] == 'k' && s[i + 1] == 'h') {
					ch = true; s = s.substr(0, i) + "h" + s.substr(i + 2);
				} else if (s[i] == 'o' && s[i + 1] == 'o') {
					ch = true; s = s.substr(0, i) + "u" + s.substr(i + 2);
				}
		}
		S.insert(s);
	}
	printf("%d\n", S.size());
	return 0;
}