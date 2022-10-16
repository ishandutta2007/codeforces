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

	int64 a = 0, b = -oo, c = -oo;

	for (int i = 0; i < n; ++i){
		int64 v; cin >> v;

		b = max(b, a + v);
		c = max(c, a - v);
		a = max(b - v, c + v);
	}

	cout << a << endl;

	return 0;
}