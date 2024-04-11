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
	vector<int> Q(n);
	for (int i = 0; i < n; ++i) cin >> Q[i];
	sort(Q.begin(), Q.end());

	int64 sum = 0;
	int ans = 0;

	for (int i = 0; i < n; ++i){
		if (sum <= Q[i]){
			sum += Q[i];
			++ans;
		}
	}
	cout << ans << endl;

	return 0;
}