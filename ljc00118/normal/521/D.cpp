#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;
  
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;
 
template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
    while (c < '0' || c > '9') { if (c == '-') { fu = -1; } c = getchar(); }
    while (c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}
 
template <typename T>
void print(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}
 
template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

const int N = 1e5 + 5;

struct ele {
	long double v;
	int id;
};

bool operator < (const ele a, const ele b) { return a.v < b.v; }

vector <ele> all;
vector <pii> add[N];
vector <int> ans;
int a[N], mx[N], mxid[N], o[N];
int n, m, k;

bool cmp(int x, int y) { return o[x] < o[y]; }

int main() {
	read(n); read(m); read(k);
	for (int i = 1; i <= n; i++) read(a[i]);
	for (int i = 1; i <= m; i++) {
		int opt, id, b;
		read(opt); read(id); read(b);
		if (opt == 1) {
			if (b > mx[id]) mx[id] = b, mxid[id] = i;
		}
		if (opt == 2) {
			add[id].push_back(make_pair(b, i));
		}
		if (opt == 3) {
			all.push_back((ele) {(long double)b, i});
		}
		o[i] = opt;
	}
	for (int i = 1; i <= n; i++) {
		if (mx[i] && mx[i] > a[i]) add[i].push_back(make_pair(mx[i] - a[i], mxid[i]));
		sort(add[i].begin(), add[i].end()); reverse(add[i].begin(), add[i].end());
		ll sum = a[i];
		for (int j = 0; j < (int)add[i].size(); j++) {
			all.push_back((ele) {(long double)(sum + add[i][j].first) / sum, add[i][j].second});
			sum += add[i][j].first;
		}
	}
	sort(all.begin(), all.end()); reverse(all.begin(), all.end());
	for (int i = 0; i <= min((int)all.size() - 1, k - 1); i++) ans.push_back(all[i].id);
	print((int)ans.size(), '\n');
	sort(ans.begin(), ans.end(), cmp);
	for (int i = 0; i < (int)ans.size(); i++) print(ans[i], ' ');
	putchar('\n');
    return 0;
}