#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

int typ;
string s;

int toInt(const string &s)
{
	stringstream ss(s);
	int n; ss >> n;
	return n;
}

int main()
{
	scanf("%d", &typ);
	cin >> s;
	int h = toInt(s.substr(0, 2)), m = toInt(s.substr(3, 2));
	if (typ == 12) {
		if (h == 0) cout << "01";
		else if (h > 12)
				if (h % 10 == 0) cout << "10";
		 		else cout << "0" + string(1, '0' + h % 10);
		else cout << string(1, '0' + h / 10) + string(1, '0' + h % 10);
		cout << ":";
		if (m > 59) cout << "0" + string(1, '0' + m % 10);
		else cout << string(1, '0' + m / 10) + string(1, '0' + m % 10);
		cout << endl;
	} else {
		if (h >= 24) cout << "0" + string(1, '0' + h % 10);
		else cout << string(1, '0' + h / 10) + string(1, '0' + h % 10);
		cout << ":";
		if (m > 59) cout << "0" + string(1, '0' + m % 10);
		else cout << string(1, '0' + m / 10) + string(1, '0' + m % 10);
		cout << endl;
	}
	return 0;
}