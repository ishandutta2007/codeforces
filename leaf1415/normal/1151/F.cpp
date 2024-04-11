#include <iostream>
#include <vector>
#define llint long long
#define mod 1000000007

using namespace std;

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

llint n, k;
llint a[105];

int main(void)
{
	cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	int cnt = 0, cor = 0;
	for(int i = 1; i <= n; i++) if(a[i]) cnt++;
	for(int i = n-cnt+1; i <= n; i++) if(a[i]) cor++;
	
	Matrix mat(cnt+1, cnt+1);
	llint bunbo = modpow(n*(n-1)/2, mod-2);
	for(int i = 0; i <= cnt; i++){
		for(int j = 0; j <= cnt; j++){
			mat.at(i+1, j+1) = 0;
		}
	}
	for(int i = 0; i <= cnt; i++){
		llint a = (cnt-i)*(cnt-i)%mod, b = i*(n+i-2*cnt)%mod;
		if(i-1 >= 0) mat.at(i, i+1) = b * bunbo % mod;
		if(i+1 <= cnt) mat.at(i+2, i+1) = a * bunbo % mod;
		mat.at(i+1, i+1) = (n*(n-1)/2 - (a+b) + 2*mod) % mod * bunbo % mod;
	}
	
	/*for(int i = 0; i <= cnt; i++){
		for(int j = 0; j <= cnt; j++){
			cout << mat.at(i+1, j+1) << " ";
		}
		cout << endl;
	}
	
	Matrix m = mat.pow(k);
	for(int i = 0; i <= cnt; i++){
		for(int j = 0; j <= cnt; j++){
			cout << m.at(i+1, j+1) << " ";
		}
		cout << endl;
	}*/
	
	cout << mat.pow(k).at(cnt+1, cor+1) << endl;
	return 0;
}