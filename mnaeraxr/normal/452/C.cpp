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

	double n, m;
	cin >> n >> m;
	if (n == 1){
		cout << 1 << endl;
	}
	else{
		double ans = 1 / n + (n - 1) / n * (m - 1) / (n * m - 1);
		cout.precision(10);
		cout << fixed << ans << endl;
	}
	return 0;
}