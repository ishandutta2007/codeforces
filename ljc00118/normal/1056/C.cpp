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

const int N = 23456;

struct ele { int x, y; } t[N];

int a[N], pre[N], used[N], id[N];
int n, m, T, tot;

bool cmp(int x, int y) { return a[x] > a[y]; }

int main() {
	read(n); read(m);
	for(register int i = 1; i <= n * 2; i++) read(a[i]), id[i] = i;
	for(register int i = 1; i <= m; i++) {
		int x, b; read(x); read(b);
		pre[x] = b; pre[b] = x;
		t[i].x = x; t[i].y = b;
	}
	read(T);
	if(T == 1) {
		for(register int i = 1; i <= m; i++) {
			if(a[t[i].x] > a[t[i].y]) {
				cout << t[i].x << endl;
				int ans; cin >> ans;
				used[t[i].x] = used[ans] = 1;
			} else {
				cout << t[i].y << endl;
				int ans; cin >> ans;
				used[t[i].y] = used[ans] = 1;
			}
		}
		sort(id + 1, id + n * 2 + 1, cmp);
		for(register int i = 1; i <= n * 2; i++) {
			if(used[id[i]]) continue;
			cout << id[i] << endl; used[id[i]] = 1;
			int ans; cin >> ans; used[ans] = 1;
		}
	} else {
		sort(id + 1, id + n * 2 + 1, cmp);
		for(register int j = 1; j <= n; j++) {
			int ans; cin >> ans; used[ans] = 1;
			if(pre[ans] && !used[pre[ans]]) cout << pre[ans] << endl, used[pre[ans]] = 1;
			else {
				for(register int i = 1; i <= m; i++) {
					if(used[t[i].x] || used[t[i].y]) continue;
					if(a[t[i].x] > a[t[i].y]) {
						cout << t[i].x << endl;
						int ans; cin >> ans;
						used[t[i].x] = used[ans] = 1;
					} else {
						cout << t[i].y << endl;
						int ans; cin >> ans;
						used[t[i].y] = used[ans] = 1;
					}
				}
				for(register int i = 1; i <= n * 2; i++) {
					if(!used[id[i]]) {
						cout << id[i] << endl;
						used[id[i]] = 1;
						int ans; if(cin >> ans) used[ans] = 1;
					}
				}
			}
		}
	}
	return 0;
}