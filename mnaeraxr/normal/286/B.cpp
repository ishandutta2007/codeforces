#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define double long double

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 200000 + 10;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;

	vector<int> v(2 * n);

	for (int i = 0; i < n; ++i)
		v[i] = i + 1;

	for (int s = 2; s <= n; ++s){
		int b = s - 2;

		for (int i = 0, c = -1; ; i = min(i + s, n)){
			swap(v[i + b], c);
			if (i == n) break;
		}
	}

	for (int i = 0; i < n; ++i)
		cout << v[n - 1 + i] << " ";

	cout << endl;

	return 0;
}