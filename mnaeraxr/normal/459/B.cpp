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
	int v1, t1, v2, t2;
	cin >> v1;
	v2 = v1;
	t1 = t2 = 1;

	for (int i = 1; i < n; ++i){
		int v; cin >> v;
		if (v < v1) v1 = v, t1 = 1;
		else if (v == v1) t1++;
		if (v > v2) v2 = v, t2 = 1;
		else if (v == v2) t2++;
	}

	if (v1 == v2){
		cout << 0 << " " << 1LL * t1 * (t1 - 1) / 2 << endl;
	}
	else{
		cout << v2 - v1 << " " << 1LL * t1 * t2 << endl;
	}

//	int x1, y1, x2, y2;
//	cin >> x1 >> y1 >> x2 >> y2;
//
//	if (x1 == x2){
//		int d = y1 - y2;
//		cout << x1 + d << " " << y1 << " " << x2 + d << " " << y2 << endl;
//	}
//	else if (y1 == y2){
//		int d = x1 - x2;
//		cout << x1 << " " << y1 + d << " " << x2 << " " << y2 + d << endl;
//	}
//	else{
//		int dx = abs(x1 - x2);
//		int dy = abs(y1 - y2);
//		if (dx != dy) cout << -1 << endl;
//		else cout << x1 << " " << y2 << " " << x2 << " " << y1 << endl;
//	}

	return 0;
}