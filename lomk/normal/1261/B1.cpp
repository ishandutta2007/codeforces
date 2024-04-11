/*input
7
1 2 1 3 1 2 1
9
2 1
2 2
3 1
3 2
3 3
1 1
7 1
7 7
7 4

3
10 20 10
6
1 1
2 1
2 2
3 1
3 2
3 3

*/
#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define endl '\n'
#define mp make_pair
#define fi first
#define se second
#define __builtin_popcount __builtin_popcountll
#define loop(i,l,r) for(int i=(l); i<=(r); i++)
#define rloop(i,l,r) for(int i=(l); i>=(r); i--)
#define bit(x,y) ((x>>y)&1LL)
const int N = 2e5 + 5;
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

int n;
int sum[N];
vector<pair<int, int> > a;
vector<int> b;
int ansToQuery[N];
struct BITx {
	int tree[N];
	void update(int i, int val) {
		i++;
		for (; i < N; i += i & -i) tree[i] += val;
	}
	int get(int i) {
		i++;
		int ret = 0;
		for (; i; i -= i & -i) ret += tree[i];
		return ret;
	}
	int get(int l, int r) {return get(r) - get(l - 1);}
} BIT;

struct Query {
	int len, pos, id;
	Query(int _len, int _pos, int _id): len(_len), pos(_pos), id(_id) {};
};

vector<Query> query;
signed main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	loop(i, 0, n - 1) {
		int t; cin >> t;
		a.push_back(mp(t, i));
		b.push_back(t);
	}
	sort(a.begin(), a.end(), [&](pair<int, int> X, pair<int, int> Y) {
		if (X.fi != Y.fi) return X.fi > Y.fi;
		return X.se < Y.se;
	});
	int q; cin >> q;
	loop(i, 1, q) {
		int len, pos; cin >> len >> pos;
		query.push_back(Query(len, pos, i));
	}
	sort(query.begin(), query.end(), [&](Query X, Query Y) {
		return X.len < Y.len;
	});
	int pivot = 0;
	for (auto &curQuery : query) {
		while (pivot < curQuery.len) {
			BIT.update(a[pivot].se, 1);
			pivot++;
		}
		int l = 0, r = n - 1;
		while (l != r) {
			int mid = (l + r) / 2;
			if (BIT.get(mid) >= curQuery.pos) r = mid;
			else l = mid + 1;
		}
		ansToQuery[curQuery.id] = b[l];
	}
	loop(i, 1, q) cout << ansToQuery[i] << endl;
}