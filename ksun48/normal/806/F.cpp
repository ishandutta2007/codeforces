#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;
using i128 = __int128_t;

static int minv(int a, int m) {
	a %= m;
	assert(a);
	return a == 1 ? 1 : int(m - ll(minv(m, a)) * ll(m) / a);
}

int MOD;

pair<int,int> factor(int k){
	if(!k) return {1, 0};
	int b = 1;
	while(true){
		int g = gcd(MOD, k);
		if (g == 1) break;
		b *= g;
		k /= g;
	}
	return {k, b};
}

int solve(int a, int b){
	int A = 2 * a + 2;
	int B = 2 * b + 40;
	vector<int> ncr(B+1, 0);
	{
		i128 r = 1, nr = 1;
		for(int i = 0; i <= B; i++){
			ncr[i] = int((r * nr) % MOD);
			if(i == A) break;
			auto [tr, tnr] = factor(A - i);
			auto [br, bnr] = factor(i + 1);
			r = (r * tr * minv(br, MOD)) % MOD;
			nr = (nr * tnr) / bnr;
		}
	}
	int OD = MOD >> (__builtin_ctz(MOD));
	int val = (a + 1) % MOD;
	int ans = 0;
	for(int i = 1; i < B; i++){
		val = ncr[i+1] - val;
		if(val & 1) val += OD;
		val /= 2;
	}
	for(int i = B-1; i >= 0; i--){
		if(i <= 2*b && i % 2 == 0) ans = (ans + val) % MOD;
		val = (ncr[i+1] - val * 2) % MOD;
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int N, A;
	cin >> N >> A >> MOD;
	A /= 2;
	int ans = 0;
	while(A){
		ans += solve((A-1) / 2, (N-1) / 2);
		ans %= MOD;
		A /= 2;
	}
	if(ans < 0) ans += MOD;
	cout << ans << '\n';
}