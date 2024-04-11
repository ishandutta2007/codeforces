#include <bits/stdc++.h>
#define CIOS ios::sync_with_stdio(false);
#define rep(i, a, b) for(register int i = a; i <= b; i++)
#define per(i, a, b) for(register int i = a; i >= b; i--)
#define DEBUG(x) cerr << "DEBUG" << x << " >>> ";
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

template <typename T>
inline void read(T &f) {
	f = 0; T fu = 1; char c = getchar();
	while (c < '0' || c > '9') { if (c == '-') fu = -1; c = getchar(); }
	while (c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
	f *= fu;
}

template <typename T>
void print(T x) {
	if (x < 0) putchar('-'), x = -x;
	if (x < 10) putchar(x + 48);
	else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
	print(x); putchar(t);
}

const int N = 2005;

int a, b, last;

int query(int x, int y) {
	cout << "?" << " " << x << " " << y << endl;
	int ans; cin >> ans; return ans;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	last = query(0, 0);
	for(register int i = 29; i >= 0; i--) {
		int ans1 = query(a ^ (1 << i), b);
		int ans2 = query(a, b ^ (1 << i));
		if(ans1 == ans2) {
			if(last == 1) a ^= (1 << i);
			if(last == -1) b ^= (1 << i);
			last = ans1;
		} else if(ans2 == 1) a ^= (1 << i), b ^= (1 << i);
	}
	cout << "!" << " " << a << " " << b << endl;
	return 0;
}