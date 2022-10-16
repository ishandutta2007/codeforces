#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 101;
const int maxm = 1001;

double prefix[maxn * maxm];
double E[maxn][maxn * maxm];
int pos[maxn];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	if (m == 1){
		cout << "1.0000000" << endl;
		exit(0);
	}

	int s = 0;
	for (int i = 1; i <= n; ++i){
		cin >> pos[i];
		s += pos[i];
	}

	E[0][0] = m - 1;
	for (int i = 1; i <= n; ++i){

		prefix[0] = 0;
		for (int j = 1; j <= n * m; ++j)
			prefix[j] = prefix[j - 1] + E[i - 1][j - 1] / (m - 1);

		for (int j = 1; j <= n * m; ++j){
			int l = max(j - m, 0);
			int v = j - pos[i];
			E[i][j] = prefix[j] - prefix[l];
			if (v >= 0) E[i][j] -= E[i - 1][v] / (m - 1);
		}
	}


	double ans = 1.0;
	for (int i = 0; i < s; ++i)
		ans += E[n][i];

	cout.precision(10);
	cout << fixed << ans << endl;

	return 0;
}