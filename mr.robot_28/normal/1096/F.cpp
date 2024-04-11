#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

const int N = 200 * 1000 + 13;
const int MOD = 998244353;

int n;
int p[N];
bool used[N];
int gt[N];

int add(int a, int b){
	a += b;
	if (a >= MOD)
		a -= MOD;
	return a;
}

int mul(int a, int b){
	return (a * 1ll * b) % MOD;
}

int binpow(int a, int b){
	int res = 1;
	while (b){
		if (b & 1)
			res = mul(res, a);
		a = mul(a, a);
		b >>= 1;
	}
	return res;
}

int f[N];

void upd(int x){
	for (int i = x; i < N; i |= i + 1)
		++f[i];
}

int get(int x){
	int sum = 0;
	for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
		sum += f[i];
	return sum;
}

int main() {
	scanf("%d", &n);
	forn(i, n){
		scanf("%d", &p[i]);
		if (p[i] != -1)
			used[p[i]] = true;
	}
	
	int cur = 0;
	for (int i = n; i >= 1; --i){
		gt[i] = cur;
		cur += !used[i];
	}
	
	// case 1
	int ans = mul(mul(cur, cur - 1), binpow(4, MOD - 2));
	
	int inv = binpow(cur, MOD - 2);
	
	// case 2
	int lft = 0;
	forn(i, n){
		if (p[i] == -1)
			++lft;
		else
			ans = add(ans, mul(lft, mul(gt[p[i]], inv)));
	}
	
	// case 3
	int rgh = 0;
	for (int i = n - 1; i >= 0; --i){
		if (p[i] == -1)
			++rgh;
		else
			ans = add(ans, mul(rgh, mul(cur - gt[p[i]], inv)));
	}
	
	// case 4	
	int tmp = 0;
	forn(i, n) if (p[i] != -1){
		ans = add(ans, tmp - get(p[i]));
		upd(p[i]);
		++tmp;
	}
	
	printf("%d\n", ans);
	return 0;
}