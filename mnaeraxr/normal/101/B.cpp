#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define DB(x) cout << #x << " = " << x << endl << flush;
#define SZ(x) (int)((x).size())
#define MP make_pair

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double EPS = 1e-9;
const int MAXN = (int)2e6 + 10;
const int64 MOD = (int64)1e9 + 7;

struct node{
	int64 val;
	int le, ri;
};

node st[MAXN];
int st_tot;

int new_node(){
	return st_tot++;
}

void update(int r, int b, int e, int x, int64 v){
	st[r].val = (st[r].val + v) % MOD;
	if (b < e){
		int mid = (b + e) >> 1;
		if (x <= mid){
			if (!st[r].le) st[r].le = new_node();
			update(st[r].le, b, mid, x, v);
		}
		else{
			if (!st[r].ri) st[r].ri = new_node();
			update(st[r].ri, mid + 1, e, x, v);
		}
	}
}

int64 query(int r, int b, int e, int x, int y){
	if (x <= b && e <= y) return st[r].val;
	int mid = (b + e) >> 1;
	int64 ans = 0;
	if (x <= mid && st[r].le)
		ans = (ans + query(st[r].le, b, mid, x, y)) % MOD;
	if (mid + 1 <= y && st[r].ri)
		ans = (ans + query(st[r].ri, mid + 1, e, x, y)) % MOD;
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int root = new_node();

	int n, m;
	cin >> n >> m;

	update(root, 0, n, 0, 1);

	vector<pii> V(m);
	for (int i = 0; i < m; ++i){
		cin >> V[i].second >> V[i].first;
	}

	sort(V.begin(), V.end());

	for (int i = 0; i < m; ++i){
		int64 cur = query(root, 0, n, V[i].second, V[i].first - 1);
		update(root, 0, n, V[i].first, cur);
	}

	int64 ans = query(root, 0, n, n, n);
	cout << ans << endl;

	return 0;
}