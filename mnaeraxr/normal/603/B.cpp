#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef vector<int> vi;
typedef pair<int,int> pii;

const double EPS = 1e-9;
const int oo = 0x3f3f3f3;
const int MAXN = (int)1e5 + 10;
int64 mod = 1000000007;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int64 p, k;
	cin >> p >> k;

	vector<bool> mk(p);
	int64 ans = 1;

	int64 tot = 1;

	for (int64 i = 1; i < p; ++i) if (!mk[i]){
		if (k * i % p == i) ++tot;
		ans = ans * p % mod;
		int64 t = i;
		while (t && !mk[t]){
			mk[t] = true;
			t = t * k % p;
		}
	}

	ans = ans * tot % mod;

	cout << ans << endl;

	return 0;
}