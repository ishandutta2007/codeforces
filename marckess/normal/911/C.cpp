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
	
	int k[3];

	cin >> k[0] >> k[1] >> k[2];
	sort(k, k+3);

	if (k[0] == 1) {
		cout << "YES" << endl;
	} else if (k[0] == 2 && k[1] == 2) {
		cout << "YES" << endl;
	} else if (k[0] == 3 && k[2] == 3) {
		cout << "YES" << endl;
	} else if (k[0] == 2 && k[1] == 4 && k[2] == 4) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}

	return 0;
}