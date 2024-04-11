#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100000 + 10;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int64 n; cin >> n;

	vector<int64> fib(2, 1);
	int t = 2;

	while (fib.back() <= n){
		fib.push_back(fib[t - 1] + fib[t - 2]);
		t++;
	}

	cout << fib.size() - 3 << endl;

	return 0;
}