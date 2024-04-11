#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define SET(p,k) memset(p, k, sizeof(p));
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int n;
	ll a[100005], b[100005];

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int j = 0; j < n; j++)
		cin >> b[j];

	ll res = 0;
	for (int i = 0; i < n; i++) {
		ll aa = 0, ab = 0;
		for (int j = i; j < n; j++) {
			aa |= a[j];
			ab |= b[j];
		}
		res = max(res, aa + ab);
	}

	cout << res << endl;

	return 0;
}