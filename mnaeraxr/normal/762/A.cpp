#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int64,int64> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100000 + 10;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int64 n, k;

	cin >> n >> k;

	vector<int64> D;

	for (int64 i = 1; i * i <= n; ++i){
		if (n % i == 0){
			D.push_back(i);
			D.push_back(n / i);
		}
	}

	sort(D.begin(), D.end());
	D.resize( unique(D.begin(), D.end()) - D.begin());

	if (k > (int)D.size()) cout << -1 << endl;
	else cout << D[k - 1] << endl;

	return 0;
}