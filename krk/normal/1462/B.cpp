#include <bits/stdc++.h>
using namespace std;

int T;
int n;
string s;

int main()
{
	cin >> T;
	while (T--) {
		cin >> n;
		cin >> s;
		if (s.substr(int(s.length()) - 4) == "2020" ||
			s.substr(0, 1) == "2" && s.substr(int(s.length()) - 3) == "020" ||
			s.substr(0, 2) == "20" && s.substr(int(s.length()) - 2) == "20" ||
			s.substr(0, 3) == "202" && s.substr(int(s.length()) - 1) == "0" ||
			s.substr(0, 4) == "2020") printf("YES\n");
		else printf("NO\n");
	}
    return 0;
}