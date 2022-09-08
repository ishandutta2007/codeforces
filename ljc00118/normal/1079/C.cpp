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

const int N = 1e5 + 5;

int f[N][6], a[N], Ans[N];
int n;

int main() {
	memset(f, -1, sizeof(f));
	read(n);
	for(register int i = 1; i <= n; i++) read(a[i]);
	for(register int i = 1; i <= 5; i++) f[1][i] = 0;
	for(register int i = 2; i <= n; i++) {
		for(register int j = 1; j <= 5; j++) {
			for(register int k = 1; k <= 5; k++) {
				if(a[i - 1] > a[i] && j > k && ~f[i - 1][j]) f[i][k] = j;
				if(a[i - 1] == a[i] && j != k && ~f[i - 1][j]) f[i][k] = j;
				if(a[i - 1] < a[i] && j < k && ~f[i - 1][j]) f[i][k] = j;
			}
		}
	} int ans = -1;
	for(register int i = 1; i <= 5; i++) {
		if(f[n][i] != -1) {
			ans = i;
			break;
		}
	}
	if(ans == -1) cout << "-1" << endl;
	else {
		for(register int i = n; i >= 1; i--) {
			Ans[i] = ans;
			ans = f[i][ans];
		}
		for(register int i = 1; i <= n; i++) print(Ans[i], i == n ? '\n' : ' ');
	}
	return 0;
}