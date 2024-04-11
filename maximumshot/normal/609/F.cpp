#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <set>
#include <string>
#include <tuple>
#include <fstream>
#include <stdio.h>
#include <cstring>
#include <map>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair< int, int > pii;

const int inf = 1000000000;
const ll inf64 = 1ll * inf * inf;
const double pi = acos(-1.0);

int bp(const vec< pii > & a, int x) {
	if(a.empty()) return -1;
	int l = 0, r = (int)a.size() - 1, m;
	while(r - l > 1) {
		m = (l + r) / 2;
		if(a[m].first >= x) r = m;
		else l = m + 1;
	}
	return (a[l].first == x?a[l].second : (a[r].first == x?a[r].second : -1));
}

struct segment_tree {
	int n;
	vec< int > t;

	segment_tree() {
		n = 0;
	}

	segment_tree(int _n) : n(_n) {
		t.resize(4 * n, inf + 10);		
	}

	void push(int v) {
		if(t[v] != inf + 10) {
			t[v * 2 + 1] = min(t[v * 2 + 1], t[v]);
			t[v * 2 + 2] = min(t[v * 2 + 2], t[v]);
			t[v] = inf + 10;
		}
	}

	void upd(int v, int tl, int tr, int l, int r, int x) {
		if(l <= tl && tr <= r) t[v] = min(t[v], x);
		else {
			int tm = (tl + tr) / 2;
			push(v);
			if(l <= tm) upd(v * 2 + 1, tl, tm, l, r, x);
			if(r > tm) upd(v * 2 + 2, tm + 1, tr, l, r, x);
		}
	}

	void upd(int l, int r, int x) {
		if(l > r) return;
		upd(0, 0, n - 1, l, r, x);
	}

	int get(int v, int tl, int tr, int p) {
		if(tl == tr) return t[v];
		else {
			int tm = (tl + tr) / 2;
			push(v);
			if(p <= tm) return get(v * 2 + 1, tl, tm, p);
			else return get(v * 2 + 2, tm + 1, tr, p);
		}
	}

	int get(int p) {
		return get(0, 0, n - 1, p);
	}

	void print(int v, int tl, int tr) {
		if(tl == tr) cout << t[v] << " ";
		else {
			int tm = (tl + tr) / 2;
			push(v);
			print(v * 2 + 1, tl, tm);
			print(v * 2 + 2, tm + 1, tr); 
		}
	}

	void print() {
		cout << "\n";
		print(0, 0, n - 1);
		cout << "\n";
	}
};

bool solve() {
	
	int n, m;

	cin >> n >> m;

	vec< int > pos(n), c(n);
	vec< ll > len(n), crd;
	vec< pii > tmp;

	for(int i = 0;i < n;i++) {
		//cin >> pos[i] >> len[i];
		scanf("%d %I64d", &pos[i], &len[i]);
		crd.push_back(pos[i]);
		tmp.push_back(mp(pos[i], i));
	}

	sort(ALL(tmp));
	
	vec< pii > Q(m); 

	for(int i = 0;i < m;i++) {
		int p, b;
		//cin >> p >> b;
		scanf("%d %d", &p, &b);
		Q[i] = mp(p, b);
		crd.push_back(p);
	}

	sort(ALL(crd));
	crd.resize(unique(ALL(crd)) - crd.begin());

	int sz = (int)crd.size();

	segment_tree st(sz);

	for(int i = 0;i < n;i++) {
		int l, r;
		
		l = lower_bound(ALL(crd), 1ll * pos[i]) - crd.begin();
		r = (upper_bound(ALL(crd), pos[i] + len[i]) - crd.begin()) - 1;

		// [l .. r]

		st.upd(l, r, pos[i]);
	}

	set< pair< int, pair< ll, int > > > useless;
	set< pair< int, pair< ll, int > > > :: iterator cur;

	for(int i = 0;i < m;i++) {
		int p, b;
		tie(p, b) = Q[i];
		int pp = lower_bound(ALL(crd), p) - crd.begin();
		int value = st.get(pp);
		if(value != inf + 10) {
			int frog_id = bp(tmp, value);
			c[frog_id]++;
			len[frog_id] += b;
			
			set< pair< int, pair< ll, int > > > T;
			
			cur = useless.lower_bound(mp(pos[frog_id], mp(-inf, -inf)));
			for(;cur != useless.end();cur++) {
				if(cur->first > pos[frog_id] + len[frog_id]) break;
				T.insert(*cur);
				len[frog_id] += cur->second.first;
				c[frog_id] += cur->second.second;
			}

			/*for(auto it : useless) {
				if(pos[frog_id] <= it.first && 1ll * it.first <= pos[frog_id] + len[frog_id]) {
					T.insert(it);
					c[frog_id] += it.second.second;
					len[frog_id] += it.second.first;
				}
			}*/
			
			for(auto it : T) useless.erase(it);

			int l, r;
			l = lower_bound(ALL(crd), pos[frog_id]) - crd.begin();
			r = (upper_bound(ALL(crd), pos[frog_id] + len[frog_id]) - crd.begin()) - 1;
			st.upd(l, r, pos[frog_id]);
			
		}else {

			cur = useless.lower_bound(mp(p, mp(-inf, -inf)));
			if(cur == useless.end() || cur->first != p) 
				useless.insert(mp(p, mp(b, 1)));
			else {
				pair< int, pair< ll, int > > T = *cur;
				useless.erase(T);
				T.second.first += b;
				T.second.second++;
				useless.insert(T);
			}

			/*pair< int, pair< ll, int > > T;
			int ok = 0;
			for(auto it : useless) {
				if(it.first == p) {
					ok = 1;
					T = it;
					break;
				}
			}

			if(ok) {
				useless.erase(T);
				T.second.first += b;
				T.second.second++;
				useless.insert(T);
			}else useless.insert(mp(p, mp(b, 1)));*/
		} 
	}

	for(int i = 0;i < n;i++) printf("%d %I64d\n", c[i], len[i]);

	return true;
}

int main() {

	//while(solve());
	solve();
	
	return 0;
}