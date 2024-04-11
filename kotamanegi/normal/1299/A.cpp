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

#define int ll
void solve(){
	int n;
	cin >> n;
	vector<int> inputs;
	REP(i, n) {
		int a;
		cin >> a;
		inputs.push_back(a);
	}
	sort(ALL(inputs));
	reverse(ALL(inputs));
	int gogo = 0;
	REP(i, 30) {
		int hoge = 0;
		REP(q, inputs.size()) {
			if ((1 << i) & inputs[q]) {
				hoge++;
			}
		}
		if (hoge == 1) {
			gogo += (1 << i);
		}
	}
	int now_max = -1;
	int now_itr = 0;
	REP(i, inputs.size()) {
		int hoge = (gogo & inputs[i]);
		if (hoge > now_max) {
			now_max = hoge;
			now_itr = i;
		}
	}
	cout << inputs[now_itr];
	REP(i, inputs.size()) {
		if (now_itr == i) continue;
		cout << " " << inputs[i];
	}
	cout << endl;
}
#undef int
int main() {
	init();
	solve();
}