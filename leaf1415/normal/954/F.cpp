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
#define mod 1000000007

using namespace std;

typedef long long llint;
typedef long long ll;
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

ll n, m;
ll a[10005], l[10005], r[10005];
vector<P> evec, vec;
Matrix mat[8];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	rep(i, 1, n){
		cin >> a[i] >> l[i] >> r[i];
		evec.push_back(P(l[i], a[i]));
		evec.push_back(P(r[i]+1, -a[i]));
	}
	sort(all(evec));
	
	//for(auto p : evec) cout << p.first << " " << p.second << endl;
	
	ll b[3] = {};
	rep(i, 0, (int)evec.size()-1){
		ll x = evec[i].second, t = evec[i].first;
		if(x >= 0) b[x-1]++;
		else b[-x-1]--;
		
		if(i == (int)evec.size()-1 || t != evec[i+1].second){
			ll mask = 0;
			rep(j, 0, 2) if(b[j]) mask |= 1<<j;
			vec.push_back(P(t, mask));
		}
	}
	vec.push_back(P(m, 0));
	vec.push_back(P(m+1, 0));
	
	//for(auto p : vec) cout << p.first << " " << p.second << endl;
	
	rep(i, 0, 7){
		mat[i] = Matrix(3, 3);
		rep(j, 1, 3){
			if(i & (1<<(j-1))) continue;
			rep(k, 1, 3) mat[i].at(j, k) = 1;
		}
		mat[i].at(1, 3) = mat[i].at(3, 1) = 0;
	}
	
	Matrix mul = Matrix::ident(3); ll pre = 2, type = 0;
	for(auto p : vec){
		ll k = p.first - pre;
		Matrix cmat = mat[type].pow(k);
		mul = cmat * mul;
		pre = p.first, type = p.second;
	}
	cout << mul.at(2, 2) << endl;
	
	return 0;
}