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

const int N = 1e5 + 5, P = 1e9 + 7;

vector <int> t, t2;
int a[N], f[N];
int n;

inline int add(int x, int y) {
	int ans = x + y;
	return ans < P ? ans : ans - P;
}

int main() {
	read(n); f[0] = 1;
	for(register int i = 1; i <= n; i++) {
		read(a[i]); t.clear(); t2.clear();
		for(register int j = 1; j * j <= a[i]; j++) {
			if(a[i] % j == 0) {
				if(j <= n) t2.push_back(j);
				if(j * j != a[i] && a[i] / j <= n) t.push_back(a[i] / j);
			}
		}
		int len1 = t.size(), len2 = t2.size();
		for(register int j = 0; j < len1; j++) f[t[j]] = add(f[t[j]], f[t[j] - 1]);
		for(register int j = len2 - 1; j >= 0; j--) f[t2[j]] = add(f[t2[j]], f[t2[j] - 1]);
	} int ans = 0;
	for(register int i = 1; i <= n; i++) ans = add(ans, f[i]); cout << ans << endl;
	return 0;
}