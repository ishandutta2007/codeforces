#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include<bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define pb push_back
#define eb emplace_back
#define rep(i,a,b) for(auto i = (a); i != (b); ++i)
#define REP(i,n) rep(i,0,n)
#define all(v) (v).begin(), (v).end()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

bool geq(int x, int y) {
	printf("? %d %d\n", x, y);
	fflush(stdout);
	char c;
	scanf(" %c", &c);
	if (c == 'e') exit(0);
	return c == 'x';
}

int run() {
	int a = 0, b = 1;

	// find n such that 2^n  a < 2^{n+1}

	while (!geq(a, b)) {
		a = b;
		b = 2*b + 1;
	}
	++a; ++b;
	fprintf(stderr, "Now %d  a < %d\n", a, b);
	while (b - a > 1) {
		// do a binary search, since this is an INTERACTIVE problem
		// b - a = 2^k for some k
		int m = (a + b) / 2;
		if (geq(a - 1, m - 1)) {
			// A < m
			b = m;
		} else {
			a = m;
		}
	}
	return a;
}

int main() {
	char in[10];
	while (scanf("%s", in), in[0] == 's') {
		int a = run();	
		printf("! %d\n", a);
		fflush(stdout);
	}
	
	/*
	for (int a = 1; a <= 16; a++) {
		for (int x = 0; x <= 8; x++) {
			for (int y = 0; y <= 9; y++) {
				int xp = x % a, yp = y % a;
				printf("%d", xp >= yp);
			}
			printf(" ");
		}
		printf("\n");
	}

	return 0; */
}