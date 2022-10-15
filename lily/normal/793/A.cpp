/* Never Say Die. */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <ctime>
#include <cstdlib>
#include <queue>
#include <map>
#include <set>
#include <bitset>
#include <cassert>
using namespace std;
typedef long long LL;
typedef long double LD;

long long n, k;
long long sum, l, mi;


int main() {
	cin >> n >> k;
	long long ai;
	for (int i = 1; i <= n; i++) {
		cin >> ai;
		if (i == 1) l = ai % k, mi = ai / k;
		else if (l != ai % k) return puts("-1"), 0;
		sum += ai / k;
		mi = min(mi, ai / k);
	}
	cout << sum - mi * n << endl;
	return 0;
}