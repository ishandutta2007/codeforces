#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int64 oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 200000 + 10;
const int sqrtmaxn = 1000;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;

	vector<int> positions(n + 1);
	vector<int> price(n + 1, oo);

	positions[0] = -2000;
	price[0] = 0;

	vector<int> delta = {1, 90, 1440};

	vector<int> money = {20, 50, 120};

	for (int i = 1; i <= n; ++i){
		int t; cin >> t;
		positions[i] = t;

		for (int j = 0; j < 3; ++j){
			int p = upper_bound(positions.begin(), positions.begin() + i, t - delta[j]) - positions.begin();
			int curprice = price[p - 1] + money[j];
			price[i] = min(curprice, price[i]);
		}

		cout << price[i] - price[i - 1] << endl;
	}


	return 0;
}