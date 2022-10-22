#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int Maxn = 5005;
const int Maxl = 26;
const int Maxm = 10005;

string s1, s2;
vector <int> va[Maxl], vb[Maxl];
vector <int> ha[Maxm], hb[Maxm];
int ra[Maxn], rb[Maxn];

bool Check(int len)
{
	if (len == 1)
		for (int i = 0; i < Maxl; i++) {
			for (int j = 0; j < va[i].size(); j++)
				ha[0].push_back(va[i][j]);
			for (int j = 0; j < vb[i].size(); j++)
				hb[0].push_back(vb[i][j]);
		}
	else {
		for (int i = 0; i < Maxl; i++) {
			for (int j = 0; j < va[i].size(); j++) {
				int ind = va[i][j];
				if (ind >= len - 1) ha[ra[ind - 1]].push_back(ind);
			}
			for (int j = 0; j < vb[i].size(); j++) {
				int ind = vb[i][j];
				if (ind >= len - 1) hb[rb[ind - 1]].push_back(ind);
			}
		}
	}
	int cur = 0;
	for (int i = 0; i < Maxm; i++) {
		int l = 0, r = 0;
		while (l < ha[i].size() || r < hb[i].size()) {
			char mn;
			if (l < ha[i].size() && (r == hb[i].size() || s1[ha[i][l]] <= s2[hb[i][r]]))
				mn = s1[ha[i][l]];
			else mn = s2[hb[i][r]];
			int cnt1 = 0, cnt2 = 0;
			while (l < ha[i].size() && s1[ha[i][l]] == mn) {
				cnt1++; ra[ha[i][l]] = cur; l++;
			}
			while (r < hb[i].size() && s2[hb[i][r]] == mn) {
				cnt2++; rb[hb[i][r]] = cur; r++;
			}
			if (cnt1 == 1 && cnt2 == 1) return true;
			cur++;
		}
		ha[i].clear(); hb[i].clear();
	}
}

int main()
{
	cin >> s1 >> s2;
	for (int i = 0; i < s1.length(); i++)
		va[s1[i] - 'a'].push_back(i);
	for (int i = 0; i < s2.length(); i++)
		vb[s2[i] - 'a'].push_back(i);
	for (int i = 1; i < Maxn; i++)
		if (Check(i)) { printf("%d\n", i); return 0; }
	printf("-1\n");
	return 0;
}