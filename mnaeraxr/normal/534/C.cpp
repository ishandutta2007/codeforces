#include <bits/stdc++.h>

using namespace std;

#define MP make_pair
#define SZ(x) ((int)x.size())
#define DB(x) cout << #x << "=" << x << endl
#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const double EPS = 1e-7;
const int MOD = (int)1e9 + 7;
const int MAXN = (int)1e5 + 10;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int64 n, A;
	cin >> n >> A;
	int64 s = 0;
	vector<int64> V(n);
	for (int i = 0; i < n; ++i) cin >> V[i], s += V[i];
	for (int i = 0; i < n; ++i){
		int64 mn = max(1LL, A - (s - V[i]));
		int64 mx = min(V[i], A - (n - 1));
		cout << V[i] - (mx - mn + 1) << " ";
	}
	cout << endl;

	return 0;
}