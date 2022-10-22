#include <bits/stdc++.h>
#define sz(a) int((a).size())
using namespace std;
const int N = 1e5 + 10;
struct Union {
	int fa[N], to[N], b[N], e[N]; 
	
	void init(int n) {
		for(int i = 1; i <= n; i++) fa[i] = b[i] = e[i] = i, to[i] = 0;
		return;
	}
	
	int find(int x) {return fa[x] == x ? x : fa[x] = find(fa[x]); }
	int merge(int u, int v) {
		u = find(u), v = find(v);
		if(u == v) return 0;
		to[e[u]] = b[v];
		fa[v] = u;
		e[u] = e[v];
		return 1;
	}
}T1, T2;

int n, m1, m2;
int s[N], t[N], tot = 0;
int check(int a, int b) {return T1.find(a) != T1.find(b) && T2.find(a) != T2.find(b); }
void Merge(int a, int b) {T1.merge(a, b), T2.merge(a, b), s[++tot] = a, t[tot] = b; }
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
	int hd1 = 2, hd2 = 2;
	while(hd1 < n && hd2 < n) {
		while(hd1 < n && T1.find(hd1 - 1) == T1.find(hd1)) hd1++;
		while(hd2 < n && T2.find(hd2 - 1) == T2.find(hd2)) hd2++;
		for(int i = -1; i <= 0; i++) {
//			cout << T1.find(hd1 + i) <<" " << T2.find(hd2 + i) << endl; 
			for(int j = -1; j <= 0; j++) {
				if(check(hd1 + i, hd2 + j)) {
					Merge(hd1 + i, hd2 + j);
				}
			}
		}
		if(check(hd1 - 1, hd1)) Merge(hd1 - 1, hd1);
		if(check(hd2 - 1, hd2)) Merge(hd2 - 1, hd2);
	}
	cout << tot << endl;
	for(int i = 1; i <= tot; i++) cout << s[i] <<" " << t[i] << endl;
	return 0;
}