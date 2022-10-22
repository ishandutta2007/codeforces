#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <queue>
#include <iomanip>
#include <algorithm>
using namespace std;

const int Maxb = 16;
const int Maxn = 205;

int n;
string s[Maxn];
string beg[Maxn], en[Maxn];
set <int> has[Maxn][Maxb + 1];
int m;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
		if (s[i].length() <= Maxb) beg[i] = en[i] = s[i];
		else { beg[i] = s[i].substr(0, Maxb); en[i] = s[i].substr(int(s[i].length()) - Maxb); }
		for (int j = 1; j <= Maxb && j <= s[i].length(); j++) {
			int mask = 0;
			for (int k = 0; k < j - 1; k++) {
				mask <<= 1; mask |= int(s[i][k] == '1');
			}
			for (int k = j - 1; k < s[i].length(); k++) {
				mask <<= 1; mask |= int(s[i][k] == '1');
				has[i][j].insert(mask);
				mask = mask & ((1 << j - 1) - 1);
			}
		}
	}
	scanf("%d", &m);
	for (int i = n + 1; i <= n + m; i++) {
		int a, b; scanf("%d %d", &a, &b);
		beg[i] = beg[a] + beg[b];
		en[i] = en[a] + en[b];
		if (beg[i].length() > Maxb) beg[i] = beg[i].substr(0, Maxb);
		if (en[i].length() > Maxb) en[i] = en[i].substr(int(en[i].length()) - Maxb);
		for (int j = 1; j <= Maxb; j++)
			set_union(has[a][j].begin(), has[a][j].end(), has[b][j].begin(), has[b][j].end(), inserter(has[i][j], has[i][j].begin()));
		string tmp = en[a] + beg[b];
		for (int j = 1; j <= Maxb && j <= tmp.length(); j++) {
			int mask = 0;
			for (int k = 0; k < j - 1; k++) {
				mask <<= 1; mask |= int(tmp[k] == '1');
			}
			for (int k = j - 1; k < tmp.length(); k++) {
				mask <<= 1; mask |= int(tmp[k] == '1');
				has[i][j].insert(mask);
				mask = mask & ((1 << j - 1) - 1);
			}
		}
		int val = 1;
		while (val <= Maxb && has[i][val].size() == (1 << val)) val++;
		val--;
		printf("%d\n", val);
	}
	return 0;
}