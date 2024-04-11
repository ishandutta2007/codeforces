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
#define llint long long
#define inf 1e18
#define rep(x, s, t) for(llint (x) = (s); (x) < (t); (x)++)
#define Rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define mod 998244353

using namespace std;
typedef pair<llint, llint> P;

struct Matrix{
	int h, w;
	vector<llint> mat;
	Matrix(){
		h = w = 0;
	}
	Matrix(int h, int w){
		this->h = h, this->w = w;
		mat.resize(h*w);
	}
	llint& at(int i, int j){
		return mat[w*(i-1)+(j-1)];
	}
	static Matrix ident(int size){
		Matrix ret(size, size);
		for(int i = 1; i <= size; i++) ret.at(i, i) = 1;
		return ret;
	}
	Matrix operator*(Matrix& ope){
		Matrix ret(h, ope.w);
		for(int i = 1; i <= h; i++){
			for(int j = 1; j <= ope.w; j++){
				for(int k = 1; k <= w; k++){
					ret.at(i, j) += at(i, k) * ope.at(k, j) % mod;
					ret.at(i, j) %= mod;
				}
			}
		}
		return ret;
	}
	Matrix pow(llint n){
		if(n == 0) return ident(h);
		if(n % 2){
			return pow(n-1) * (*this);
		}
		else{
			Matrix tmp = pow(n/2);
			return tmp * tmp;
		}
	}
	void print(){
		for(int i = 1; i <= h; i++){
			for(int j = 1; j <= w; j++){
				cout << at(i, j) << " ";
			}
			cout << endl;
		}
	}
};

llint h, w, l, r;
Matrix mat(2, 2);

llint get(llint h, llint w){
	llint ret = h/2*w;
	h %= 2;
	if(h) ret += (w+1)/2;
	return ret;
}

llint modpow(llint a, llint n)
{
	if(n == 0) return 1;
	if(n % 2){
		return ((a%mod) * (modpow(a, n-1)%mod)) % mod;
	}
	else{
		return modpow((a*a)%mod, n/2) % mod;
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> h >> w >> l >> r;
	
	llint even = r/2 - (l-1)/2, odd = (r-l+1) - even;
	even %= mod, odd %= mod;
	//cout << even << " " << odd << endl;

	mat.at(1, 1) = mat.at(2, 2) = even;
	mat.at(1, 2) = mat.at(2, 1) = odd;
	
	llint x = get(h, w), y = h*w-x;
	Matrix pmat = mat.pow(x), pmat2 = mat.pow(y);
	
	llint ans = 0;
	if(x%2 != y%2) ans = modpow((r-l+1)%mod, h*w);
	else{
		ans += pmat.at(1, 1) * pmat2.at(1, 1) % mod;
		ans += pmat.at(2, 1) * pmat2.at(2, 1) % mod, ans %= mod;
	}
	cout << ans << endl;
	
	return 0;
}