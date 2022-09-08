#include <bits/stdc++.h>
#define CIOS ios::sync_with_stdio(false);
#define For(i, a, b) for(register int i = a; i <= b; i++)
#define Rof(i, a, b) for(register int i = a; i >= b; i--)
#define DEBUG(x) cerr << "DEBUG" << x << " >>> ";
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

template <typename T>
inline void read(T &f) {
	f = 0; T fu = 1; char c = getchar();
	while(c < '0' || c > '9') {if(c == '-') fu = -1; c = getchar();}
	while(c >= '0' && c <= '9') {f = (f << 3) + (f << 1) + (c & 15); c = getchar();}
	f *= fu;
}

template <typename T>
void print(T x) {
	if(x < 0) putchar('-'), x = -x;
	if(x < 10) putchar(x + 48);
	else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
	print(x); putchar(t);
}

const int N = 1e6 + 5, PP1 = 998244353, PP2 = 167772161;

ll s[N], s2[N], P[N], P2[N];
char c[N], d[N];
int n, m, cnt0, cnt1, fir0 = -1, fir1 = -1, ans;

pair <ll, ll> calc(int l, int r) { return make_pair(((s[r] - s[l - 1] * P[r - l + 1]) % PP1 + PP1) % PP1, ((s2[r] - s2[l - 1] * P2[r - l + 1]) % PP2 + PP2) % PP2); }

int main() {
	scanf("%s %s", c + 1, d + 1); n = strlen(c + 1); m = strlen(d + 1);
	for(register int i = 1; i <= n; i++) {
		if(c[i] == '0' && fir0 == -1) fir0 = cnt1;
		if(c[i] == '1' && fir1 == -1) fir1 = cnt0;
		if(c[i] == '0') cnt0++;
		if(c[i] == '1') cnt1++;
	} P[0] = 1; P2[0] = 1;
	for(register int i = 1; i <= m; i++) s[i] = (s[i - 1] * 131 + d[i]) % PP1, P[i] = P[i - 1] * 131 % PP1, s2[i] = (s2[i - 1] * 101 + d[i]) % PP2, P2[i] = P2[i - 1] * 101 % PP2;
	for(register int i = 1; i <= m; i++) {
		if(cnt0 * i >= m) break;
		int QAQ = m - cnt0 * i;
		if(QAQ % cnt1 != 0) continue;
		int len = QAQ / cnt1, now = 1;
		pair <ll, ll> h1 = calc(fir0 * len + 1, fir0 * len + i);
		pair <ll, ll> h2 = calc(fir1 * i + 1, fir1 * i + len); 
		if(h1 == h2) continue; ans++;
		for(register int j = 1; j <= n; j++) {
			if(c[j] == '0') {
				if(calc(now, now + i - 1) != h1) {
					ans--; break;
				} now += i;
			} else {
				if(calc(now, now + len - 1) != h2) {
					ans--; break;
				} now += len; 
			}
			// qeoqj
			// qwqqaqqwq
			// kasfalkjdsjf
			// /zl
		}
	} print(ans, '\n');
	return 0;
}