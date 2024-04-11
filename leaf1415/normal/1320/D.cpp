#include <iostream>
#include <utility>
#include <vector>
#include <map>
#include <ctime>
#include <queue>
#include <algorithm>
#define llint long long
#define inf 1e18

using namespace std;

typedef vector<llint> Hash;

struct RollingHash{
	const static llint L = 6, mod = 1000000007;
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
	void makeHash(vector<llint> &s){
		llint n = s.size();
		vec.resize(n+1), beki.resize(n+1);
		
		for(int i = 0; i <= n; i++) vec[i].resize(L), beki[i].resize(L);
		for(int i = 0; i < L; i++) vec[0][i] = 0;
		for(int i = 0; i < L; i++) beki[0][i] = 1;
		
		for(int i = 1; i <= n; i++){
			for(int j = 0; j < L; j++){
				vec[i][j] = vec[i-1][j] * H[j] % mod + s[i-1], vec[i][j] %= mod;
				beki[i][j] = beki[i-1][j] * H[j] % mod, beki[i][j] %= mod;;
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

llint n, Q;
string s;
vector<llint> vec, svec[2];
RollingHash rh[2];

void get(llint l, llint r, llint &L, llint &R)
{
	L = lower_bound(vec.begin(), vec.end(), l) - vec.begin();
	R = upper_bound(vec.begin(), vec.end(), r) - vec.begin() - 1;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	cin >> s;
	s = "#" + s;
	
	for(int i = 1; i <= n; i++){
		if(s[i] == '0'){
			vec.push_back(i);
			svec[0].push_back(i%2);
			svec[1].push_back((i+1)%2);
		}
	}
	rh[0].makeHash(svec[0]);
	rh[1].makeHash(svec[1]);
	
	/*for(int i = 0; i < vec.size(); i++) cout << vec[i] << " ";  cout << endl;
	for(int i = 0; i < svec[0].size(); i++) cout << svec[0][i] << " ";  cout << endl;
	for(int i = 0; i < svec[1].size(); i++) cout << svec[1][i] << " ";  cout << endl;*/
	
	llint l, l2, r, r2, len;
	llint L, R, L2, R2;
	cin >> Q;
	for(int q = 1; q <= Q; q++){
		cin >> l >> l2 >> len;
		r = l + len - 1, r2 = l2 + len - 1;
		
		get(l, r, L, R);
		get(l2, r2, L2, R2);
		
		//cout << L << " " << R << " " << L2 << " " << R2 << endl;
		//cout << p << " " << p2 << endl;
		
		if(R-L+1 != R2-L2+1){
			cout << "No" << "\n";
			continue;
		}
		if(R-L+1 == 0){
			cout << "Yes" << endl;
			continue;
		}
		
		//cout << rh[p].getHash(L, R).first << " " << rh[p2].getHash(L2, R2).first << endl;
		if(rh[l%2].getHash(L, R) == rh[l2%2].getHash(L2, R2)) cout << "Yes" << "\n";
		else cout << "No" << "\n";
	}
	flush(cout);
	
	return 0;
}