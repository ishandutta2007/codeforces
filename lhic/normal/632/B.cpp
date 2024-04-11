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

int n;
ll p[600000];
char s[600000];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%lld", p + i);
	scanf(" %s", s);
	ll sa = 0;
	ll sb = 0;
	for (int i = 0; i < n; ++i)
		if (s[i] == 'A')
			sa += p[i];
		else
			sb += p[i];
	ll ans = max(sa, sb);
	ll na = 0;
	ll nb = 0;
	for (int i = 0; i < n; ++i) {
		if (s[i] == 'A')
			na += p[i];
		else
			nb += p[i];
		ll xa = sa - na;
		ll xb = sb - nb;
		ans = max(ans, max(na + xb, nb + xa));
	}
	cout << ans << "\n";
	return 0;
}