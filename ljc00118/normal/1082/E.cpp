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

const int N = 5e5 + 5;

vector <int> t[N];
int a[N], s[N];
int n, m, ans;

int main() {
	read(n); read(m);
	for(register int i = 1; i <= n; i++) {
		read(a[i]); t[a[i]].push_back(i);
		if(a[i] == m) s[i] = s[i - 1] + 1;
		else s[i] = s[i - 1];
	}
	ans = s[n];
	for(register int i = 1; i <= N - 5; i++) {
		if(i == m) continue;
		int maxn = 1;
		if(t[i].size()) {
			int l = 0, r = t[i].size() - 1;
			for(register int j = l + 1; j <= r; j++) {
				maxn = max(maxn, -s[t[i][j]] + s[t[i][l] - 1] + j - l + 1);
				if(s[t[i][j]] - s[t[i][l] - 1] >= j - l) l = j;		
			}
			for(register int j = r - 1; j >= l; j--) {
				maxn = max(maxn, -(s[t[i][r]] - s[t[i][j] - 1] - r + j + 1));
				if(s[t[i][r]] - s[t[i][j] - 1] >= r - j) r = j;
			}
			ans = max(ans, s[n] + maxn);
		}
	}
	cout << ans << endl;
	return 0;
}