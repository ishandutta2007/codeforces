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

const int N = 1e5 + 5;

queue <int> q;
vector <int> adj[N], a[N], ans;
int to_big[N], n, m;

void addedge(int u, int v) {
	adj[u].push_back(v);
}

void error() {
	printf("No\n");
	exit(0);
}

int main() {
	read(n); read(m);
	for(register int i = 1; i <= n; i++) {
		int t; read(t);
		for(register int j = 1; j <= t; j++) {
			int tmp; read(tmp);
			a[i].push_back(tmp);
		}
		if(i == 1) continue;
		int fir = -1;
		for(register int j = 0; j < (int)min(a[i - 1].size(), a[i].size()); j++) {
			if(a[i - 1][j] != a[i][j]) {
				fir = j;
				break;
			}
		}
		if(~fir) {
			if(a[i - 1][fir] > a[i][fir]) {
				if(to_big[a[i - 1][fir]] == -1 || to_big[a[i][fir]] == 1) error();
				to_big[a[i - 1][fir]] = 1;
				to_big[a[i][fir]] = -1;
			} else addedge(a[i][fir], a[i - 1][fir]);
		} else if(a[i - 1].size() > a[i].size()) error();
	}
	for(register int i = 1; i <= m; i++) {
		if(to_big[i] == 1) {
			q.push(i);
		}
	}
	while(!q.empty()) {
		int u = q.front(); q.pop();
		for(register int i = 0; i < (int)adj[u].size(); i++) {
			int v = adj[u][i];
			if(to_big[v] == -1) {
				error();
			}
			if(to_big[v] == 0) {
				to_big[v] = 1;
				q.push(v);
			}
		}
	}
	for(register int i = 1; i <= m; i++) if(to_big[i] == 1) ans.push_back(i);
	cout << "Yes" << endl;
	cout << ans.size() << endl;
	for(register int i = 0; i < (int)ans.size(); i++) print(ans[i], ' ');
	return 0;
}