#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int mod1 = 1000000007;
const int mod2 = 1000000009;
const int arg1 = 641;
const int arg2 = 151;
const int Maxn = 1000005;

int n, k;
char str[Maxn];
int pw1, pw2;
ii H[Maxn];
map <ii, int> Has[Maxn];
map <ii, int> G;

bool Check(map <ii, int> &M)
{
	for (map <ii, int>::iterator it = M.begin(); it != M.end(); it++)
		if (it->second > 1) return false;
		else if (G.find(it->first) == G.end()) return false;
	return true;
}

int main()
{
	scanf("%d %d", &n, &k);
	scanf("%s", str);
	pw1 = 1; pw2 = 1;
	for (int i = 0; i < k - 1; i++) {
		pw1 = ll(pw1) * arg1 % mod1;
		pw2 = ll(pw2) * arg2 % mod2;
	}
	ii h = ii(0, 0);
	for (int i = 0; i < k; i++) {
		h.first = (ll(h.first) * arg1 + ll(str[i] - 'a' + 1)) % mod1;
		h.second = (ll(h.second) * arg2 + ll(str[i] - 'a' + 1)) % mod2;
	}
	H[0] = h;
	Has[0][h]++;
	for (int i = 1; i < n * k; i++) {
		h.first = (ll(h.first) - ll(str[i - 1] - 'a' + 1) * pw1 % mod1 + mod1) % mod1;
		h.second = (ll(h.second) - ll(str[i - 1] - 'a' + 1) * pw2 % mod2 + mod2) % mod2;
		int ni = (i + k - 1) % (n * k);
		h.first = (ll(h.first) * arg1 + ll(str[ni] - 'a' + 1)) % mod1;
		h.second = (ll(h.second) * arg2 + ll(str[ni] - 'a' + 1)) % mod2;
		Has[i % k][h]++;
		H[i] = h;
	}
	int g; scanf("%d", &g);
	char cur[Maxn];
	for (int j = 1; j <= g; j++) {
		scanf("%s", cur);
		ii h = ii(0, 0);
		for (int i = 0; i < k; i++) {
			h.first = (ll(h.first) * arg1 + ll(cur[i] - 'a' + 1)) % mod1;
			h.second = (ll(h.second) * arg2 + ll(cur[i] - 'a' + 1)) % mod2;
		}
		G[h] = j;
	}
	for (int j = 0; j < k; j++) if (Check(Has[j])) {
		printf("YES\n");
		for (int i = j; i < n * k; i += k)
			printf("%d%c", G[H[i]], i + k < n * k? ' ': '\n');
		return 0;
	}
	printf("NO\n");
	return 0;
}