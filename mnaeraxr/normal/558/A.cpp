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

	vector<pii> A, B;
	int n; cin >> n;
	for (int i = 0; i < n; ++i){
		int v, t;
		cin >> v >> t;
		if (v < 0) A.push_back({-v, t});
		else B.push_back({v, t});
	}

	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	int ans = 0;
	for (int i = 0; i < min(A.size(), B.size()); ++i){
		ans += A[i].second + B[i].second;
	}

	if (A.size() > B.size()) ans += A[B.size()].second;
	else if (B.size() > A.size()) ans += B[A.size()].second;

	cout << ans << endl;

	return 0;
}