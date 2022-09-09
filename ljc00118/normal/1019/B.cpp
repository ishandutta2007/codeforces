#include <bits/stdc++.h>
#define For(i, a, b) for(int i = a; i <= b; i++)
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

int n;

int ask(int x) {
	int a, b;
	cout << "? " << x << endl;
	cin >> a;
	cout << "? " << x + (n / 2) << endl;
	cin >> b;
	if(a == b) {
		cout << "! " << x << endl;
		exit(0);
	}
	return a > b;
}

int main() {
	cin >> n;
	int l = 1, r = n / 2 + 1;
	int now = ask(1);
	while(l + 1 < r) {
		int mid = (l + r) >> 1;
		if(ask(mid) == now) l = mid;
		else r = mid;
	}
	cout << "! -1" << endl;
	return 0;
}