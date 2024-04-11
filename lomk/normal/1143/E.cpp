/*input
2 4 3
2 1
1 1 2 2
1 2
2 3
3 4

*/
#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define endl '\n'
#define fi first
#define se second
#define mp make_pair
#define __builtin_popcount __builtin_popcountll
#define bit(x,y) ((x>>y)&1LL)
#define loop(i,l,r) for(int i=(int)l; i<=(int)r; i++)
#define rloop(i,l,r) for(int i=(int)l; i>=(int)r; i--)
const int N = 200005;
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
int read() {
	int x; cin >> x; return x;
}

int len, n, q;
int mask[N];
vector<int> perm;
vector<int> a;
int jump[N][19];
int soonest[N];

int last[N];

int pre(int x) {
	if (x != 1) return x - 1;
	return len;
}

signed main() {
#ifndef UncleGrandpa
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#endif
	cin >> len >> n >> q;
	loop(i, 1, len) {
		int t; cin >> t;
		mask[t] = i;
	}
	loop(i, 1, n) {
		int t; cin >> t; t = mask[t];
		a.push_back(t);
	}
	memset(last, -1, sizeof(last));
	loop(i, 0, n - 1) {
		loop(k, 0, 18) {
			if (k == 0)
				jump[i][0] = last[pre(a[i])];
			else {
				if (jump[i][k - 1] == -1)
					jump[i][k] = -1;
				else
					jump[i][k] = jump[jump[i][k - 1]][k - 1];
			}
		}
		int &cur = soonest[i]; cur = i;
		int dis = len - 1;
		loop(k, 0, 18) {
			if (bit(dis, k)) {
				cur = jump[cur][k];
				if (cur == -1) break;
			}
		}
		if (i)
			soonest[i] = max(soonest[i], soonest[i - 1]);
		last[a[i]] = i;
	}
	loop(i, 1, q) {
		int l, r; cin >> l >> r; l--; r--;
		if (soonest[r] >= l) cout << 1;
		else cout << 0;
	}
}