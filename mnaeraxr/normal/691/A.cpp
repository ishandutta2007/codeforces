#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100010;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	int s = 0;

	for (int i = 0; i < n; ++i){
		int v; cin >> v;
		s += v;
	}

	if (s == max(n - 1, 1)) cout << "YES" << endl;
	else cout << "NO" << endl;

	return 0;
}