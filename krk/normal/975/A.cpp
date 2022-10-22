#include <bits/stdc++.h>
using namespace std;

int n;
string s;
set <int> S;

int main()
{
	cin >> n;
	while (n--) {
		cin >> s;
		int mask = 0;
		for (int i = 0; i < s.length(); i++)
			mask |= 1 << int(s[i] - 'a');
		S.insert(mask);
	}
	cout << S.size() << endl;
	return 0;
}