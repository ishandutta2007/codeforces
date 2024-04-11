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

int a, b, c, d, e, f, minn = 23332323, x, y;

int dis(int x, int y, int _x, int _y) {
	return abs(x - _x) + abs(y - _y);
}

void a_to_b(int x, int y, int _x, int _y) {
	while(x != _x || y != _y) {
		if(x != _x) {
			if(x > _x) x--;
			else x++;
			print(x, ' '); print(y, '\n');
		} else {
			if(y > _y) y--;
			else y++;
			print(x, ' '); print(y, '\n');
		}
	}
}

int main() {
	cin >> a >> b >> c >> d >> e >> f;
	for(register int i = min(a, c); i <= max(a, c); i++) {
		for(register int j = min(b, d); j <= max(b, d); j++) {
			if(dis(a, b, i, j) + dis(c, d, i, j) + dis(e, f, i, j) < minn) {
				minn = dis(a, b, i, j) + dis(c, d, i, j) + dis(e, f, i, j);
				x = i; y = j;
			}
		}
	}
	cout << minn + 1 << endl;
	a_to_b(x, y, a, b); a_to_b(x, y, c, d); a_to_b(x, y, e, f);
	print(x, ' '); print(y, '\n');
	return 0;
}