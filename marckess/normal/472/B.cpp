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
	
	int n, k, f[2005], res = 0;

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> f[i];
		f[i]--;
	}
	sort(f, f+n, greater<int>());

	for (int i = 0; i < n; i += k)
		res += f[i] * 2;

	cout << res << endl;

	return 0;
}