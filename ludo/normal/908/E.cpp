#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) for (auto i = 0; i < (n); i++)
const ll maxm = 1001, mod = 1e9 + 7;
ll M, N, masks[maxm] = {};
int f[maxm] = {}, g[maxm] = {};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	f[0] = g[0] = 1;
	for (int i = 1; i < maxm; i++) {
		for (int j = i; j > 0; j--) g[j] = g[j-1];
		f[i] = g[0] = g[i];
		for (int j = 1; j <= i; ++j) (g[j] += g[j-1]) >= mod && (g[j] -= mod);
	}

	cin >> M >> N;
	string line;
	getline(cin, line);
	REP(i, N) {
		getline(cin, line);
		REP(j, M) if (line[j] == '1') masks[j] |= 1LL << i;
	}

	sort(masks, masks + M);
	ll ret = 1LL;

	for (int i = 0, j = 0; i < M; i = j) {
		while (j < M && masks[i] == masks[j]) j++;
		ret = (ret * f[j - i]) % mod;
	}
	cout << ret << endl;
	return 0;
}