#include <bits/stdc++.h>

typedef long long ll;
typedef long long llong;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;

/*
ll pw(ll a, ll b) {
	ll ans = 1; while (b) {
		while (!(b & 1)) b >>= 1, a = (a * a) % MOD;
		ans = (ans * a) % MOD, --b;
	} return ans;
}
*/

char s[210000];
int n;
ll t;

void add(int x) {
	s[x] = 0;
	int pr = x - 1;
	if (s[x - 1] == '.')
		s[x - 1] = 0, --pr;
	while (s[pr] == '9')
		s[pr] = '0', --pr;
	++s[pr];
}

int main() {
	scanf("%d%lld", &n, &t);
	scanf(" %s", s + 1);
	s[0] = '0';
	++n;
	int fl = 0;
	int st = -1;
	int sg = -1;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '.')
			fl = 1, sg = i;
		else {
			if (fl) {
				if (s[i] >= '5') {
					st = i;
					break;
				}
			}
		}
	}
	--t;
	if (st != -1) {
		add(st);
		for (int i = st - 1; i >= 0; --i) {
			if (isdigit(s[i]) && t > 0 && s[i] >= '5' && i > sg) {
				--t;
				add(i);
			}
		}
	}
	if (s[0] == '0')
		printf("%s\n", s + 1);
	else
		printf("%s\n", s);
	return 0;
}