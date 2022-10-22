#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 100005;

ll n;
int q;
ll u;
char str[Maxn];

int main()
{
	scanf("%I64d %d", &n, &q);
	while (q--) {
		scanf("%I64d", &u); 
		scanf("%s", str); int slen = strlen(str);
		ll lvl = 0;
		while (!(u & 1ll << lvl)) lvl++;
		for (int i = 0; i < slen; i++)
			if (str[i] == 'L') {
				if (lvl != 0) {
					u ^= 1ll << lvl; u ^= 1ll << lvl - 1ll;
					lvl--;
				}
			} else if (str[i] == 'R') {
				if (lvl != 0) {
					u ^= 1ll << lvl - 1ll;
					lvl--;
				}
			} else if (str[i] == 'U') {
				ll nxt = u;
				nxt ^= 1ll << lvl; nxt |= 1ll << lvl + 1ll;
				if (nxt <= n) { u = nxt; lvl++; }
			}
		printf("%I64d\n", u);
	}
	return 0;
}