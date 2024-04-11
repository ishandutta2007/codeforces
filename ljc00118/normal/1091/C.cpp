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

vector <ll> ans;
int n;

void calc(int x) {
    ll l = 1, r = n + 1 - x, k = (r - l) / x + 1;
    ans.push_back((l + r) * k / 2);
}

int main() {
	read(n);
	for(register int i = 1; i * i <= n; i++) {
		if(n % i != 0) continue; calc(i);
		if(i * i != n) calc(n / i);
	}
	sort(ans.begin(), ans.end()); int len = ans.size();
	print(ans[0], ' ');
	for(register int i = 1; i < len; i++) if(ans[i] != ans[i - 1]) print(ans[i], ' ');
	putchar('\n');
	return 0;
}