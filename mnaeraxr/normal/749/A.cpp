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

	cout << n / 2 << endl;

	for (int i = 1; i < n / 2; ++i)
		cout << 2 << " ";

	if (n & 1) cout << 3 << endl;
	else cout << 2 << endl;
	return 0;
}