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
#define reps(x, s) for(llint (x) = 0; (x) < (llint)(s).size()-1; (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define all(x) (x).begin(),(x).end()
#define inf 1e18
#define mod 1000000007

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;
typedef pair<pair<int, int>, int> T;

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

ll n, k;
ll b[105], c[105];
Matrix mat(20, 20);

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	rep(i, 1, n) cin >> b[i] >> b[i] >> c[i], c[i]++;
	chmin(b[n], k);
	
	Matrix mul = Matrix::ident(20);
	rep(i, 1, n){
		rep(j, 1, 20){
			rep(k, 1, 20){
				if(j > c[i] || k > c[i]) mat.at(k, j) = 0;
				else if(abs(j-k) > 1) mat.at(k, j) = 0;
				else mat.at(k, j) = 1;
			}
		}
		Matrix pmat = mat.pow(b[i]-b[i-1]);
		mul = pmat * mul;
	}
	cout << mul.at(1, 1) << endl;
	
	
	return 0;
}