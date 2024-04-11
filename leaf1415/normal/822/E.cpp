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
#define rep(x, s, t) for(int (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define all(x) (x).begin(),(x).end()
#define inf 1e18

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;

typedef P Hash;

struct RollingHash{
	const static llint L = 2, mod = 1000000007;
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
		
		vec[0] = P(0, 0);
		beki[0] = P(1, 1);
		
		for(int i = 1; i <= n; i++){
			vec[i].first = vec[i-1].first * H[0] % mod + s[i-1], vec[i].first %= mod;
			vec[i].second = vec[i-1].second * H[1] % mod + s[i-1], vec[i].second %= mod;
			beki[i].first = beki[i-1].first * H[0] % mod, beki[i].first %= mod;
			beki[i].second = beki[i-1].second * H[1] % mod, beki[i].second %= mod;
		}
	}
	Hash getHash(int l, int r){
		l++, r++;
		Hash ret;
		ret.first = (vec[r].first + mod - vec[l-1].first*beki[r-l+1].first%mod) % mod;
		ret.second = (vec[r].second + mod - vec[l-1].second*beki[r-l+1].second%mod) % mod;
		return ret;
	}
};

int n, m, x;
string s, t;
RollingHash rh;
int dp[100005][35];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> s >> m >> t >> x;
	
	string S = "#"+s+t;
	rh.makeHash(S);
	
	rep(i, 0, n) rep(j, 0, x) dp[i][j] = -1e9;
	dp[0][0] = 0;
	
	rep(i, 0, n-1){
		rep(j, 0, x){
			if(dp[i][j] < 0) continue;
			
			chmax(dp[i+1][j], dp[i][j]);
			if(dp[i][j] >= m){
				cout << "YES" << endl;
				return 0;
			}
			
			int ub = min(n-i, m-dp[i][j])+1, lb = 0, mid;
			while(ub-lb>1){
				mid = (ub+lb)/2;
				if(rh.getHash(i+1, i+mid) == rh.getHash(n+dp[i][j]+1, n+dp[i][j]+mid)) lb = mid;
				else ub = mid;
			}
			chmax(dp[i+lb][j+1], dp[i][j]+lb);
		}
	}
	
	/*rep(i, 0, n){
		rep(j, 0, x){
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}*/
	
	rep(i, 0, n){
		rep(j, 0, x){
			if(dp[i][j] >= m){
				cout << "YES" << endl;
				return 0;
			}
		}
	}
	cout << "NO" << endl;
	
	return 0;
}