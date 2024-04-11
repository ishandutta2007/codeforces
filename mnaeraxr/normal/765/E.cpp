#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef int int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 200000 + 10;
const int mod = 1000000007;

vi adj[maxn];

void solve(int n){
	if (n == -1){
		cout << -1 << endl;
		exit(0);
	}

	while (n != 0 && n % 2 == 0)
		n >>= 1;

	cout << n << endl;
	exit(0);
}

bool first;

int build(int s, int p){
//	cout << s << " " << first << endl;

	int t1 = 0, t2 = 0;

	for (auto u : adj[s]){
		if (u == p) continue;

		int l = build(u, s) + 1;

//		cout << s << " " << u << " " << l << " " << first << endl;

		if (t1 == 0) t1 = l;
		else if (t1 != l){
			if (p == -1){
				if (t2 == 0) t2 = l;
				else if (t2 != l)
					solve(-1);
			}
			else{
				if (first){
					first = false;
					build(s, -1);
					assert( false );
				}

//				cout << "here" << endl;
//				cout << s << endl;

				solve(-1);
			}
		}
	}

	if (p == -1) solve(t1 + t2);
	else return t1;

	return -1;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;

	for (int i = 1; i < n; ++i){
		int u, v; cin >> u >> v;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	int root = 0;

	for (int i = 1; i <= n && !root; ++i){
		if (adj[i].size() > 2)
			root = i;
	}

	if (root == 0) solve(n - 1);

	first = true;
	build(root, -1);

	return 0;
}
/*
7
1 2
1 3
1 4
4 5
4 6
6 7
 */