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

const int INF = 0x7fffffff;

vector <string> a, ans; int minn = INF;
char s[4] = {'A', 'G', 'C', 'T'}; 
int n, m;

void chkans(vector <string> t) {
	int sum = 0;
	for(register int i = 0; i < n; i++) {
		for(register int j = 0; j < m; j++) {
			sum += (a[i][j] != t[i][j]);
		}
	}
	if(sum < minn) minn = sum, ans = t;
}

char c[2][2];
vector <string> cur, cur2;
void solve1() {
	cur.clear();
	for(register int i = 0; i < n; i++) {
		string s1, s2;
		int cnt1 = 0, cnt2 = 0;
		for(register int j = 0; j < m; j++) {
			s1.push_back(c[i % 2][j % 2]);
			s2.push_back(c[i % 2][1 - j % 2]);
			cnt1 += (s1[j] != a[i][j]);
			cnt2 += (s2[j] != a[i][j]);
		}
		if(cnt1 < cnt2) cur.push_back(s1);
		else cur.push_back(s2);
	}
	chkans(cur);
}

void solve2() {
	cur2.clear();
	for(register int i = 0; i < m; i++) {
		string s1, s2;
		int cnt1 = 0, cnt2 = 0;
		for(register int j = 0; j < n; j++) {
			s1.push_back(c[i % 2][j % 2]);
			s2.push_back(c[i % 2][1 - j % 2]);
			cnt1 += (s1[j] != a[j][i]);
			cnt2 += (s2[j] != a[j][i]);
		}
		if(cnt1 < cnt2) cur2.push_back(s1);
		else cur2.push_back(s2);
	}
	for(register int i = 0; i < n; i++) {
		for(register int j = 0; j < m; j++) {
			cur[i][j] = cur2[j][i];
		}
	}
	chkans(cur);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for(register int i = 1; i <= n; i++) {
		string tmp; cin >> tmp;
		a.push_back(tmp);
	}
	rep(i, 0, 3) rep(j, 0, 3) rep(k, 0, 3) rep(t, 0, 3) {
		int a[4] = {i, j, k, t}; sort(a, a + 4);
		if(a[0] == 0 && a[1] == 1 && a[2] == 2 && a[3] == 3) {
			c[0][0] = s[i]; c[0][1] = s[j];
			c[1][0] = s[k]; c[1][1] = s[t];
			solve1(); solve2();
		}
	}
	for(register int i = 0; i < n; i++) cout << ans[i] << endl;
	return 0;
} // qaqqwqqaq