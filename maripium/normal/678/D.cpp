#include<bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 1e9 + 7;
typedef vector<int> row;
typedef vector<row> matrix;

matrix operator * (matrix a,matrix b) {
	matrix c;
	int m = a.size(), n = a[0].size(), p = b[0].size();
	c.assign(m,row(p,0));
	for(int i = 0;i < m;++i) 
		for(int j = 0;j < p;++j) 
			for(int k = 0;k < n;++k) 
				c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % mod;
	return c;
}

matrix binpow(matrix a,int n) {
	matrix b;
	b.assign(a.size(),row(a.size(),0));
	for(int i = 0;i < b.size();++i) b[i][i] = 1;
	while(n) {
		if(n & 1) b = b * a;
		a = a * a;
		n >>= 1;
	}
	return b;
}

signed main() {
	int a,b,n,x;
	cin >> a >> b >> n >> x;
	matrix ans;
	ans.assign(2,row(2,0));
	ans[0][0] = (a + 1) % mod;
	ans[0][1] = (-a % mod + mod) % mod;
	ans[1][0] = 1;
	ans = binpow(ans,n - 1);
	matrix f(2,row(1,0));
	f[0][0] = (a * x  + b) % mod;
	f[1][0] = x % mod;
	ans = ans * f;
	cout << ans[0][0] << endl;
}