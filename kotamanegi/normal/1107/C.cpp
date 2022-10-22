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
void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> inputs;
	REP(i, n) {
		int a;
		cin >> a;
		inputs.push_back(a);
	}
	string s;
	cin >> s;
	s.push_back(' ');
	inputs.push_back(0);
	priority_queue<int> nexts;
	int ans = 0;
	nexts.push(inputs[0]);
	for (int q = 1; q < s.length(); ++q) {
		if (s[q] != s[q - 1]) {
			int cnt = 0;
			while (nexts.empty() == false) {
				if(cnt < k)
				ans += nexts.top();
				nexts.pop();
				cnt++;
			}
		}
		nexts.push(inputs[q]);
	}
	cout << ans << endl;
}
#undef int
int main() {
	init();
	solve();
}