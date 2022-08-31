#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MAXN = 2e5;
int N, K;
ll A[MAXN];

int main() {
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
		A[i] += A[i-1];
	}
	if (A[N] % K != 0) {
		cout << "No\n";
		return 0;
	}
	ll d = A[N] / K;

	map<ll, int> mp;
	for (int i = 0; i <= N; i++) mp[A[i]] = i;
	vector<int> res;
	ll prv = 0;
	for (int i = 1; i <= K; i++) {
		if (!mp.count(d * i)) {
			cout << "No\n";
			return 0;
		}
		ll cur = mp[d*i];
		res.push_back(cur - prv);
		prv = cur;
	}
	cout << "Yes\n";
	for (int i = 0; i < K; i++) {
		cout << res[i] << " \n"[i == K-1];
	}
}