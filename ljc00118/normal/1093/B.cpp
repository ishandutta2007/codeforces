#include <bits/stdc++.h>
#define Fast_cin ios::sync_with_stdio(false), cin.tie();
#define rep(i, a, b) for(register int i = a; i <= b; i++)
#define per(i, a, b) for(register int i = a; i >= b; i--)
#define DEBUG(x) cerr << "DEBUG" << x << " >>> " << endl;
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
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

const int N = 1005;

char c[N];
int T, n;

bool check() {
	int l = 1, r = n;
	while(l < r) {
		if(c[l] != c[r]) return 1;
		l++; r--;
	}
	return 0;
}

int main() {
	read(T);
	while(T--) {
		scanf("%s", c + 1); n = strlen(c + 1);
		if(check()) { printf("%s\n", c + 1); continue; }
		sort(c + 1, c + n + 1);
		if(check()) { printf("%s\n", c + 1); continue; }
		printf("-1\n"); 
	}
	return 0;
}