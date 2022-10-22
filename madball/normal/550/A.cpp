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
	ll i, j;
	bool res = false;
	vector<ll> ab;
	vector<ll> ba;
	cin >> s;
	for (i = 0; i < s.size() - 1; i++) {
		if ((s[i] == 'A') && (s[i + 1] == 'B'))
			ab.push_back(i);
		if ((s[i] == 'B') && (s[i + 1] == 'A'))
			ba.push_back(i);
		if ((ab.size() > 3) && (ba.size()) > 3)
			res = true;
	}

	if (!res)
		for (i = 0; i < ab.size(); i++)
			for (j = 0; j < ba.size(); j++)
				if (abs(ab[i] - ba[j]) > 1)
					res = true;

	if (res)
		cout << "YES";
	else
		cout << "NO";
	return 0;
}