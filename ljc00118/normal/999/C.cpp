#include <bits/stdc++.h>
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

const int N = 4e5 + 5;

char c[N];
int sum[30];
int n, m, now = 0, zm, tmp = 0;

int main() {
	cin >> n >> m;
	if(n == m) return 0;
	scanf("%s", c + 1);
	for(int i = 1; i <= n; i++) sum[c[i] - 'a' + 1]++;
	for(int i = 1; i <= 26; i++) {
		if(m >= sum[i]) m -= sum[i];
		else { now = i; break; }
	}
	for(int i = 1; i <= n; i++) {
		if(c[i] - 'a' + 1 < now) continue;
		if(c[i] - 'a' + 1 == now) {
			tmp++; if(tmp > m) putchar(c[i]);
		} else putchar(c[i]);
	}
	return 0;
}