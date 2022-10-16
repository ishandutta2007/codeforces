#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define DB(x) cout<<#x<<"="<<x<<endl;
#define SZ(x) (int)((x).size())
#define MP make_pair

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double EPS = 1e-9;
const int MAXN = (int)1e5 + 10;

int small_ans[6] = {0, 1, 3, 5, 3, 3};
int sqr(int v){ return v * v; }

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int x; cin >> x;

	if (x < 6){
		cout << small_ans[x] << endl;
		exit(0);
	}

	int lo = 2, hi = 2;
	while ( (sqr(2 * hi + 1) + 1) / 2 < x) hi *= 2;

	while (lo + 1 < hi){
		int mid = (lo + hi) >> 1;
		if ( (sqr( 2 * mid + 1) + 1) / 2 < x) lo = mid;
		else hi = mid;
	}

	cout << 2 * hi + 1 << endl;

	return 0;
}