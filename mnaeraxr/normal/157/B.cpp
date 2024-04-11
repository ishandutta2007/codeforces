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
const int MAXN = (int)1e5 + 10;
const double PPI = 3.141592653589793;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t; cin >> t;
	vector<int> C(t);
	for (int i = 0; i < t; ++i)
		cin >> C[i];
	int ans = 0;
	sort(C.begin(), C.end());
	for (int i = t - 1, sg = 1; i >= 0; --i, sg *= -1){
		ans += sg * C[i] * C[i];
	}

	double ans1 = 1.0 * PPI * ans;
	cout.precision(10);
	cout << fixed << ans1 << endl;

	return 0;
}