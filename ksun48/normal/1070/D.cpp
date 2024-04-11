#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 2e5;
int N;
ll A[MAXN];

ll K;

int main() {
	ios_base::sync_with_stdio(0);
	cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> A[i];
	ll res = 0;
	ll left = 0;
	for (int i = 0; i < N; i++) {
		if (left) {
			assert(left < K);
			A[i] = max(0ll, A[i] - (K - left));
			res++;
			left = 0;
		}
		res += A[i] / K;
		A[i] %= K;
		left = A[i];
	}
	assert(left < K);
	if (left) {
		res++;
	}
	cout << res << '\n';
}