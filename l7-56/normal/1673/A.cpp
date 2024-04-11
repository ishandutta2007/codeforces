#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const int maxn = 2e5 + 10;
char s[maxn];
int n;
void work() {
	scanf("%s", s + 1); n = strlen(s + 1);
	ll val = 0;
	for (int i = 1; i <= n; ++i) val += s[i] - 'a' + 1;
	if (n % 2 == 0) return printf("Alice %lld\n", val), void();
	ll va = val - (min(s[1], s[n]) - 'a' + 1), vb = val - va;
	if (va > vb) return printf("Alice %lld\n", va - vb), void();
	printf("Bob %lld\n", vb - va);
}

int main() {
	int T; scanf("%d", &T);
	while (T--) work();
	return 0;
}