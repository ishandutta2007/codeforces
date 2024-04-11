#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define fill_to_n(a,n,k) iota(a,a+n,k)
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	bitset<1000005> bs;
	int n;

	cin >> n;

	bs.set();
	bs[0] = bs[1] = 0;
	for (ll i = 2; i <= 1e6; i++)
		if (bs[i])
			for (ll j = i*i; j <= 1e6; j += i)
				bs[j] = 0;

	for (int i = 4; i <= n; i++) {
		if (!bs[i] && !bs[n-i]) {
			cout << i << " " << n - i << endl;
			return 0;
		}
	}

	return 0;
}