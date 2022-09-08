#include <bits/stdc++.h>
#define Fast_cin ios::sync_with_stdio(false), cin.tie(0);
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

const int N = 1e5 + 5;

set <int> wxw;
vector <int> adj[N];
bool used[N];
int n, m;

void push(int u) {
	for(register unsigned i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if(!used[v]) {
			used[v] = 1;
			wxw.insert(v);
		}
	}
}

int main() {
	read(n); read(m);
	for(register int i = 1; i <= m; i++) {
		int u, v; read(u); read(v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	used[1] = 1; cout << 1 << " "; push(1);
	for(register int i = 2; i <= n; i++) {
		int u = *wxw.begin(); wxw.erase(wxw.begin());
		print(u, ' '); push(u);
	}
	putchar('\n');
    return 0;
}