#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 200000 + 10;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int64 n, m, k;
	cin >> n >> m >> k;

	int64 answer = 0;

	for (int64 v = 0; v * v <= n; ++v){

		int64 k1 = v;
		int64 k2 = k - k1;

		if (k2 >= 0 && k2 < m && k1 < n){
			int64 t = (n / (k1 + 1)) * (m / (k2 + 1));
			answer = max(answer, t);
		}

		if (v > 0){
			int64 k1 = min(n / v - 1, k);
			int64 k2 = k - k1;

			if (0 <= k1 && k1 < n && 0 <= k2 && k2 < m){
				int64 t = (n / (k1 + 1)) * (m / (k2 + 1));
				answer = max(answer, t);
			}
		}
	}

	if (answer == 0) answer = -1;

	cout << answer << endl;

	return 0;
}