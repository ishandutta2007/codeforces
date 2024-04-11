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

char t[210000];
char p[210000];
int a[210000];
int en[210000];

int main() {
	scanf("%s %s", t, p);
	int n = strlen(t);
	int m = strlen(p);
	for (int i = 0; i < n; ++i)
		scanf("%d", a + i), --a[i];
	int l = 0;
	int r = n;
	while (r - l > 1) {
		int mid = (l + r) >> 1;
		memset(en, 0, sizeof(en));
		for (int i = 0; i < mid; ++i)
			en[a[i]] = 1;
		int now = 0;
		for (int i = 0; i < n; ++i) {
			if (en[i])
				continue;
			if (now != m && p[now] == t[i])
				++now;
		}
		if (now == m)
			l = mid;
		else
			r = mid;
	}
	cout << l << "\n";
	return 0;
}