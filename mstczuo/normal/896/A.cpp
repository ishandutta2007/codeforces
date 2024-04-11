# include <bits/stdc++.h>
using namespace std;

const char* origin = "What are you doing at the end of the world? Are you busy? Will you save us?";

const char* r[3] = {"What are you doing while sending \"", "\"? Are you busy? Will you send \"", "\"?"};

int l0 = strlen(r[0]);
int l1 = strlen(r[1]);
int l2 = strlen(r[2]);

typedef long long ull;

const int maxn = 54;

ull f[maxn];

char calc(int n,ull s) {
	if(n == 0) return origin[s];
	if(s < l0) return r[0][s]; s -= l0;
	if(s < f[n-1]) return calc(n-1, s); 
	s -= f[n-1];
	if(s < l1) return r[1][s]; s -= l1;
	if(s < f[n-1]) return calc(n-1, s);
	s -= f[n-1];
	return r[2][s];
}

int n, Q; ull s;
int main() {
	f[0] = strlen(origin);
	int sum_l = strlen(r[0]) + strlen(r[1]) + strlen(r[2]);
	for(int i = 1; i < maxn; ++i) f[i] = f[i-1] * 2 + sum_l;
	cin >> Q;
	while(Q--) {
		cin >> n >> s;
		s -= 1;
		while(s >= l0 && n >= maxn) s -= l0, n -= 1;
		if (n >= maxn) { putchar(r[0][s]); continue; }

		if(f[n] <= s) {
			putchar('.');
		} else {
			putchar(calc(n, s));
		}
	}
	puts("");
	return 0;
}