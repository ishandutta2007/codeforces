#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <string>
#include <algorithm>
#include <utility>
#include <complex>
#define rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define all(x) (x).begin(),(x).end()
#define inf 1e18

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;

typedef vector<llint> Hash;

struct RollingHash{
	const static llint L = 1, mod = 1000000007;
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
	void init(){
		vec.clear();
		beki.clear();
	}
	void makeHash(string &s){
		llint n = s.size();
		vec.resize(n+1), beki.resize(n+1);
		
		for(int i = 0; i <= n; i++) vec[i].resize(L), beki[i].resize(L);
		for(int i = 0; i < L; i++) vec[0][i] = 0;
		for(int i = 0; i < L; i++) beki[0][i] = 1;
		
		for(int i = 1; i <= n; i++){
			for(int j = 0; j < L; j++){
				vec[i][j] = vec[i-1][j] * H[j] % mod + s[i-1], vec[i][j] %= mod;
				beki[i][j] = beki[i-1][j] * H[j] % mod, beki[i][j] %= mod;
			}
		}
	}
	Hash getHash(int l, int r){
		l++, r++;
		Hash ret;
		for(int i = 0; i < L; i++){
			ret.push_back((vec[r][i] + mod - vec[l-1][i]*beki[r-l+1][i]%mod) % mod);
		}
		return ret;
	}
};

string s;
RollingHash rh;
bool pal[5005][5005];
int dp[5005][5005];
ll ans[5005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> s;
	ll n = s.size();
	s = "#" + s;
	rh.makeHash(s);
	
	rep(i, 1, n) pal[i][i] = true;
	rep(i, 1, n-1) pal[i][i+1] = (s[i] == s[i+1]);
	
	rep(len, 3, n){
		rep(l, 1, n){
			ll r = l+len-1;
			if(r > n) break;
			pal[l][r] = pal[l+1][r-1] && (s[l] == s[r]);
		}
	}
	
	/*rep(i, 1, n){
		rep(j, 1, n){
			cout << pal[i][j] << " ";
		}
		cout << endl;
	}*/
	
	rep(i, 1, n) dp[i][i] = 1;
	rep(len, 2, n){
		rep(l, 1, n){
			ll r = l+len-1;
			if(r > n) break;
			if(!pal[l][r]) continue;
			
			ll L = (l+r)/2, R = L+1;
			if(len % 2) L--;
			if(rh.getHash(l, L) != rh.getHash(R, r)){
				dp[l][r] = 1;
				continue;
			}
			dp[l][r] = dp[l][L]+1;
		}
	}
	
	rep(l, 1, n) rep(r, 1, n) ans[dp[l][r]]++;
	for(int i = n; i >= 1; i--) ans[i] += ans[i+1];
	rep(i, 1, n) cout << ans[i] << " "; cout << endl;
	
	return 0;
}