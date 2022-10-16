#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100000 + 10;

int64 getpoints(int64 a, int64 b){
	if (2LL * a > b) return 500LL;
	if (4LL * a > b) return 1000LL;
	if (8LL * a > b) return 1500LL;
	if (16LL * a > b) return 2000LL;
	if (32LL * a > b) return 2500LL;
	return 3000LL;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

#ifdef MARX
	freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
#endif

	vector<int64> sol(5);
	vector<bool> can(5);
	vector<int64> delta(5);

	int n; cin >> n;

	for (int i = 0; i < 2; ++i){
		for (int j = 0; j < 5; ++j){
			int64 v; cin >> v;

			if (i == 0 && v >= 0)
				can[j] = true;
			
			if (v == -1) v = 250;
			else sol[j]++;

			if (i == 0) delta[j] -= v;
			else delta[j] += v;
		}
	}

	for (int i = 2; i < n; ++i){
		for (int j = 0; j < 5; ++j){
			int64 v; cin >> v;
			if (v != -1) 
				sol[j]++;
		}
	}

	// for (int i = 0; i < 5; ++i)
	// 	cout << sol[i] << " ";
	// cout << endl;

	int64 lo = 0, hi = 1000000007;

	auto eval = [&](int64 t, bool dbg=false){
		int64 answer = 0;
		for (int i = 0; i < 5; ++i){
			int64 cur = getpoints( (delta[i] < 0 && can[i]? (t + sol[i]) : sol[i]), t + n);
			answer += delta[i] * cur;
		}
		return answer;
	};

	for (int i = 0; i <= 6000; ++i)
		if (eval(i) > 0){
			cout << i << endl;
			return 0;
		}

	cout << -1 << endl;

	return 0;
}