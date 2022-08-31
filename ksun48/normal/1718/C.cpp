#include <bits/stdc++.h>
using namespace std;

const int X = 1e6;

bitset<X> is_prime;
vector<int> pr;
vector<int> pf(X);

void init(){
	is_prime.flip();
	is_prime[0] = is_prime[1] = false;
	for(int i = 2; i < X; i++){
		if(is_prime[i]){
			pr.push_back(i);
			pf[i] = i;
		}
		for(int p : pr){
			if(i * p >= X) break;
			is_prime[i * p] = false;
			pf[i * p] = p;
			if(i % p == 0) break;
		}
	}
}

using ll = int64_t;

void solve(){
	int N, Q;
	cin >> N >> Q;
	vector<ll> a(N);
	for(ll& x : a) cin >> x;
	vector<int> pfact;
	{
		int cN = N;
		while(cN > 1){
			int p = pf[cN];
			pfact.push_back(p);
			while(cN % p == 0) cN /= p;
		}
	};

	int P = (int)pfact.size();
	vector<vector<ll> > sums;
	multiset<ll> best;
	for(int i = 0; i < P; i++){
		int p = pfact[i];
		vector<ll> sum(N / p);
		for(int j = 0; j < N; j++){
			sum[j % (N / p)] += (N / p) * a[j];
		}
		sums.push_back(sum);
		for(ll r : sum){
			best.insert(r);
		}
	}
	cout << (*best.rbegin()) << '\n';
	while(Q--){
		int idx;
		ll val;
		cin >> idx >> val;
		idx--;
		ll diff = val - a[idx];
		for(int i = 0; i < P; i++){
			int p = pfact[i];
			auto& r = sums[i][idx % (N / p)];
			best.erase(best.find(r));
			r += (N / p) * diff;
			best.insert(r);
		}
		a[idx] += diff;
		cout << (*best.rbegin()) << '\n';
	}
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	init();
	int T;
	cin >> T;
	while(T--) solve();
}