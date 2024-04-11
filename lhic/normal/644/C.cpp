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
#include <unordered_map>
#include <queue>


typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

mt19937_64 rnd(100);

char buf[100];
int n;
ull gg[120000];
int cnt;

unordered_map<string, int> mm;
unordered_map<ull, vector<string> > mm2;
unordered_map<string, vector<int> > vv;



int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf(" %s", buf);
		string s, t;
		t = "*";
		int cnt2 = 0;
		int l = strlen(buf);
		for (int j = 0; j < l; ++j) {
			if (buf[j] == '/')
				++cnt2;
			if (cnt2 < 3)
				s += buf[j];
			else
				t += buf[j];
		}
		int go = 0;
		if (!mm.count(t))
			go = mm[t] = cnt++;
		else
			go = mm[t];
		vv[s].push_back(go);
	}
	for (int i = 0; i < cnt; ++i)
		gg[i] = rnd();
	for (auto &i: vv) {
		sort(i.second.begin(), i.second.end());
		i.second.resize(unique(i.second.begin(), i.second.end()) - i.second.begin());
		ull hsh = 0;
		for (int j: i.second)
			hsh ^= gg[j];
		mm2[hsh].push_back(i.first);
	}
	int ans = 0;
	for (auto i: mm2) {
		if ((int)i.second.size() >= 2)
			++ans;
	}
	printf("%d\n", ans);
	for (auto i: mm2) {
		if ((int)i.second.size() < 2)
			continue;
		for (auto j: i.second)
			printf("%s ", j.c_str());
		printf("\n");
	}
	return 0;
}