#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 105;
const int mod = 1e9 + 7;

int n, k;
int a[N];
struct matrix {
	vector<vector<int> > M;
	int size() {
		return M.size();
	}
	
	matrix(int n = 0,int m = 0) {	
		M.assign(n,vector<int>(m,0));
	}
	vector<int>& operator [](int x) {
		return M[x];
	}
};

matrix operator * (matrix a,matrix b) {
	int m = a.size(), n = a[0].size(), p = b[0].size();
	matrix c(m, p);
	for (int i = 0;i < m;++i) 
		for (int j = 0;j < p;++j) 
			for (int k = 0;k < n;++k)
				c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % mod;
	
	return c;
}

matrix pow(matrix a,int k) {
	int n = a.size();
	matrix b(n,n);
	for (int i = 0;i < n;++i) b[i][i] = 1;
	while(k) {
		if (k & 1) b = b * a;
		a = a * a;
		k >>= 1;
	}
	return b;
}

signed main() {
	ios_base::sync_with_stdio(false);	cin.tie(0);
	cin >> n >> k;
	for (int i = 0;i < n;++i) cin >> a[i];
	matrix res(1,n);
	matrix mul(n,n);
	for (int i = 0;i < n;++i) res[0][i] = 1; 
	for (int i = 0;i < n;++i) 
		for (int j = 0;j < n;++j)	
			mul[i][j] += (__builtin_popcountll(a[i] ^ a[j]) % 3 == 0);
	res = res * pow(mul,k - 1);
	int ans = 0;
	for (int i = 0;i < n;++i) ans = (ans + res[0][i]) % mod;
	cout << ans << endl;
}