#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define For(i, l, r) for (int i = (l); i <= (r); ++i)
#define Ford(i, r, l) for (int i = (r); i >= (l); --i) 
using namespace std;

typedef long long ll;
const int N = 105;

int n;
ll x, y;
string s;
 
int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> x >> y >> s; s = '#' + s;
	ll cnt = 0;
	For(i, 1, n) if (s[i] == '0') {
		cnt++;
		while (s[i] == '0' && i <= n) i++;
	}
	if (!cnt) cout << 0;
	else {
		ll res = y;
		if (x < y) res += (cnt - 1) * x;
		else res += (cnt - 1) * y;
		cout << res;
	}
}