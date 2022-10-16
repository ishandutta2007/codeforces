/*input
2
1 1 1
*/
#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define endl '\n'
#define fi first
#define se second
#define mp make_pair
#define N 300005
#define bit(x,y) ((x>>y)&1LL)
#define na(x) (#x) << ":" << x
ostream& operator << (ostream &os, vector<int>&x) {
	for (int i = 0; i < x.size(); i++) os << x[i] << sp;
	return os;
}
ostream& operator << (ostream &os, pair<int, int> x) {
	cout << x.fi << sp << x.se << sp;
	return os;
}
ostream& operator << (ostream &os, vector<pair<int, int> >&x) {
	for (int i = 0; i < x.size(); i++) os << x[i] << endl;
	return os;
}
class Tree {
public:
	int par[N];
	vector<int> prevLev, curLev;
	vector<pair<int, int> > edge;
	void addEdge(int u, int v) {
		if (u != 0) edge.push_back(mp(u, v));
		par[v] = u;
		curLev.push_back(v);
	}
	void clear() {
		prevLev = curLev;
		curLev.clear();
	}
} T1, T2;

bool done = false;
int n;
int a[N];
int peak = 0;
signed main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n + 1; i++) cin >> a[i];
	T1.addEdge(0, 1); T2.addEdge(0, 1);
	T1.clear(); T2.clear();
	peak = 1;
	for (int i = 2; i <= n + 1; i++) {
		if (done) {
			for (int j = 1; j <= a[i]; j++) {
				peak++;
				T1.addEdge(T1.prevLev.back(), peak);
				T2.addEdge(T2.prevLev.back(), peak);
			}
		}
		else {
			if (a[i] == 1 || T1.prevLev.size() == 1) {
				for (int j = 1; j <= a[i]; j++) {
					peak++;
					T1.addEdge(T1.prevLev.back(), peak);
					T2.addEdge(T2.prevLev.back(), peak);
				}
			}
			else {
				done = true;
				for (int j = 1; j <= a[i]; j++)
					T1.addEdge(T1.prevLev.back(), peak + j);
				T2.addEdge(T2.prevLev.front(), peak + 1);
				for (int j = 2; j <= a[i]; j++)
					T2.addEdge(T2.prevLev.back(), peak + j);
				peak += a[i];
			}
		}
		T1.clear(); T2.clear();
	}
	if (!done) {
		cout << "perfect" << endl;
		exit(0);
	}
	cout << "ambiguous" << endl;
	for (int i = 1; i <= peak; i++) cout << T1.par[i] << sp;
	cout << endl;
	for (int i = 1; i <= peak; i++) cout << T2.par[i] << sp;
	cout << endl;
	// cout << endl;
	// cout << T2.edge << endl;
}