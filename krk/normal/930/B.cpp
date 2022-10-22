#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

const int Maxl = 26;

string s;
vector <int> my[Maxl];
int has[Maxl];
ld res;

int main()
{
	cin >> s;
	for (int i = 0; i < s.length(); i++)
		my[s[i] - 'a'].push_back(i);
	for (int i = 0; i < Maxl; i++) if (!my[i].empty()) {
		int mx = 0;
		for (int j = 1; j < s.length(); j++) {
			int mask = 0;
			for (int l = 0; l < my[i].size(); l++) {
				int ind = my[i][l];
				int oth = (ind + j) % int(s.length());
				has[s[oth] - 'a'] = 0;
				mask |= 1 << int(s[oth] - 'a');
			}
			for (int l = 0; l < my[i].size(); l++) {
				int ind = my[i][l];
				int oth = (ind + j) % int(s.length());
				has[s[oth] - 'a']++;
			}
			int res = 0;
			while (mask) {
				int b = __builtin_popcount((mask & -mask) - 1);
				res += has[b] == 1;
				mask ^= 1 << b;
			}
			mx = max(mx, res);
		}
		res += mx / ld(s.length());
	}
	cout << fixed << setprecision(10) << res << endl;
	return 0;
}