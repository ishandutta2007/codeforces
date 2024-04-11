#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define DB(x) cout << #x << " = " << x << endl << flush;
#define SZ(x) (int)((x).size())
#define MP make_pair

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double EPS = 1e-9;
const int MAXN = (int)3e5 + 10;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int p, q, l, r;
	cin >> p >> q >> l >> r;

	vector<bool> m1(1001), m2(1001);
	for (int i = 0; i < p; ++i){
		int a, b; cin >> a >> b;
		for (int j = a; j <= b; ++j)
			m1[j] = true;
	}

	for (int i = 0; i < q; ++i){
		int a, b; cin >> a >> b;
		for (int j = a; j <= b; ++j)
			m2[j] = true;
	}

	int ans = 0;
	for (int i = l; i <= r; ++i){
		bool ok = false;
		for (int j = i; j <= 1000 && !ok; ++j){
			if (m1[j] && m2[j - i]) ok = true;
		}
		if (ok) ++ans;
	}

	cout << ans << endl;

	return 0;
}