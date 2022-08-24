#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>


typedef long long ll;
typedef long double ld;

using namespace std;

const int MX = 1000010;

int fl[MX];
int go[MX][26];

int n, m;
string s;
string t[101000];
pair<int, int> gg[12000];
int cnt = 1;

int newn() {
	fl[cnt] = -1;
	return cnt++;
}

void add(const string& s, int x) {
	int now = 0;
	for (int i = 0; i < (int)s.size(); ++i) {
		char c = tolower(s[i]);
		if (go[now][c - 'a'])
			now = go[now][c - 'a'];
		else
			now = go[now][c - 'a'] = newn();
	}
	fl[now] = x;
}

int main() {
	fl[0] = -1;
	ios_base::sync_with_stdio(false);
	cin >> n;
	cin >> s;
	cin >> m;
	for (int i = 0; i < m; ++i) {
		cin >> t[i];
		reverse(t[i].begin(), t[i].end());
		add(t[i], i);
		reverse(t[i].begin(), t[i].end());
	}

	for (int i = 0; i < n; ++i)
		gg[i] = make_pair(-1, -1);
	gg[n] = make_pair(n, -1);
	for (int i = n - 1; i >= 0; --i) {
		int now = 0;
		for (int j = i; j < n; ++j) {
			if (go[now][s[j] - 'a'])
				now = go[now][s[j] - 'a'];
			else
				break;
			if (fl[now] != -1 && gg[j + 1].first != -1) {
				gg[i] = make_pair(j + 1, fl[now]);
				break;
			}
		}
	}

	int now = 0;
	int ff = 0;
	while (now < n) {
		if (ff != 0)
			cout << " ";
		ff = 1;
		cout << t[gg[now].second];
		now = gg[now].first;
	}
	return 0;
}