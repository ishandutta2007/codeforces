#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
using namespace std;
typedef long long ll;

int main() {
	/*(ifstream in("input.txt");
	ofstream out("output.txt");*/
	ll n, l, r, i;
	cin >> n;
	string s, t;
	cin >> s >> t;
	for (l = 0; s[l] == t[l]; l++);
	for (r = n - 1; s[r] == t[r]; r--);

	bool succ = true;
	char c1, c2;
	c1 = s[l];
	c2 = t[l];
	for (i = l + 1; i <= r; i++) {
		swap(c1, c2);
		if ((s[i] != c1) || (t[i] != c2))
			succ = false;
	}
	if (succ)
		cout << 2;
	else {
		bool s1 = true, s2 = true, ss = false;
		for (i = l; i < r; i++)
			if (s[i] != t[i + 1])
				s1 = false;
		for (i = l; i < r; i++)
			if (t[i] != s[i + 1])
				s2 = false;
		if (s1 || s2)
			cout << 1;
		else
			cout << 0;
	}
	return 0;
}