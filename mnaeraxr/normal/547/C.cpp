#include <bits/stdc++.h>

using namespace std;

#define MP make_pair
#define SZ(x) ((int)x.size())
#define DB(x) cout << #x << "=" << x << endl
#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const double EPS = 1e-7;
const int MOD = (int)1e9 + 7;
const int MAXN = (int)1e5 + 10;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, q;
	cin >> n >> q;
	vector<vector<int>> V(n);
	vector<bool> S(n);
	for (int i = 0; i < n; ++i){
		int v; cin >> v;
		for (int j = 2; j * j <= v; ++j){
			if (v % j == 0){
				V[i].push_back(j);
				while (v % j == 0)
					v /= j;
			}
		}
		if (v > 1) V[i].push_back(v);
	}

	vector<int> num(500100);

	int64 tot = 0;
	int64 f = 0;

	while (q--){
		int cur; cin >> cur;
		cur--;

		if (S[cur])	f--;

		int64 val = 0;
		for (int i = 1; i < (1 << V[cur].size()); ++i){
			int m = 0;
			int64 divisor = 1;
			for (int j = 0; j < V[cur].size(); ++j){
				if (i & (1 << j)){
					divisor *= V[cur][j];
					m ^= 1;
				}
			}

			if (S[cur]) num[divisor]--;

			//cout << "DIVISOR " << divisor << " " << num[divisor] << endl;
			if (m) val += num[divisor];
			else val -= num[divisor];

			if (!S[cur]) num[divisor]++;
		}

		val = f - val;
		//cout << f << " " << val << endl;

		if (S[cur]) tot -= val;
		else tot += val;

		if (!S[cur]) f++;

		cout << tot << endl;
		S[cur] = !S[cur];
	}


	return 0;
}