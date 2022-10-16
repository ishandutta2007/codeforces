#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define DB(x) cout << #x << " = " << x << endl << flush;
#define SZ(x) (int)((x).size())
#define MP make_pair

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double EPS = 1e-9;
const int MAXN = (int)1e5 + 10;

int freq[210];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	vector<pii> V(n);
	vector<int> A(n + 1, 0);
	for (int i = 0; i < n; ++i){
		cin >> V[i].first;
	}
	for (int i = 0; i < n; ++i){
		cin >> V[i].second;
	}
	sort(V.begin(), V.end());

	for (int i = n - 1; i >= 0; --i){
		A[i] = A[i + 1] + V[i].second;
	}

	int ans = oo;

	for (int i = 0, j = 0; i < n; i = j){
		for( ;j < n && V[j].first == V[i].first; ++j);

		int cur_cost = A[j];
		int final = 2 * (j - i) - 1;
		int cur_legs = j;
		for (int k = 1; k <= 200 && cur_legs > final; ++k){
			if (cur_legs - freq[k] >= final){
				cur_legs -= freq[k];
				cur_cost += k * freq[k];
			}
			else{
				int to_remove = cur_legs - final;
				cur_legs -= to_remove;
				cur_cost += k * to_remove;
			}
		}

		ans = min(ans, cur_cost);
		for (int k = i; k < j; ++k)
			freq[V[k].second]++;
	}

	cout << ans << endl;

	return 0;
}