#include <bits/stdc++.h>
using namespace std;

const int N = 2005;
const int mod = 1e9 + 7;

vector<int> operator * (vector<int> a, vector<int> b) {
	int n = a.size();
	vector<int> res(n);
	for (int i = 0;i < n;++i) {
		for (int j = 0;j < n;++j) {
			if(i + j < n) res[i + j] = (res[i + j] + 1LL * a[i] * b[j] % mod) % mod; 
		}
	}
	return res;
}

vector<int> pow(vector<int> a,int k) {
	int n = a.size();
	vector<int> res(n, 0);
	res[0] = 1;
	while(k) {
		if (k & 1) res = res * a;
		a = a * a;
		k >>= 1;
	}

	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	int n, k; cin >> n >> k;
	vector<int> a(n);
	for (int i = 0;i < n;++i) cin >> a[i];
	vector<int> mul(n, 1);
	a = a * pow(mul, k);
	for (int i = 0;i < n;++i) cout << a[i] << ' ';
}