#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef vector<int> vi;
typedef pair<int,int> pii;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100010;

struct segment_tree{
	int n;
	vector<int> sum, lazy;

	segment_tree(int n) : n(n){
		sum = vector<int>(4 * n);
		lazy = vector<int>(4 * n, -1);
	}

	void update(int p, int b, int e, int x, int y, int v){
		if (x <= b && e <= y){
			lazy[p] = v;
			sum[p] = (e - b) * v;
		}
		else{
			int m = (b + e) >> 1, l = p << 1, r = l | 1;

			if (lazy[p] != -1){
				lazy[l] = lazy[r] = lazy[p];
				sum[l] = (m - b) * lazy[p];
				sum[r] = (e - m) * lazy[p];
				lazy[p] = -1;
			}

			if (x < m) update(l, b, m, x, y, v);
			if (m < y) update(r, m, e, x, y, v);

			sum[p] = sum[l] + sum[r];
		}
	}
};

pii merge(pii a, pii b){
	pii c = {max(a.first, b.first), min(a.second, b.second)};
	c.first = min(c.first, c.second);
	return c;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;

	vector<int> A(n), B(n);

	for (int i = 0; i < n; ++i) cin >> A[i];
	for (int i = 0; i < n; ++i) cin >> B[i];

	vector<pii> MAX = {{oo, -1}};  map<int,int> MAX_POS;
	vector<pii> MIN = {{-oo, -1}}; map<int,int> MIN_POS;

	segment_tree st(n);

	int64 ans = 0;

	for (int i = 0; i < n; ++i){

		while (MAX.back().first <= A[i]){
			MAX_POS[MAX.back().first] = -1;
			MAX.pop_back();
		}

		pii cur_interval = {MAX.back().second + 1, i + 1};
		st.update(1, 0, n, cur_interval.first, cur_interval.second, 0);

		if (MIN_POS.count(A[i])){
			int pp = MIN_POS[A[i]];
			if (pp != -1){
				pii t_interval = {MIN[pp - 1].second + 1, MIN[pp].second + 1};
				pii real_interval = merge(cur_interval, t_interval);

				if (real_interval.second > real_interval.first)
					st.update(1, 0, n, real_interval.first, real_interval.second, 1);
			}
		}
/*
40
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
 */
		MAX.push_back({A[i], i});
		MAX_POS[A[i]] = MAX.size() - 1;

		// Region 2


		while (MIN.back().first >= B[i]){
			MIN_POS[MIN.back().first] = -1;
			MIN.pop_back();
		}

		cur_interval = {MIN.back().second + 1, i + 1};
		st.update(1, 0, n, cur_interval.first, cur_interval.second, 0);

		if (MAX_POS.count(B[i])){
			int pp = MAX_POS[B[i]];
			if (pp != -1){
				pii t_interval = {MAX[pp - 1].second + 1, MAX[pp].second + 1};
				pii real_interval = merge(cur_interval, t_interval);

				if (real_interval.second > real_interval.first)
					st.update(1, 0, n, real_interval.first, real_interval.second, 1);
			}
		}


		MIN.push_back({B[i], i});
		MIN_POS[B[i]] = MIN.size() - 1;

		ans += st.sum[1];
	}

	cout << ans << endl;

	return 0;
}