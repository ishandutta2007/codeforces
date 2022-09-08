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

vector <int> ans;
int n;

int calc(int x) {
	int ans = 0;
	while(x) {
		ans += x % 10;
		x /= 10;
	}
	return ans;
}

int main() {
	cin >> n;
	for(register int i = max(0, n - 1000); i <= n; i++) {
		if(i + calc(i) == n) {
			ans.push_back(i);
		}
	}
	cout << ans.size() << endl;
	for(register int i = 0; i < ans.size(); i++) {
		print(ans[i], ' ');
	}
	return 0;
}