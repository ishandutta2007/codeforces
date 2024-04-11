#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <map>
#include <set>
#include <ctime>
#include <cstdlib>
#define llint long long

using namespace std;

typedef vector<llint> Hash;

struct RollingHash{
	const static llint L = 8, mod = 1000000007;
	llint H[L];
	vector<Hash> vec, beki;

	llint getrand(){
		llint ret = rand();
		ret = ret * RAND_MAX + rand();
		ret = ret * RAND_MAX + rand();
		return ret;
	}
	RollingHash(){
		srand(time(NULL));
		for(int i = 0; i < L; i++) H[i] = getrand() % 900000000 + 100000000;
		init();
	}
	init(){
		vec.clear();
		beki.clear();
	}
	void makeHash(llint n){
		beki.resize(n+1);
		for(int i = 0; i <= n; i++) beki[i].resize(L);
		for(int i = 0; i < L; i++) beki[0][i] = 1;
		for(int i = 1; i <= n; i++){
			for(int j = 0; j < L; j++){
				beki[i][j] = beki[i-1][j] * H[j] % mod, beki[i][j] %= mod;
			}
		}
	}
	Hash getHash(set<int> &S){
		Hash ret;
		for(int i = 0; i < L; i++){
			llint sum = 0;
			for(auto it = S.begin(); it != S.end(); it++) sum += beki[*it][i], sum %= mod;
			ret.push_back(sum);
		}
		return ret;
	}
};

int T, n, m;
llint c[500005];
set<int> S[500005];
RollingHash rh;
map<Hash, llint> mp;

llint gcd(llint a, llint b)
{
	if(b == 0) return a;
	return gcd(b, a%b);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	rh.makeHash(500005);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n >> m;
		for(int i = 1; i <= n; i++) cin >> c[i];
		
		for(int i = 1; i <= n; i++) S[i].clear();
		llint u, v;
		for(int i = 1; i <= m; i++){
			cin >> u >> v;
			S[v].insert(u);
		}
		
		mp.clear();
		for(int i = 1; i <= n; i++){
			if(S[i].size() == 0) continue;
			mp[rh.getHash(S[i])] += c[i];
		}
		llint ans = 0;
		for(auto it = mp.begin(); it != mp.end(); it++) ans = gcd(ans, it->second);
		cout << ans << "\n";
	}
	flush(cout);
	
	return 0;
}