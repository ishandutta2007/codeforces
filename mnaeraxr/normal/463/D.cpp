#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

int P[6][1010];
int T[6][1010];
int V[1010], S[1010];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;	
	for (int i = 0; i < k; ++i){
		for (int j = 1; j <= n; ++j){
			cin >> P[i][j];
			T[i][P[i][j]] = j;
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; ++i){
		for (int j = 0; j < k; ++j){
			int cur = P[j][i];
			V[ cur ]++;
			if (V[ cur ] < k) continue;
			S[ cur ] = 1;

			for (int t = 1; t <= n; ++t){
				if (t == cur) continue;
				bool ok = V[t] == k;
				for (int p = 0; p < k && ok; ++p)
					if (T[p][t] > T[p][cur]) ok = false;
				if (ok) S[cur] = max(S[cur], S[t] + 1);
			}

			ans = max(ans, S[cur]);
		}
	}
	cout << ans << endl;

	return 0;
}