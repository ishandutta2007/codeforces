#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 4010;
const int maxs = 90;

int n;
int A[maxn];
int D[maxn][maxs][maxs];

int solve(int b, int k, int s){
	int &ans = D[b][k][s];

	if (ans != -1) return ans;

	ans = 0;

	int e = n - (b - 1 + k);
	int sz = e - b + 1;

	if (sz >= s){
		int val = A[b + s - 1] - A[b - 1];
		int v1 = 0, v2 = oo;
		int tsz = sz - s;

		if (tsz >= s)
			v1 = -(A[e] - A[e - s]) + solve(b + s, k, s);
		if (tsz > s)
			v2 = -(A[e] - A[e - s - 1]) + solve(b + s, k + 1, s + 1);

		ans = val + min(v1, v2);
	}

	if (sz > s){
		int val = A[b + s] - A[b - 1];
		int v1 = 0, v2 = oo;
		int tsz = sz - s - 1;

		if (tsz >= s + 1)
			v1 = -(A[e] - A[e - s - 1]) + solve(b + s + 1, k, s + 1);
		if (tsz > s + 1)
			v2 = -(A[e] - A[e - s - 2]) + solve(b + s + 1, k + 1, s + 2);

		ans = max(ans, val + min(v1, v2));
	}

	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

#ifdef MARX
    freopen("test.in", "r", stdin);
#endif

	cin >> n;

	for (int i = 1; i <= n; ++i){
		cin >> A[i];
		A[i] += A[i - 1];
	}

	memset(D, -1, sizeof D);

	cout << solve(1, 0, 1) << endl;

	return 0;
}