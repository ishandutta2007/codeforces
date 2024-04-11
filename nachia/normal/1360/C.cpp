#include<bits/stdc++.h>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

UL N;
UL S[50];

int main() {
	UL T; scanf("%u", &T);
	while (T--) {
		scanf("%u", &N);
		rep(i, N) scanf("%u", S + i);
		sort(S, S + N);
		int c[2] = {};
		int p = 0;
		stack<int> s; s.push(-2);
		rep(i, N) {
			if (s.top() + 1 == S[i]) { s.pop(); p++; }
			c[S[i] % 2]++;
			s.push(S[i]);
		}
		int d = c[0] % 2;
		printf((d > p) ? "NO\n" : "YES\n");
	}
	return 0;
}