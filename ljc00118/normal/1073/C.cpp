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
	while(c < '0' || c > '9') { if(c == '-') fu = -1; c = getchar(); }
	while(c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
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

const int N = 2e5 + 5;

char c[N];
int s[4][N];
int n, xx, yy; 

int calc(char c) {
	if(c == 'D') return 0;
	if(c == 'U') return 1;
	if(c == 'L') return 2;
	return 3;
}

bool check(int mid) {
	for(register int i = 1; i <= n - mid + 1; i++) {
		int y = s[1][n] - s[0][n], x = s[3][n] - s[2][n];
		x -= (s[3][i + mid - 1] - s[2][i + mid - 1]);
		x += (s[3][i - 1] - s[2][i - 1]);
		y -= (s[1][i + mid - 1] - s[0][i + mid - 1]);
		y += (s[1][i - 1] - s[0][i - 1]);
		int dis = abs(x - xx) + abs(y - yy);
		if(dis <= mid) return 1;
	}
	return 0;
}

int main() {
	read(n); scanf("%s", c + 1);
	for(register int i = 1; i <= n; i++) {
		for(register int j = 0; j < 4; j++) s[j][i] = s[j][i - 1];
		s[calc(c[i])][i]++;
	} 
	read(xx); read(yy);
	if(((xx + yy) & 1) != (n & 1)) {
		print(-1, '\n');
		return 0;
	}
	int l = 0, r = n, ans = -1;
	while(l <= r) {
		int mid = (l + r) >> 1;
		if(check(mid)) ans = mid, r = mid - 1; else l = mid + 1;
	}
	print(ans, '\n');
	return 0;
}