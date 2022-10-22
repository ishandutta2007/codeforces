#define  _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES

#pragma comment (linker, "/STACK:526000000")

#include "bits/stdc++.h"
#define int ll

using namespace std;
typedef string::const_iterator State;
#define eps 1e-9L
#define MAX_MOD 1000000007LL
#define GYAKU 500000004LL
#define MOD 998244353LL
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef long double ld;
#define REP(a,b) for(long long (a) = 0;(a) < (b);++(a))
#define ALL(x) (x).begin(),(x).end()
void init() {
	iostream::sync_with_stdio(false);
	cout << fixed << setprecision(20);
}
void solve(){
	string a, b;
	cin >> a >> b;
	vector<int> inputs;
	REP(i, a.length()) {
		int c;
		cin >> c;
		inputs.push_back(c);
	}
	int bot = 0;
	int top = a.length();
	while (top - bot > 1) {
		int mid = (bot + top) / 2;
		string geko;
		vector<int> bad(a.length(), 0);
		REP(q, mid) {
			bad[inputs[q] - 1] = 1;
		}
		REP(i, a.length()) {
			if (bad[i] == 0) {
				geko.push_back(a[i]);
			}
		}
		int itr = 0;
		REP(i, geko.size()) {
			if (geko[i] == b[itr]) {
				itr++;
				if (itr == b.length()) break;
			}
		}
		if (itr == b.length()) bot = mid;
		else top = mid;
	}
	cout << bot << endl;
}
#undef int
int main() {
	init();
	solve();
}