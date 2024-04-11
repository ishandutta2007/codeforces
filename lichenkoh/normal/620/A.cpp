#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
int main() {
	ios_base::sync_with_stdio(false);
	ll x1,y1,x2,y2;
	cin >> x1 >> y1 >> x2 >> y2;
	ll ans = max(abs(x1-x2),abs(y1-y2));
	cout << ans << endl;
	return 0;
}