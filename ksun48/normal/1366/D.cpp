#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int X = 2e7;

bitset<X> is_prime;
vector<int> pf;
vector<int> pr;

void init(){
	pf.resize(X, 0);
	is_prime.flip();
	is_prime[0] = is_prime[1] = false;
	for(int i = 2; i < X; i++){
		if(is_prime[i]){
			pr.push_back(i);
			pf[i] = i;
		}
		for(int p : pr){
			if(ll(i) * p >= X) break;
			pf[i * p] = p;
			is_prime[i * p] = false;
			if(i % p == 0) break;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	init();
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> b(n, -1), c(n, -1);
	for(int i = 0; i < n; i++){
		int r;
		cin >> r;
		int p = pf[r];
		assert(r % p == 0);
		int g = r;
		int h = 1;
		while(g % p == 0){
			g /= p;
			h *= p;
		}
		if(g != 1){
			b[i] = g;
			c[i] = h;
		}
	}
	for(int i = 0; i < n; i++) cout << b[i] << ' ';
	cout << '\n';
	for(int i = 0; i < n; i++) cout << c[i] << ' ';
	cout << '\n';
}