#define  _CRT_SECURE_NO_WARNINGS
#pragma comment (linker, "/STACK:526000000")

#include "bits/stdc++.h"

using namespace std;
typedef string::const_iterator State;
#define eps 1e-11L
#define MAX_MOD 1000000007LL
#define GYAKU 500000004LL

#define MOD 998244353LL
#define seg_size 262144*2LL
#define pb push_back
#define mp make_pair
typedef long long ll;
#define REP(a,b) for(long long (a) = 0;(a) < (b);++(a))
#define ALL(x) (x).begin(),(x).end()

unsigned long xor128() {
	static unsigned long x = 123456789, y = 362436069, z = 521288629, w = time(NULL);
	unsigned long t = (x ^ (x << 11));
	x = y; y = z; z = w;
	return (w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));
}

void init() {
	iostream::sync_with_stdio(false);
	cout << fixed << setprecision(10);
}

#define int ll
void solve() {
	int n;
	cin >> n;
	vector<pair<int, int>> gogo;
	REP(i, n) {
		int a;
		cin >> a;
		gogo.push_back(mp(a, 0));
	}
	REP(i, n) {
		cin >> gogo[i].second;
	}
	map<int, vector<int>> inputs;
	REP(i, n) {
		inputs[gogo[i].first].push_back(gogo[i].second);
	}
	int ans = 0;
	int back = 0;
	int total_val = 0;
	priority_queue<int> next;
	inputs[2e9].push_back(0);
	for (auto x = inputs.begin(); x != inputs.end(); ++x) {
		if (x != inputs.begin()) {
			while (next.empty() == false && back < x->first) {
				back++;
				total_val -= next.top();
				next.pop();
				ans += total_val;
			}
		}
		REP(q, x -> second.size()) {
			next.push(x->second[q]);
			total_val += x->second[q];
		}
		back = x->first;
	}
	cout << ans << endl;
}
#undef int
int main() {
	init();
	solve();
}