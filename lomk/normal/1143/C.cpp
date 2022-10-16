/*input
5
3 1
1 1
-1 0
2 1
3 0

5
-1 0
1 1
1 1
2 0
3 0

8
2 1
-1 0
1 0
1 1
1 1
4 0
5 1
7 0







*/
#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define endl '\n'
#define fi first
#define se second
#define mp make_pair
#define __builtin_popcount __builtin_popcountll
#define int long long
#define bit(x,y) ((x>>y)&1LL)
#define loop(i,l,r) for(int i=(int)l; i<=(int)r; i++)
#define rloop(i,l,r) for(int i=(int)l; i>=(int)r; i--)
const int N = 100005;
template <class T1, class T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &a) {
	return os << '(' << a.first << ", " << a.second << ')';
}
template <class T>
ostream &operator<<(ostream &os, const vector<T> &a) {
	os << '[';
	for (unsigned int i = 0; i < a.size(); i++)
		os << a[i] << (i < a.size() - 1 ? ", " : "");
	os << ']';
	return os;
}
int read() {
	int x; cin >> x; return x;
}

int n, root = -1;
vector<vector<int> > a(N);
bool rep[N];
vector<int> order;
bool canDel[N];

void dfs(int u) {
	canDel[u] = rep[u];
	for (auto v : a[u]) {
		dfs(v);
		canDel[u] = min(canDel[u], rep[v]);
	}
}

signed main() {
#ifndef UncleGrandpa
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#endif
	cin >> n;
	loop(i, 1, n) {
		int p;
		cin >> p >> rep[i];
		if (p != -1) a[p].push_back(i);
		else root = i;
	}
	dfs(root);
	canDel[root] = false;
	loop(i, 1, n) {
		if (canDel[i]) order.push_back(i);
	}
	if (order.size() == 0) cout << -1 << endl;
	else {
		for (auto it : order) cout << it << sp;
		cout << endl;
	}
}