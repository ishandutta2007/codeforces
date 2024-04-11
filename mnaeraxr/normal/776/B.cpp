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

	int n; cin >> n;

	if (n <= 2){
		cout << 1 << endl;
		for (int i = 0; i < n; ++i)
			cout << 1 << " ";
		cout << endl;
		return 0;
	}

	int m = n + 2;

	vector<bool> prime(m, true);

	for (int i = 2; i * i < m; ++i){
		if (!prime[i]) continue;

		for (int j = i * i; j < m; j += i)
			prime[j] = false;
	}

	cout << 2 << endl;

	for (int i = 2; i <= n + 1; ++i)
		cout << (prime[i] ? 1 : 2) << " ";
	cout << endl;


	return 0;
}