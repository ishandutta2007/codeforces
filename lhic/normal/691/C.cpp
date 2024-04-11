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

const int MAXN = 1200000;
char s[MAXN];

int main() {
	scanf("%s", s);
	string p;
	string a;
	int n = strlen(s);
	int st = 0;
	int pp = 0;
	for (int i = 0; i < n; ++i) {
		if (pp == 0) {
			if (s[i] == '0') {
				if (!st)
					continue;
				p += s[i];
			}
			else if (s[i] == '.') {
				pp = 1;
			}
			else {
				st = 1;
				p += s[i];
			}
		}
		else {
			a += s[i];
		}
	}
	int cnt = 0;
	if (p == "") {
		for (int i = 0; i < (int)a.size(); ++i) {
			if (a[i] != '0') {
				p = a[i];
				cnt = -(i + 1);
				a = a.substr(i + 1);
				break;
			}
		}
	}
	else {
		a = p.substr(1) + a;
		cnt = p.size() - 1;
		p = p[0];
	}
	printf("%s", p.c_str());
	while (a.back() == '0')
		a.pop_back();
	if (!a.empty()) {
		printf(".%s", a.c_str());
	}
	if (cnt != 0)
		printf("E%d\n", cnt);
	return 0;
}