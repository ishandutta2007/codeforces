#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int Maxn = 200005;
const int Maxl = 26;
const int mod1 = 1000000007;
const int mod2 = 1000000009;
const int arg1 = 15485863;
const int arg2 = 1000007;

int pw1[Maxn], pw2[Maxn];
int n, m;
char str[Maxn];
ii H[Maxl][Maxn];

ii Get(ii H[], int lef, int rig)
{
	ii my = H[rig];
	lef--;
	if (lef >= 0) {
		my.first = (my.first - ll(H[lef].first) * pw1[rig - lef] % mod1 + mod1) % mod1;
		my.second = (my.second - ll(H[lef].second) * pw2[rig - lef] % mod2 + mod2) % mod2;
	}
	return my;
}

int main()
{
	pw1[0] = pw2[0] = 1;
	for (int i = 1; i < Maxn; i++) {
		pw1[i] = ll(pw1[i - 1]) * arg1 % mod1;
		pw2[i] = ll(pw2[i - 1]) * arg2 % mod2;
	}
	scanf("%d %d", &n, &m);
	scanf("%s", str + 1);
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < Maxl; j++) {
			H[j][i].first = (ll(H[j][i - 1].first) * arg1 + ll(1 + ('a' + j == str[i]))) % mod1;
			H[j][i].second = (ll(H[j][i - 1].second) * arg2 + ll(1 + ('a' + j == str[i]))) % mod2;
		}
	while (m--) {
		int x, y, len; scanf("%d %d %d", &x, &y, &len);
		multiset <ii> A, B;
		for (int i = 0; i < Maxl; i++) {
			A.insert(Get(H[i], x, x + len - 1));
			B.insert(Get(H[i], y, y + len - 1));
		}
		printf("%s\n", A == B? "YES": "NO");
	}
	return 0;
}