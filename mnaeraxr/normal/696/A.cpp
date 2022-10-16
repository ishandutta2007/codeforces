#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

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

	int q; cin >> q;

	map<int64,int64> cost;

	while (q--){
		int64 t, a, b, c;
		cin >> t >> a >> b;

		if (t == 1){
			cin >> c;

			while (a != b){
				if (a < b) swap(a, b);
				cost[a] += c;
				a /= 2;
			}
		}
		else{
			int64 ans = 0;

			while (a != b){
				if (a < b) swap(a, b);
				ans += cost[a];
				a /= 2;
			}

			cout << ans << endl;
		}
	}

	return 0;
}