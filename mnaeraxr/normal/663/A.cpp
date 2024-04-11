#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef vector<int> vi;
typedef pair<int,int> pii;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100010;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	vector<int> v(1, 1);
	int u = 1;
	int d = 0;

	while (true){
		string a, b;
		cin >> a >> b;
		if (b == "=") break;
		v.push_back(b == "+" ? 1 : -1);

		u += b == "+";
		d += b == "-";
	}

	int n; cin >> n;

	if (n * (u - 1) < d || u > n * (d + 1)){
		cout << "Impossible" << endl;
	}
	else{
		cout << "Possible" << endl;
		int total = n * u - d;
		for (int i = 0; i < (int)v.size(); ++i){
			if (v[i] == 1) v[i] = n;

			if (total > n){
				int r = min(n - 1, total - n);
				v[i] -= r;
				total -= r;
			}

			if (i == 0) cout << v[i];
			else{
				cout << " " << (v[i] > 0 ? '+' : '-') << " " << abs(v[i]);
			}
		}
		cout << " = " << n << endl;
	}

	return 0;
}