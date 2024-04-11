#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

const int N = 1e6;
int val[N];
int pre[N];
int nex[N];

ll count(int len, int k) {
	// for piece length i, the answer is (len+1 - i)
	// the piece lengths are:
	// 1 +  (k-1)
	// 1 + 2(k-1)
	// 1 + 3(k-1)
	// ...
	// So the answer for the i'th is len - i(k-1).
	ll n = len / (k-1);
	// our answer is \sum_{i = 1}^{n} len - i(k-1) = n * len - (k-1) \sum_{i = 1}^{n} i
	// = n * len - (k-1) * (n * (n+1) / 2).
	ll res = n * len - (k-1) * (n * (n+1) / 2);
	return res % MOD;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	
	for (int i = 0; i < n; ++i) cin >> val[i];
	
	vector<int> stack;
	for (int i = 0; i < n; ++i) {
		while((stack.size() > 0) && (val[stack.back()] <= val[i])) stack.pop_back();
		if (stack.empty()) pre[i] = 0;
		else pre[i] = stack.back() + 1;
		stack.push_back(i);
	}
	stack.clear();
	
	for (int i = n-1; i >= 0; --i) {
		while((stack.size() > 0) && (val[stack.back()] < val[i])) stack.pop_back();
		if (stack.empty()) nex[i] = n-1;
		else nex[i] = stack.back() - 1;
		stack.push_back(i);
	}
	stack.clear();

	// COU[i] = how many intervals in [pre[i], nex[i]] contain i?
	// res = \sum_{i = 1}^{n} COU[i] * VAL[i];
	// Use inclusion exclusion to find COU[i].

	ll res = 0;
	for (int i = 0; i < n; ++i) {
		ll len = nex[i] - pre[i] + 1;
		ll lef = i - pre[i];
		ll rig = nex[i] - i;
		ll cou = count(len, k) - count(lef, k) - count(rig, k);

		cou %= MOD;
		res += (cou * val[i]) % MOD;
	}
	cout << res % MOD << '\n';
}