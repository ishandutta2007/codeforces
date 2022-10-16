#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

int ships(int v, int a){
	return (v + 1) / (a + 1);
}

const int maxn = 200001;
pii st[maxn << 2];

void build(int p, int b, int e, int &n){
	st[p] = make_pair(0, n + 1);
	if (b == e) return;
	int mid = (b + e) >> 1;
	int le = p << 1;
	int ri = le | 1;
	build(le, b, mid, n);
	build(ri, mid + 1, e, n);
}

void update(int p, int b, int e, int x, int y, int &v, bool mode){
	if (x <= b && e <= y){
		if (mode)
			st[p].second = min(st[p].second, v);
		else
			st[p].first = max(st[p].first, v);
	}
	else{
		int mid = (b + e) >> 1;
		if (x <= mid) update(p << 1, b, mid, x, y, v, mode);
		if (mid + 1 <= y) update((p << 1) | 1, mid + 1, e, x, y, v, mode);
	}
}

void query(int p, int b, int e, int x, pii &ans){
	ans.first = max(st[p].first, ans.first);
	ans.second = min(st[p].second, ans.second);

	if (b < e){
		int mid = (b + e) >> 1;
		if (x <= mid) query(p << 1, b, mid, x, ans);
		else query((p << 1) | 1, mid + 1, e, x, ans);
	}
}

int main()
{
	int n, k, a;
	scanf("%d%d%d", &n, &k, &a);

	int t;
	scanf("%d", &t);

	int tot = ships(n, a);
	
	build(1, 0, n + 1, n);

	for (int i = 1; i <= t; ++i){
		int v, hi, lo; 
		scanf("%d", &v);

		pii cur = make_pair(0, n + 1);
		query(1, 0, n + 1, v, cur);
		hi = cur.second, lo = cur.first;

		tot -= ships(hi - lo - 1, a);
		tot += ships(v - lo - 1, a);
		tot += ships(hi - v - 1, a);

		if (tot < k){
			printf("%d\n", i);
			exit(0);
		}

		update(1, 0, n + 1, lo + 1, v - 1, v, true);
		update(1, 0, n + 1, v + 1, hi - 1, v, false);
	}	

	cout << -1 << endl;

	return 0;
}