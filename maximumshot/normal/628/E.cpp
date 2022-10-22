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
#include <queue>

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

int bp(const vec< int > & a, int x) {
	if(a.empty()) return 0;
	int l, r, m;
	l = 0, r = (int)a.size() - 1;
	while(r - l > 1) {
		m = (l + r) / 2;
		if(a[m] >= x) r = m;
		else l = m + 1;
	}
	if(a[l] >= x) return (int)a.size() - l;
	else if(a[r] >= x) return (int)a.size() - r;
	else return 0;
}

vec< vec< int > > t; 

void up(int v) {
	t[v].clear();
	int ls, rs, l, r;
	ls = (int)t[v * 2 + 1].size(), l = 0;
	rs = (int)t[v * 2 + 2].size(), r = 0;
	while(l < ls && r < rs) {
		if(t[v * 2 + 1][l] <= t[v * 2 + 2][r]) {
			t[v].push_back(t[v * 2 + 1][l++]);
		}else {
			t[v].push_back(t[v * 2 + 2][r++]);
		}
	}
	while(l < ls) t[v].push_back(t[v * 2 + 1][l++]);
	while(r < rs) t[v].push_back(t[v * 2 + 2][r++]);
}

void build(const vec< int > & a, int v, int tl, int tr) {
	if(tl == tr) {
		t[v].clear();
		t[v].push_back(a[tl]);
	}else {
		int tm = (tl + tr) / 2;
		build(a, v * 2 + 1, tl, tm);
		build(a, v * 2 + 2, tm + 1, tr);
		up(v);
	}
}

int get(int v, int tl, int tr, int l, int r, int x) {
	if(l > r) return 0;
	if(l <= tl && tr <= r) return bp(t[v], x);
	else {
		int tm = (tl + tr) / 2, ans = 0;
		if(l <= tm) ans += get(v * 2 + 1, tl, tm, l, r, x);
		if(r > tm) ans += get(v * 2 + 2, tm + 1, tr, l, r, x);
		return ans;
	}
}

bool solve() {

	int n, m;

	scanf("%d %d", &n, &m);

	vec< vec< char > > mat(n, vec< char >(m));

	for(int i = 0;i < n;i++) {
		char c;
		for(int j = 0;j < m;j++) {
			scanf(" %c", &c);
			mat[i][j] = (c == 'z');
		}
	}

	vec< vec< int > > l(n, vec< int >(m)), r = l;

	for(int i = 0;i < n;i++) {
		if(mat[i][0]) l[i][0] = 1;
		for(int j = 1;j < m;j++) {
			if(mat[i][j]) l[i][j] = 1 + l[i][j - 1];
			else l[i][j] = 0;
		}
		if(mat[i][m - 1]) r[i][m - 1] = 1;
		for(int j = m - 2;j >= 0;j--) {
			if(mat[i][j]) r[i][j] = 1 + r[i][j + 1];
			else r[i][j] = 0;
		}
	}

	vec< vec< int  > > cur(n, vec< int >(m, -1));
	vec< int > last(n + m, 0);
	vec< vec< int > > crd(n + m, vec< int >(min(n, m), -1));

	for(int i = n - 1;i >= 0;i--) {
		for(int j = 0;j < m;j++) {
			cur[i][j] = last[i + j];
			crd[i + j][ last[i + j]++ ] = j; 
		}
	}

	vec< int > T;

	t.resize(4 * min(n, m));

	ll ans = 0;

	for(int diag = 0;diag < n + m - 1;diag++) {
		T.clear();
		for(int it = 0;it < last[diag];it++) {
			if(mat[ diag - crd[diag][it] ][ crd[diag][it] ]) 
				T.push_back(crd[diag][it] + r[ diag - crd[diag][it] ][ crd[diag][it] ] - 1);
			else 
				T.push_back(-1);
		}

		/*cout << diag << " : ";
		for(auto it : T) cout << it << ' ';
		cout << '\n';

		cout << "Ask : \n";*/

		build(T, 0, 0, last[diag] - 1);
		for(int back = -1, it = 0;it < last[diag];it++) {
			//cout << "[ " << max(back + 1, it - l[ diag - crd[diag][it] ][ crd[diag][it] ] + 1) << " .. " << it << " ] value = " << crd[diag][it] << " : " <<
			//	get(0, 0, last[diag] - 1, max(back + 1, it - l[ diag - crd[diag][it] ][ crd[diag][it] ] + 1), it, crd[diag][it]) << '\n'; 
			if(mat[ diag - crd[diag][it] ][ crd[diag][it] ]) {
				ans += get(0, 0, last[diag] - 1, max(back + 1, it - l[ diag - crd[diag][it] ][ crd[diag][it] ] + 1), it, crd[diag][it]);
			}else {
				back = it;
			}
		}

		//cout << "\n";
	}

	cout << ans << '\n';

	return true;
}

int main() {

	//while(solve());
	solve();
	
	return 0;
}