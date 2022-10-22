#include<bits/stdc++.h>
#define sz(a) int((a).size())
#define x first
#define y second
#define pi pair<int, int> 
#define vi vector<int>
#define i64 long long
#define u64 unsigned long long
using namespace std;
const int N = 1e5 + 10, V = 7000 + 1;
bitset<V> val[V], coef[V], s[N];

int mu[V], vis[V], p[V], tot = 0;

void sieve(int n) {
	vis[1] = mu[1] = 1;
	for(int i = 2; i <= n; i++) {
		if(!vis[i]) p[++tot] = i, mu[i] = -1;
		for(int j = 1; j <= tot && p[j] * i <= n; j++) {
			vis[i * p[j]] = 1;
			if(i % p[j] == 0) {
				mu[i * p[j]] = 0;
				break;
			}
			mu[i * p[j]] = - mu[i];
		}
	}
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	sieve(V - 1);
	for(int i = 1; i < V; i++) {
		for(int j = 1; j < V; j++) {
			if(i % j == 0) {
				val[i][j] = 1;
			}
			if(j % i == 0) {
				coef[i][j] = mu[j / i];
			}
		}
	}
	int n, q;
	cin >> n >> q;
	for(int i = 1; i <= q; i++) {
		int opt, x, y, z, v;
		cin >> opt;
		if(opt == 1) {
			cin >> x >> v;
			s[x] = val[v];
		} else if(opt == 2) {
			cin >> x >> y >> z;
			s[x] = s[y] ^ s[z];
		} else if(opt == 3) {
			cin >> x >> y >> z;
			s[x] = s[y] & s[z];
		} else {
			cin >> x >> v;
			cout << ((coef[v] & s[x]).count() & 1);
		}
	}
	cout << endl;
	return 0;
}