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


#define MAXN 1000005
#define MOD 1000000007

LL ans, tot;

char s[MAXN];

LL power(LL a, LL b) {
	LL ret = 1;
	for ( ; b; b >>= 1) {
		if (b & 1) ret = ret * a % MOD;
		a = a * a % MOD;
	}
	return ret;
}

int main() {
	scanf("%s" , s + 1);
	int n = int(strlen(s + 1));
	for (int i = 1; i <= n; i++) {
		if (s[i] == 'a') tot++;
		else {
			(ans += power(2, tot) - 1) %= MOD;
		}
	}
	cout << (ans + MOD) % MOD << endl;
	return 0;
}