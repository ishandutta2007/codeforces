/*input
2
4
bbcb
aada
aada
3
abc
bbb
bbb
*/
#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define endl '\n'
#define fi first
#define se second
#define mp make_pair
#define __builtin_popcount __builtin_popcountll
#define int long long
#define bit(x,y) ((x>>y)&1LL)
#define loop(i,l,r) for(int i=(int)l; i<=(int)r; i++)
#define rloop(i,l,r) for(int i=(int)l; i>=(int)r; i--)
//const int N=;
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

int m;
vector<int> ori, a, b;
set<int> st;
int conv[26]; bool used[26];
string ans;

bool back(int pos) {
	if (pos == ori.size()) return true;
	int &now = conv[ori[pos]];
	if (now != -1) {
		if (now == a[pos])return back(pos + 1);
		else if (now < a[pos]) return false;
		else return true;
	}
	else {
		if (!used[a[pos]]) {
			now = a[pos]; used[a[pos]] = true;
			auto rec = back(pos + 1);
			if (rec) return true;
			now = -1; used[a[pos]] = false;
		}
		loop(i, a[pos] + 1, m - 1) {
			if (!used[i]) {
				now = i; used[i] = true;
				return true;
			}
		}
	}
	return false;
}

signed main() {
#ifndef UncleGrandpa
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#endif
	int T; cin >> T;
	while (T--) {
		auto transNum = [&](string & s, vector<int> &inp) {
			for (auto it : s) inp.push_back(it - 'a');
		};
		auto reset = [&]() {
			st.clear(); a.clear(); b.clear(); ori.clear();
			memset(conv, -1, sizeof(conv)); memset(used, 0, sizeof(used)); ans = "";
		};
		reset();
		cin >> m;
		string s;
		cin >> s; transNum(s, ori);
		cin >> s; transNum(s, a);
		cin >> s; transNum(s, b);
		bool ok = true;
		if (back(0)) {
			int it = 0;
			loop(i, 0, ori.size() - 1) {
				int &t = conv[ori[i]];
				if (t == -1) {
					while (used[it])
						it++;
					t = it; it++;
				}
				if (t != b[i]) {
					if (t > b[i]) ok = false;
					break;
				}
			}
			loop(i, 0, m - 1) {
				int &t = conv[i];
				if (t == -1) {
					while (used[it])
						it++;
					t = it; it++;
				}
			}
			loop(i, 0, m - 1)ans += char('a' + conv[i]);
		}
		else ok = false;
		if (ok) {
			cout << "YES" << endl;
			cout << ans << endl;
		}
		else cout << "NO" << endl;
		// try backtrack, then check with b
	}
}