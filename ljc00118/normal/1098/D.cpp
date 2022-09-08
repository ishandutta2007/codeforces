#include <bits/stdc++.h>
#define Fast_cin ios::sync_with_stdio(false), cin.tie();
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

multiset <int> t[40];
ll sum[40];
int n;

int calc(int x) {
	int ans = 0;
	for(register int i = 0; i <= 30; i++) {
		if((x >> i) & 1) ans = i;
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n; while(n--) {
		char opt; int x; cin >> opt >> x;
		int LG = calc(x);
		if(opt == '+') {
			t[LG].insert(x);
			sum[LG] += x;
		}
		if(opt == '-') {
			t[LG].erase(t[LG].find(x));
			sum[LG] -= x;
		}
		int ans = 0; ll s = 0;
		for(register int i = 0; i <= 30; i++) {
			ans += t[i].size();
			if(t[i].size() && *t[i].begin() > s * 2) ans--;
			s += sum[i];
		}
		cout << ans << endl;
	}
	return 0;
} // faker