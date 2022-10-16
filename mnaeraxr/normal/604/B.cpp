#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100000;

int n, k;
int w[maxn];

int solve(int f){
	int ans = n;
	int pnt = n - 1;
	for (int i = 0; i < n; ++i){
		while (pnt > i && w[i] + w[pnt] > f) --pnt;
		if (pnt > i){
			--ans;
			--pnt;
		}
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; ++i)
		cin >> w[i];

	int lo = w[n - 1] - 1;
	int hi = lo + 1;
	while (solve(hi) > k) hi *= 2;
	while (lo + 1 < hi){
		int m = (lo + hi) / 2;
		if (solve(m) <= k) hi = m;
		else lo = m;
	}

	cout << hi << endl;

	return 0;
}