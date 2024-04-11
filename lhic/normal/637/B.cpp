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
#include <unordered_set>


typedef long long ll;
typedef long double ld;

using namespace std;

unordered_set<string> ss;
string s[210000];
char buf[20];
int n;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%s", buf);
		s[i] = buf;
	}
	for (int i = n - 1; i >= 0; --i) {
		if (!ss.count(s[i])) {
			printf("%s\n", s[i].c_str());
			ss.insert(s[i]);
		}
	}
	return 0;
}