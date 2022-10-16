#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int64 oo = 1000000000000000000LL;
const double eps = 1e-9;
const int maxn = 200000 + 10;
const int mod = 1000000007;

void add(int &a, int b){
	a += b;
	if (a >= mod)
		a -= mod;
}

struct node{
	int begin, end;
	int height, max_height;
	int multiplier;

	bool operator <(const node &a) const{
		return height < a.height;
	}

} V[ maxn ];

struct segment_tree{
	vector< set<pii> > data;

	segment_tree(int n){
		data = vector< set<pii> >(4 * n);
	}

	void update(int p, int b, int e, int x, int y, int idx){
		if (x <= b && e <= y){
			if (idx < 0)
				data[p].erase( {V[-idx].height, -idx} );
			else
				data[p].insert( {V[idx].height, idx});
		}
		else{
			int m = (b + e) >> 1, l = p << 1, r = l | 1;
			if (x < m) update(l, b, m, x, y, idx);
			if (m < y) update(r, m, e, x, y, idx);
		}
	}

	int query(int p, int b, int e, int x){
		int ans = 0;

		while (b + 1 < e){

			int m = (b + e) >> 1, l = p << 1, r = l | 1;
			if (x < m) p = l, e = m;
			else       p = r, b = m;

			if (!data[ p ].empty()){
				int idx = data[p].rbegin()->second;
				if (V[idx].height > V[ans].height)
					ans = idx;
			}
		}

		return ans;
	}
};

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int h, w, n;

	cin >> h >> w >> n;

	for (int i = 0; i < n; ++i){
		int u, l, r, s;
		cin >> u >> l >> r >> s;

		V[i] = {l, r, u, u + s, 0};
	}

	V[n] = {1, w, 0, h + 1, 1};

	sort(V, V + n + 1);

	segment_tree st(w);
	st.update(1, 0, w, 0, w, 0);

	for (int i = 1; i <= n; ++i){
		int b = V[i].begin, e = V[i].end;
		int h = V[i].height;

		int p1 = b == 1 ? e + 1 : b - 1;
		int p2 = e == w ? b - 1 : e + 1;

		vector<int> pos = {p1, p2};

		for (auto p : pos){
			while (true){
				int idx = st.query(1, 0, w, p - 1);

				if ( V[idx].max_height < h )
					st.update(1, 0, w, V[idx].begin - 1, V[idx].end, -idx);
				else{
					add( V[i].multiplier, V[ idx ].multiplier );
					break;
				}
			}
		}

		st.update(1, 0, w, V[i].begin - 1, V[i].end, i);
	}

	int answer = 0;

	for (int i = 0; i < w; ++i){
		while (true){
			int idx = st.query(1, 0, w, i);

			if (V[idx].max_height < h + 1)
				st.update(1, 0, w, V[idx].begin - 1, V[idx].end, -idx);
			else{
				add(answer, V[idx].multiplier);
				break;
			}
		}
	}

	cout << answer << endl;

	return 0;
}