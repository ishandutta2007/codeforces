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
typedef double ld;

using namespace std;

int n;
char s[300000];
int cnt[100];

int main() {
	scanf("%s", s);
	n = strlen(s);
	for (int i = 0; i < n; ++i)
		++cnt[s[i] - 'a'];
	int cc = 0;
	vector<int> vv;
	for (int i = 0; i < 26; ++i)
		if (cnt[i] % 2)
			++cc, vv.push_back(i);
	for (int i = 0; i < cc / 2; ++i) {
		++cnt[vv[i]];
		--cnt[vv[cc - 1 - i]];
	}

	if (n % 2 == 0) {
		string s2 = "";
		for (int i = 0; i < 26; ++i) {
			cnt[i] /= 2;
			for (int j = 0; j < cnt[i]; ++j)
				s2 += (char)('a' + i);
		}
		cout << s2;
		reverse(s2.begin(), s2.end());
		cout << s2 << "\n";
	}
	else {
		string s2 = "";
		int go = 0;
		for (int i = 0; i < 26; ++i) {
			if (cnt[i] % 2 == 1)
				go = i;
			cnt[i] /= 2;
			for (int j = 0; j < cnt[i]; ++j)
				s2 += (char)('a' + i);
		}
		cout << s2;
		reverse(s2.begin(), s2.end());
		cout << (char)('a' + go);
		cout << s2 << "\n";
	}
	return 0;
}