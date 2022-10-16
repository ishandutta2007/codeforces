#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100000 + 10;


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k;

	cin >> n >> k;

	if (2 * k >= n){
		cout << -1 << endl;
		return 0;
	}

	cout << n * k << endl;

	for (int i = 1; i <= n; ++i){
		for (int j = 1; j <= k; ++j){
			int u = (i + j) % n; if (u == 0) u = n;
			cout << i << " " << u << endl;
		}
	}

	return 0;
}