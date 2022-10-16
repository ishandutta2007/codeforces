#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100000 + 10;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string a, b;
	cin >> a >> b;

	cout << a << " " << b << endl;

	int q; cin >> q;

	while (q--){
		string u, v; cin >> u >> v;

		if (u != a) swap(a, b);
		a = v;

		cout << a << " " << b << endl;
	}

	return 0;
}