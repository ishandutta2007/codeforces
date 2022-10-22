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

string s;
int best[3][2], len[3];
int ans;
string wth;

int Get(const string &s)
{
	int pnt = 0;
	while (pnt + 1 < s.length() && s[pnt] == '0') pnt++;
	return pnt;
}

int main()
{
	cin >> s;
	int md = 0;
	for (int i = s.length() - 1; i >= 0; i--)
		if ((s[i] - '0') % 3 == 1) {
			if (len[1] < 2) best[1][len[1]++] = i;
			md = (md + 1) % 3;
		} else if ((s[i] - '0') % 3 == 2) {
			if (len[2] < 2) best[2][len[2]++] = i;
			md = (md + 2) % 3;
		}
	ans = s.length() + 1;
	if (md == 0) { printf("%s\n", s.c_str()); return 0; }
	else if (md == 1) {
		if (len[1] >= 1) {
			string tmp = s; tmp.erase(tmp.begin() + best[1][0]);
			int cand = 1 + Get(tmp);
			if (cand < ans) { ans = cand; wth = tmp; }
		}
		if (len[2] >= 2) {
			string tmp = s; tmp.erase(tmp.begin() + best[2][0]); tmp.erase(tmp.begin() + best[2][1]);
			int cand = 2 + Get(tmp);
			if (cand < ans) { ans = cand; wth = tmp; }
		}
	} else if (md == 2) {
		if (len[2] >= 1) {
			string tmp = s; tmp.erase(tmp.begin() + best[2][0]);
			int cand = 1 + Get(tmp);
			if (cand < ans) { ans = cand; wth = tmp; }
		}
		if (len[1] >= 2) {
			string tmp = s; tmp.erase(tmp.begin() + best[1][0]); tmp.erase(tmp.begin() + best[1][1]);
			int cand = 2 + Get(tmp);
			if (cand < ans) { ans = cand; wth = tmp; }
		}
	}
	if (ans >= s.length()) printf("-1\n");
	else {
		int pnt = 0;
		while (pnt + 1 < wth.length() && wth[pnt] == '0') pnt++;
		printf("%s\n", wth.substr(pnt).c_str());
	}
	return 0;
}