#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define first fi;
#define second se;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vi> vvi;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int n, a[100005], q, m;

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a+n);

	cin >> q;
	while (q--) {
		cin >> m;
		cout << upper_bound(a, a+n, m) - a << endl; 
	}

	return 0;
}