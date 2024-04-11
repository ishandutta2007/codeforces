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

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;

	vector<int> V(n);

	for (int i = 0; i < n; ++i)
		cin >> V[i];

	sort(V.begin(), V.end());

	int ans = 0;

	for (int i = 1; i < n; ++i){
		ans += max(0, V[i - 1] - V[i] + 1);
		V[i] = max(V[i], V[i - 1] + 1);
	}

	cout << ans << endl;

	return 0;
}