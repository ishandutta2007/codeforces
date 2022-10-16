/*input
2 4
*/
#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define endl '\n'
#define fi first
#define se second
#define mp make_pair
#define int long long
#define N
#define bit(x,y) ((x>>y)&1LL)
#define For(i,l,r) for(int i=l; i<r; i++)

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int x, y;
	cin >> x >> y;
	if (x == y) {
		cout << "=" << endl;
		return 0;
	}
	double lx = log10(x); double ly = log10(y);
	if (lx * y < ly * x) cout << "<" << endl;
	else if (lx * y > ly * x) cout << ">" << endl;
	else cout << "=" << endl;
}