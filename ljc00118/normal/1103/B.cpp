#pragma GCC target("avx")
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define Fast_cin ios::sync_with_stdio(false), cin.tie(0);
#define rep(i, a, b) for(register int i = a; i <= b; i++)
#define per(i, a, b) for(register int i = a; i >= b; i--)
#define DEBUG(x) cerr << "DEBUG" << x << " >>> " << endl;
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
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

string foo;

int query(int l, int r) {
	cout << "?" << " " << l << " " << r << endl;
	cin >> foo;
	if(foo == "x") return 1;
	return 0;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	while(cin >> foo && foo != "end") {
		int ans = query(0, 1);
		if(ans == 1) { cout << "!" << " " << 1 << endl; continue; }
		for(int l = 1, r = 2; ; l <<= 1, r <<= 1) {
			int ans = query(l, r);
			if(ans == 1) {
				while(r - l > 1) {
					int mid = (l + r + 1) >> 1;
					ans = query(l, mid);
					if(ans == 1) r = mid; else l = mid;
				}
				cout << "!" << " " << r << endl;
				break;
			}
		}
	}
	return 0;
}