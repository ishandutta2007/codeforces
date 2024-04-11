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

vector <int> s[N];
int a[N], b[N], cnt[N];
int n, m, ans, nowans;

bool cmp(vector <int> a, vector <int> b) { return a.size() > b.size(); }
bool cmp2(int a, int b) { return a > b; }

int main() {
	read(n); read(m);
	for(register int i = 1; i <= n; i++) {
		read(a[i]); read(b[i]);
		s[a[i]].push_back(b[i]);
	}
	for(register int i = 1; i <= m; i++) sort(s[i].begin(), s[i].end(), cmp2);
	for(register int i = 1; i <= m; i++) {
		if(s[i].size() && s[i][0] > 0) cnt[1] += s[i][0];
		for(register int j = 1; j < s[i].size(); j++) {
			s[i][j] += s[i][j - 1];
			if(s[i][j] > 0) cnt[j + 1] += s[i][j];
		}
	}
	for(register int i = 1; i <= n; i++) ans = max(ans, cnt[i]);
	cout << ans << endl;
	return 0;
}