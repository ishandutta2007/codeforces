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

vector < pair <int, int> > ans;
vector <int> t, tt, can;
int a[N], used[N];
int n, sum = 0, l, r, last, big;

int main() {
	read(n);
	for(register int i = 1; i <= n; i++) read(a[i]);
	for(register int i = 1; i <= n; i++) {
		if(a[i] == 1) t.push_back(i);
		else tt.push_back(i);
	}
	if(t.size() == 0) l = tt[0], r = tt[1];
	else if(t.size() == 1) l = tt[0], r = t[0];
	else l = t[0], r = t[1], last = t.size() - 2;
	used[l] = used[r] = 1; int now = l, len = tt.size();
	for(register int i = 0; i < len; i++) {
		if(used[tt[i]]) continue;
		ans.push_back(make_pair(now, tt[i]));
		used[tt[i]] = 1; sum += a[tt[i]] - 2; now = tt[i];
		if(a[tt[i]] - 2 > 0) can.push_back(tt[i]), a[tt[i]] -= 2;
	}
	ans.push_back(make_pair(now, r));
	if(last > sum) {
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << " " << ans.size() << endl;
	cout << n - 1 << endl; big = can.size() - 1;
	for(register int i = 0; i < ans.size(); i++) print(ans[i].first, ' '), print(ans[i].second, '\n');
	for(register int i = 2; i < t.size(); i++) {
		print(t[i], ' '); print(can[big], '\n'); a[can[big]]--; if(a[can[big]] == 0) big--;
	}
	return 0;
}