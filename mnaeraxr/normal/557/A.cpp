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
	int mn1, mx1, mn2, mx2, mn3, mx3;
	cin >> mn1 >> mx1 >> mn2 >> mx2 >> mn3 >> mx3;
	int gold = min(mx1, n - mn2 - mn3);
	int silver = min(mx2, n - gold - mn3);
	int bronze = n - gold - silver;

	cout << gold << " " << silver << " " << bronze << endl;

	return 0;
}