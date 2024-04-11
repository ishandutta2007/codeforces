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

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef long double ld;

using namespace std;

const int MAXN = 220000;
int n;
int s;
int cc[MAXN];
int m;
int fr;

int main() {
	scanf("%d%d", &n, &s);
	--s;
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		int x;
		scanf("%d", &x);
		if (i == s) {
			if (x != 0)
				++ans;
		}
		else {
			if (x == 0)
				++fr, ++ans;
			else
				++cc[x], ++m;
		}
	}
	for (int i = 1; i < n; ++i) {
		if (m <= 0)
			break;
		if (cc[i] != 0) {
			m -= cc[i];
			continue;
		}
		if (fr) {
			--fr;
			continue;
		}
		++ans;
		--m;
	}
	cout << ans << "\n";
	return 0;
}