#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
using namespace std;
typedef long long ll;

int main() {
	/*ifstream in("input.txt");
	ofstream out("output.txt");*/

	string s;
	ll i, j, k, a, b, c;
	cin >> s;
	for (i = 0; i < s.size(); i++)
		s[i] -= '0';
	for (i = -1; i < s.size(); i++)
		for (j = i + (i >= 0); j < s.size(); j++)
			for (k = j + 1; k < s.size(); k++) {
				a = (i == -1 ? 0 : s[i]);
				b = (j == -1 ? 0 : s[j]);
				c = s[k];
				if (!(((a << 2) + (b << 1) + c) % 8)) {
					cout << "YES\n";
					if (a)
						cout << a << b << c;
					else
						if (b)
							cout << b << c;
						else
							cout << c;
					return 0;
				}
			}

	cout << "NO";
	return 0;
}