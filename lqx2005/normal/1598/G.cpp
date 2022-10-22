#include<bits/stdc++.h>
   
using namespace std;
   
#define broken fprintf(stderr, "running on %s %d\n", __FUNCTION__, __LINE__)
#define sz(a) int((a).size())
#define x first
#define y second
#define mp make_pair
#define Hash pair<int, int>
typedef long long i64;
typedef unsigned long long u64;
const int N = 5e5 + 10;
int n, m;
char s[N], num[N];
int P1, P2;
mt19937 rnd(__builtin_ia32_rdtsc());
Hash h1[N], h2[N], p10[N];
int isprime(int n) {
	for(int i = 2; i * i <= n; i++) {
		if(n % i == 0) return 0;
	}
	return 1;
}
const Hash B = {10, 10};

Hash operator + (const Hash a, const Hash b) {
	return {(a.x + b.x) % P1, (a.y + b.y) % P2};
}

Hash operator - (const Hash a, const Hash b) {
	return {(a.x - b.x + P1) % P1, (a.y - b.y + P2) % P2};
}

Hash operator * (const Hash a, const Hash b) {
	return {1ll * a.x * b.x % P1, 1ll * a.y * b.y % P2}; 
}

Hash query(int l, int r) {
	return h1[r] - h1[l - 1] * p10[r - l + 1];
}

int LCP(int x) {
	int l = 1, r = min(n - x + 1, m), best = 0;
	while(l <= r) {
		int mid = (l + r) / 2;
		if(query(x, x + mid - 1) == h2[mid]) best = mid, l = mid + 1;
		else r = mid - 1;
	}
	return best;
}

void check(int len) {
	if(len == 0) return; 
	for(int i = 1; i + len - 1 <= n; i++) {
		int lcp = len - min(len, LCP(i));
		for(int j = max(1, lcp - 1); j <= lcp && i + len + j - 1 <= n; j++) {
			if(query(i, i + len - 1) + query(i + len, i + len + j - 1) == h2[m]) {
				printf("%d %d\n%d %d\n", i, i + len - 1, i + len, i + len + j - 1);
				exit(0);
			}
		}
		for(int j = max(1, lcp - 1); j <= lcp && i - j >= 1; j++) {
			if(query(i, i + len - 1) + query(i - j, i - 1) == h2[m]) {
				printf("%d %d\n%d %d\n", i - j, i - 1, i, i + len - 1);
				exit(0);
			}
		}
	}
	return;
}

int rndprime() {
	uniform_int_distribution<int> dist(5e8, 1e9);
	int p = dist(rnd);
	while(!isprime(p)) p++;
	return p;
}

int main() {
	P1 = rndprime();
	P2 = rndprime();
	scanf("%s", s + 1);
	n = strlen(s + 1);
	p10[0] = {1, 1};
	for(int i = 1; i <= n; i++) p10[i] = p10[i - 1] * B;
	for(int i = 1; i <= n; i++) {
		int c = s[i] - '0';
		h1[i] = h1[i - 1] * B + Hash{c, c}; 
	}
	scanf("%s", num + 1);
	m = strlen(num + 1);
	for(int i = 1; i <= m; i++) {
		int c = num[i] - '0';
		h2[i] = h2[i - 1] * B + Hash{c, c};
	}
	check(m);
	check(m - 1);
    return 0;
}