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
	const static llint L = 6;// mod = 1000000007;
	llint H[L], mod[L];
	vector<Hash> vec, beki;

	llint getrand(){
		llint ret = rand();
		ret = ret * RAND_MAX + rand();
		ret = ret * RAND_MAX + rand();
		return ret;
	}
	RollingHash(){
		srand(time(NULL));
		for(int i = 0; i < L; i++) H[i] = 10, mod[i] = getrand() % 900000000 + 100000000;
		init();
	}
	init(){
		vec.clear();
		beki.clear();
	}
	void makeHash(vector<llint> &s){
		llint n = s.size();
		vec.resize(n+1), beki.resize(n+1);
		
		for(int i = 0; i <= n; i++) vec[i].resize(L), beki[i].resize(L);
		for(int i = 0; i < L; i++) vec[0][i] = 0;
		for(int i = 0; i < L; i++) beki[0][i] = 1;
		
		for(int i = 1; i <= n; i++){
			for(int j = 0; j < L; j++){
				vec[i][j] = vec[i-1][j] * H[j] % mod[j] + s[i-1], vec[i][j] %= mod[j];
				beki[i][j] = beki[i-1][j] * H[j] % mod[j], beki[i][j] %= mod[j];
			}
		}
	}
	Hash getHash(int l, int r){
		l++, r++;
		Hash ret;
		for(int i = 0; i < L; i++){
			ret.push_back((vec[r][i] + mod[i] - vec[l-1][i]*beki[r-l+1][i]%mod[i]) % mod[i]);
		}
		return ret;
	}
};

ll n;
string s;
vector<ll> vec;
RollingHash rh;

bool check(ll i, ll j, ll k)
{
	if(i >= j || j >= k) return false;
	if(j-i >= 2 && s[i] == '0') return false;
	if(k-j >= 2 && s[j] == '0') return false;
	if(n-k >= 2 && s[k] == '0') return false;
	
	//cout << i << " " << j << " " << k << endl;
	
	Hash res = rh.getHash(i, j-1), res2 = rh.getHash(j, k-1), res3 = rh.getHash(k, n-1);
	rep(i, 0, RollingHash::L-1){
		//cout << res[i] << " " << res2[i] << " " << res3[i] << endl;
		if((res[i] + res2[i]) % rh.mod[i] != res3[i]) return false;
	}
	
	vector<ll> tmp, tmp2, tmp3;
	rep(p, i, j-1) tmp.push_back(vec[p]);
	rep(p, j, k-1) tmp2.push_back(vec[p]);
	rep(p, k, n-1) tmp3.push_back(vec[p]);
	reverse(all(tmp)), reverse(all(tmp2)), reverse(all(tmp3));
	
	
	while(tmp2.size() < tmp.size()) tmp2.push_back(0);
	while(tmp.size() < tmp2.size()) tmp.push_back(0);
	tmp.push_back(0), tmp2.push_back(0);
	
	rep(i, 0, (int)tmp.size()-1){
		ll c = tmp[i] + tmp2[i];
		tmp[i+1] += c / 10, tmp[i] = c % 10;
	}
	//for(auto x : tmp) cout << x; cout << endl;
	//for(auto x : tmp3) cout << x; cout << endl;
	
	while(tmp.size() >= 2 && tmp.back() == 0) tmp.pop_back();
	return tmp == tmp3;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> s;
	n = s.size();
	for(auto &c : s) vec.push_back(c-'0');
	rh.makeHash(vec);
	
	for(int i = min(n-1, n/3*2+5); i >= 0; i--){
		ll len = n-i;
		if(check(0, i-len, i)){
			cout << s.substr(0, i-len) << "+" << s.substr(i-len, len) << "=" << s.substr(i) << endl;
			return 0;
		}
		if(check(0, i-len+1, i)){
			cout << s.substr(0, i-len+1) << "+" << s.substr(i-len+1, len-1) << "=" << s.substr(i) << endl;
			return 0;
		}
		
		if(check(0, len, i)){
			cout << s.substr(0, len) << "+" << s.substr(len, i-len) << "=" << s.substr(i) << endl;
			return 0;
		}
		if(check(0, len-1, i)){
			cout << s.substr(0, len-1) << "+" << s.substr(len-1, i-(len-1)) << "=" << s.substr(i) << endl;
			return 0;
		}
	}
	
	return -1;
}