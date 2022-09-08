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

multiset <int> t;
multiset <int> :: iterator it, it1, it2;
int a[N], n, fir = 1, ans = 1;

int main() {
	read(n);
	for(register int i = 1; i <= n; i++) read(a[i]); t.insert(a[1]);
	for(register int i = 2; i <= n; i++) {
		t.insert(a[i]); it1 = t.begin(); it2 = t.end(); --it2;
		while(*it2 - *it1 > 1) {
			it = t.lower_bound(a[fir++]); t.erase(it);
			it1 = t.begin(); it2 = t.end(); --it2;
		} ans = max(ans, i - fir + 1);
	}
	cout << ans << endl;
	return 0;
}