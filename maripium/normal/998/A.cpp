#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define For(i, l, r) for (int i = (l); i <= (r); ++i)
#define Ford(i, r, l) for (int i = (r); i >= (l); --i) 
using namespace std;
 
int main() {
	ios_base::sync_with_stdio(false);
	int n; cin >> n;
	pair<int,int> a[n + 5];
	For(i, 1, n) {
		cin >> a[i].fi;
		a[i].se = i;
	}
	sort(a + 1, a + 1 + n);
	if (n == 1 || (n == 2 && a[1].fi == a[2].fi)) return cout << -1 << '\n',0;
	cout << 1 << '\n' << a[1].se;
}