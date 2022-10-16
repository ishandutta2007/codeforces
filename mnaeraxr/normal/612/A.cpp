#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100010;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, p, q;
	cin >> n >> p >> q;
	string s; cin >> s;

	for (int i = 0; p * i <= n; ++i){
		if ((n - p * i) % q == 0){
			cout << i + (n - p * i) / q << endl;
			for (int j = 0; j < i; ++j){
				for (int t = 0; t < p; ++t)
					cout << s[t + j * p];
				cout << endl;
			}
			for (int j = 0; j < (n - p * i) / q; ++j){
				for (int t = 0; t < q; ++t)
					cout << s[i * p + t + j * q];
				cout << endl;
			}
			exit(0);
		}
	}

	cout << -1 << endl;

	return 0;
}