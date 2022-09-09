#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
    while(c < '0' || c > '9') {if(c == '-') fu = -1; c = getchar();}
    while(c >= '0' && c <= '9') {f = (f << 3) + (f << 1) + (c & 15); c = getchar();}
    f *= fu;
}

const int N = 100000 + 10;

int T[N];
int n, ans = INT_MAX;

int main() {
	read(n);
	for(int i = 1; i <= n; i++) {
		int a = n / i, b = 0;
		if(n % i != 0) b++;
		ans = min(ans, i + a + b);
	}
	for(int i = 1; i <= n; i++) {
		int a = n / i, b = 0;
		if(n % i != 0) b++;
		if(i + a + b == ans) {
			int tot = 0;
			for(int j = a * i + 1; j <= n; j++) T[++tot] = j;
			for(int j = a - 1; j >= 0; j--) for(int k = j * i + 1; k <= j * i + i; k++) T[++tot] = k;
			for(int j = 1; j <= n; j++) printf("%d ", T[j]);
			break;
		}
	}
	return 0;
}