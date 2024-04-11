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
const int MAXN = (int)5e6 + 10;

int sieve[MAXN];
int tot[MAXN], acc[MAXN];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int64 i = 2; i < MAXN; ++i){
		if (!sieve[i]){
			sieve[i] = i;
			for (int64 j = i * i; j < MAXN; j += i){
				if (!sieve[j]) sieve[j] = i;
			}
		}
	}

	for (int i = 2; i < MAXN; ++i){
		tot[i] = tot[i / sieve[i]] + 1;
		acc[i] = tot[i] + acc[i - 1];
	}

	int q; cin >> q;
	while (q--){
		int u, v; cin >> u >> v;
		cout << acc[u] - acc[v] << endl;
	}

	return 0;
}