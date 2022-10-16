#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = (int)1e5 + 10;
const int maxl = 20;

int rmql[maxl][maxn];
int rmqu[maxl][maxn];

int getl(int a, int b){
	int l = __lg(b - a + 1);
	return min(rmql[l][a], rmql[l][b - (1 << l) + 1]);
}

int getu(int a, int b){
	int l = __lg(b - a + 1);
	return max(rmqu[l][a], rmqu[l][b - (1 << l) + 1]);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	for (int i = 0; i < n; ++i){
		cin >> rmql[0][i];
		rmqu[0][i] = rmql[0][i];
	}

	for (int i = 1; (1 << i) <= n; ++i)
		for (int j = 0; j + (1 << (i - 1)) < n; ++j){
			rmql[i][j] = min(rmql[i - 1][j], rmql[i - 1][j + (1 << (i - 1))]);
			rmqu[i][j] = max(rmqu[i - 1][j], rmqu[i - 1][j + (1 << (i - 1))]);
		}

	int ans = 0;
	for (int i = 0; i < n; ++i){
		int l = i, h = n;
		while (l + 1 < h){
			int m = (l + h) / 2;
			if (getu(i, m) - getl(i, m) <= 1)
				l = m;
			else
				h = m;
		}
		ans = max(ans, l - i + 1);
	}

	cout << ans << endl;

	return 0;
}