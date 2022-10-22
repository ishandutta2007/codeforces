#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 10, V = N - 10;
vector<int> g[N];
int t[N], a[N], odd[N];
int stk[N], top = 0;
void add(int x, int v) {
	for(int i = x; i <= V; i += i & (-i)) t[i] += v;
}

int ask(int x) {
	int sum = 0;
	for(int i = x; i > 0; i -= i & (-i)) sum += t[i];
	return sum;
}

int solve() {
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		odd[i] = (ask(V) - ask(a[i])) & 1;
		add(a[i], 1);
	}
	for(int i = 1; i <= n; i++) add(a[i], -1);
	for(int i = n; i >= 1; i--) {
		odd[i] ^= ask(a[i] - 1) & 1;
		add(a[i], 1);
	}
	for(int i = 1; i <= n; i++) {
		add(a[i], -1);
		g[a[i]].clear();
	}
	for(int i = 1; i <= n; i++) {
		g[a[i]].push_back(odd[i]);
	}
	for(int i = 1; i <= n; i++) {
		if(g[a[i]].empty()) continue;
		top = 0;
		for(int j = 0; j < int(g[a[i]].size()); j++) {
			if(top == 0 || stk[top] != g[a[i]][j]) stk[++top] = g[a[i]][j];
			else top--;
		}
		for(int j = 1; j <= top; j++) if(stk[j]) return 0;
		g[a[i]].clear();
	}
	return 1;
}

int main() {
	int T;
	for(cin >> T; T--; ) printf(solve() ? "YES\n" : "NO\n");
	return 0;	
}