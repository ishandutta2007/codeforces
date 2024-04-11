#include <bits/stdc++.h>
using namespace std;

using hash_t = uint64_t;

vector<int> get_primes(int N)
{
	if (N == 1) return {};
	vector<bool> chk(N/2+2);
	vector<int> ret = {2};
	for (int i=3;i<=N;i+=2) if (!chk[i/2]){
		ret.push_back(i);
		if (i > N/i) continue;
		for (int j=i*i;j<=N;j+=i+i){
			chk[j/2] = 1;
		}
	}
	return ret;
}

void print(int N, vector<int> except = {})
{
	vector<bool> vis(N+1);
	for (int v: except) vis[v] = 1;
	vector<int> outp;
	for (int i=1;i<=N;i++) if (!vis[i]) outp.push_back(i);
	cout << outp.size() << '\n';
	for (int v: outp) cout << v << ' ';
	cout << '\n';
}

void solve()
{
	int N;
	cin >> N;

	random_device dv;
	mt19937 rng(dv());
	uniform_int_distribution<hash_t> dist(static_cast<hash_t>(1), numeric_limits<hash_t>::max());

	auto primes = get_primes(N);
	vector<hash_t> hash(N+1), fhash(N+1);
	for (int p: primes){
		hash[p] = dist(rng);
	}
	for (int i=2;i<=N;i++){
		if (!hash[i]){
			int n = i;
			for (int p: primes){
				if (p > n/p) break;
				while (n%p == 0) hash[i] ^= hash[p], n /= p;
			}
			if (n > 1) hash[i] ^= hash[n];
		}
		fhash[i] = fhash[i-1]^hash[i];
	}

	hash_t all = 0;
	for (int i=1;i<=N;i++) all ^= fhash[i];

	if (all == 0){ print(N); return; }

	map<hash_t, int> fhash_map;
	for (int i=1;i<=N;i++) fhash_map[fhash[i]] = i;

	auto it = fhash_map.find(all);
	if (it != fhash_map.end()){ print(N, {it->second}); return; }

	for (int i=1;i<=N;i++){
		auto it = fhash_map.find(all^fhash[i]);
		if (it != fhash_map.end()){ print(N, {i, it->second}); return; }
	}

	print(N, {2, (N-1)/2, N});
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	solve();
}