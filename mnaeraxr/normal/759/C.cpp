#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int64 oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 200000 + 10;
const int sqrtmaxn = 1000;

struct segment_tree{
	vector<int> data, lazy;

	segment_tree(int n){
		data = vi(4 * n);
		lazy = vi(4 * n);
	}

	void push(int p, int l, int r){
		if (lazy[p]){
			data[l] += lazy[p];
			data[r] += lazy[p];
			lazy[l] += lazy[p];
			lazy[r] += lazy[p];
			lazy[p] = 0;
		}
	}

	void update(int p, int b, int e, int x, int y, int v){
		if (x <= b && e <= y){
			data[p] += v;
			lazy[p] += v;
		}
		else{
			int m = (b + e) >> 1, l = p << 1, r = l | 1;
			push(p, l, r);

			if (x < m) update(l, b, m, x, y, v);
			if (m < y) update(r, m, e, x, y, v);

			data[p] = max( data[l], data[r] );

		}
	}

	int query(int p, int b, int e){
		while (b + 1 < e){
			int m = (b + e) >> 1, l = p << 1, r = l | 1;
			push(p, l, r);

			if (data[r] > 0)
				p = r, b = m;
			else
				p = l, e = m;
		}
		return b;
	}

	int max_value(){
		return data[1];
	}
};

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;

	vector<int> value(n);

	segment_tree s(n);

	for (int i = 0; i < n; ++i){
		int t, op;
		cin >> t >> op;

		if (op == 0) s.update(1, 0, n, 0, t, -1);
		else{
			cin >> value[ t - 1 ];
			s.update(1, 0, n, 0, t, +1);
		}

		if (s.max_value() > 0)
			cout << value[ s.query(1, 0, n) ] << endl;
		else
			cout << -1 << endl;
	}

	return 0;
}