#include <bits/stdc++.h>
#define sz(a) int((a).size())
using namespace std;
const int N = 1e3 + 10;
struct Union {
	int fa[N];
	
	void init(int n) {
		for(int i = 1; i <= n; i++) fa[i] = i;
	}
	
	int find(int x) {return fa[x] == x ? x : fa[x] = find(fa[x]); }
	
	int merge(int x, int y) {
		x = find(x), y = find(y);
		if(x == y) return 0;
		return fa[x] = y, 1;
	}
}T1, T2;
int n, m1, m2;
int a[N], b[N], tot = 0;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m1 >> m2;
	T1.init(n), T2.init(n); 
	for(int i = 1, u, v; i <= m1; i++) {
		cin >> u >> v;
		T1.merge(u, v);
	}
	for(int i = 1, u, v; i <= m2; i++) {
		cin >> u >> v;
		T2.merge(u, v);
	}
	for(int i = 1; i <= n; i++) {
		for(int j = i + 1; j <= n; j++) {
			if(T1.find(i) != T1.find(j) && T2.find(i) != T2.find(j)) {
				T1.merge(i, j), T2.merge(i, j);
				a[++tot] = i, b[tot] = j;
			}
		}
	}
	cout << tot << endl;
	for(int i = 1; i <= tot; i++) cout << a[i] <<" " << b[i] << endl;
	return 0;
}