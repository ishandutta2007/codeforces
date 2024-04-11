#pragma comment (linker, "/STACK:526000000")
#define  _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"

using namespace std;
typedef string::const_iterator State;
#define eps 1e-11L
#define MAX_MOD 1000000007LL
#define GYAKU 500000004LL

#define MOD 998244353LL
#define seg_size 262144
#define pb push_back
#define mp make_pair
typedef long long ll;
#define REP(a,b) for(long long (a) = 0;(a) < (b);++(a))
#define ALL(x) (x).begin(),(x).end()

void init() {
	iostream::sync_with_stdio(false);
	cout << fixed << setprecision(100);
}

int coloring[300] = {};
int union_tree[600] = {};
int union_find(int now) {
	if (union_tree[now] == now) return now;
	return union_tree[now] = union_find(union_tree[now]);
}
int union_merge(int a, int b) {
	a = union_find(a);
	b = union_find(b);
	union_tree[a] = b;
	return 0;
}
void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	REP(t, 600) {
		union_tree[t] = t;
	}
	REP(i, s.length()) {
		REP(q, i) {
			if (s[q] > s[i]) {
				//must be different.
				union_merge(q * 2, i * 2 + 1);
				union_merge(q * 2 + 1, i * 2);
			}
		}
	}
	REP(i, s.length()) {
		if (union_find(i * 2) == union_find(i * 2 + 1)) {
			cout << "NO" << endl;
			return;
		}
	}
    set<int> geko;
	REP(i, s.length()) {
		int ok = 0;
		REP(q, 2) {
			int hoge = union_find(i * 2 + q);
			if (geko.find(hoge) != geko.end()) {
				coloring[i] = q;
				ok = 1;
				break;
			}
		}
		if(ok == 0){
			coloring[i] = 0;
			geko.insert(union_find(i * 2));
		}
	}
	cout << "YES" << endl;
	REP(i, s.length()) {
		cout << coloring[i];
	}
	cout << endl;
	return;
 }

int main() {
	init();
	solve();
}