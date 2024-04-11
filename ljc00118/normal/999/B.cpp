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

char c[110];
int n;

void rever(int x) {
	for(int i = 1, j = x; i < j; i++, j--) swap(c[i], c[j]);
}

int main() {
	cin >> n;
	scanf("%s", c + 1);
	for(int i = 2; i <= n; i++) if(n % i == 0) rever(i);
	for(int i = 1; i <= n; i++) putchar(c[i]); putchar('\n');
	return 0;
}