/*input
4

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
	int n; cin >> n;
	n++;
	if (n % 2 == 1) {
		if (n == 1) cout << 0 << endl;
		else if (n == 2) cout << 1 << endl;
		else cout << n << endl;
	}
	else cout << n / 2 << endl;
}