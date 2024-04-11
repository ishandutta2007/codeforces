#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100000 + 10;

const int MAX = 1024;

int grundy(int n, int64 mask){
	int64 seen = 0;

	for (int i = 1; i <= n; ++i){
		if (mask >> i & 1) continue;

		seen |= 1LL << grundy(n - i, mask | 1LL << i);
	}

	int g = 0;
	while (seen >> g & 1) g++;

	return g;
}

int _grundy(int n){
	int g = 0;
	for (int i = 1; i <= n; ++i){
		g++;
		n -= i;
	}
	return g;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;

	int x = 0;

	for (int i = 0; i < n; ++i){
		int v; cin >> v;

		x ^= _grundy(v);
	}

	cout << (x ? "NO" : "YES") << endl;

	return 0;
}