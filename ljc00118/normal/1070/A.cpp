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


queue <int> q;
int from[3000005];
int d, s;

int main() {
	read(d); read(s);
	for(register int i = 1; i <= 9 && i <= s; i++) {
		if(!from[i % d * (s + 1) + i]) {
			from[i % d * (s + 1) + i] = -1;
			q.push(i % d * (s + 1) + i);
		}
	}
	while(!q.empty()) {
		int a = q.front() / (s + 1), b = q.front() % (s + 1); q.pop();
		if(!a && b == s) {
			vector <int> ans;
			while(~from[a * (s + 1) + b]) {
				int _a = from[a * (s + 1) + b] / (s + 1), _b = from[a * (s + 1) + b] % (s + 1);
				ans.push_back(b - _b); a = _a; b = _b;
			}
			putchar(b + '0');
			for(register int i = ans.size() - 1; i >= 0; i--) putchar(ans[i] + '0');
			putchar('\n');
			return 0;
		}
		for(register int i = 0; i <= 9 && b + i <= s; i++) {
			int _a = (a * 10 + i) % d, _b = b + i;
			if(!from[_a * (s + 1) + _b]) {
				from[_a * (s + 1) + _b] = a * (s + 1) + b;
				q.push(_a * (s + 1) + _b);
			}
		}
	}
	putchar('-'); putchar('1'); putchar('\n');
	return 0;
}