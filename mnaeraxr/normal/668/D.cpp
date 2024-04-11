#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef vector<int> vi;
typedef pair<int,int> pii;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100010;

struct bit{
	int n;
	unordered_map<int,int> d;

	bit() {}

	bit(int n) : n(n) {}

	void update(int x, int v){
		while (x < n){
			d[x] += v;
//			cout << "upd: " << x << endl;
			x += x & -x;
		}
	}

	int query(int x){
		int ans = 0;
		while (x){
			if (d.count(x)) ans += d[x];
//			cout << "que: " << x << endl;
			x -= x & -x;
//			cout << x << endl;
		}
		return ans;
	}
};

map<int, bit> M;

struct event{
	int m, t, x;
	void read(){
		cin >> m >> t >> x;
	}
};

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	vector<event> v(n);
	vector<int> coord;
	for (int i = 0; i < n; ++i){
		v[i].read();
		coord.push_back(v[i].t);
	}

	sort(coord.begin(), coord.end());
	coord.resize(unique(coord.begin(), coord.end()) - coord.begin());

	int tot = coord.size() + 2;

	for (int i = 0; i < n; ++i){
		v[i].t = lower_bound(coord.begin(), coord.end(), v[i].t) - coord.begin() + 1;
		if (!M.count(v[i].x)) M[v[i].x] = bit(tot);
	}

//	for (auto el : M)
//		cout << el.first << " " << el.second.n << endl;

	for (int i = 0; i < n; ++i){
		if (v[i].m == 1){
//			cout << "add: " << v[i].x << " " << v[i].t << endl;
			M[v[i].x].update(v[i].t, +1);
		}
		else if (v[i].m == 2){
//			cout << "remove: " << v[i].x << " " << v[i].t << endl;
			M[v[i].x].update(v[i].t, -1);
		}
		else{
//			cout << "query: " << v[i].x << " " << v[i].t << endl;
			cout << M[v[i].x].query(v[i].t)<< endl;
		}
	}

	return 0;
}