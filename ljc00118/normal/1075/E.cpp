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

const int N = 3e5 + 5;

int x[N], y[N];
int n, xMin = 1, xMax = 1, yMin = 1, yMax = 1;

int dis(int x, int y, int _x, int _y) { return abs(x - _x) + abs(y - _y); }
int dis(int a, int b) { return dis(x[a], y[a], x[b], y[b]); }
int calc(int a, int b) {
	int ans = 0, now = dis(a, b);
	for(register int i = 1; i <= n; i++) {
		if(i == a || i == b) continue;
		ans = max(ans, now + dis(i, a) + dis(i, b));
	} return ans;
}

int main() {
	read(n);
	for(register int i = 1; i <= n; i++) read(x[i]), read(y[i]);
	for(register int i = 2; i <= n; i++) {
		if(x[i] < x[xMin]) xMin = i;
		if(y[i] < y[yMin]) yMin = i;
		if(x[i] > x[xMax]) xMax = i;
		if(y[i] > y[yMax]) yMax = i;
	} int ans = 0;
	ans = max(ans, calc(xMin, xMax));
	ans = max(ans, calc(xMin, yMax));
	ans = max(ans, calc(xMin, yMin));
	ans = max(ans, calc(xMax, xMin));
	ans = max(ans, calc(xMax, yMax));
	ans = max(ans, calc(xMax, yMin));
	ans = max(ans, calc(yMin, xMax));
	ans = max(ans, calc(yMin, yMax));
	ans = max(ans, calc(yMin, xMin));
	ans = max(ans, calc(yMax, xMin));
	ans = max(ans, calc(yMax, xMax));
	ans = max(ans, calc(yMax, yMin));
	print(ans, ' ');
	for(register int i = 4; i <= n; i++) print((x[xMax] - x[xMin] + y[yMax] - y[yMin]) << 1, i == n ? '\n' : ' ');
	return 0;
}