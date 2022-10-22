#include <cstdio>
#include <vector>
using namespace std;

const int Maxn = 105;
const int Maxk = 105;
const int Maxm = 215;

int n, k;
vector <int> q;
vector <int> s;
bool eq[Maxm];
bool dp[Maxk][Maxm];

vector <int> Perm(const vector <int> &cur, const vector <int> &q)
{
	vector <int> res(cur.size());
	for (int i = 0; i < res.size(); i++)
		res[i] = cur[q[i] - 1];
	return res;
}

vector <int> invPerm(const vector <int> &cur, const vector <int> &q)
{
	vector <int> res(cur.size());
	for (int i = 0; i < cur.size(); i++)
		res[q[i] - 1] = cur[i];
	return res;
}

int main()
{
	scanf("%d %d", &n, &k);
	q.resize(n); s.resize(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &q[i]);
	for (int i = 0; i < n; i++)
		scanf("%d", &s[i]);
	vector <int> cur(n);
	for (int i = 0; i < n; i++)
		cur[i] = i + 1;
	eq[Maxk] = cur == s;
	for (int i = 1; i <= k; i++) {
		cur = Perm(cur, q);
		eq[Maxk + i] = cur == s;
	}
	for (int i = 0; i < n; i++)
		cur[i] = i + 1;
	for (int i = 1; i <= k; i++) {
		cur = invPerm(cur, q);
		eq[Maxk - i] = cur == s;
	}
	dp[0][Maxk] = true;
	for (int i = 1; i <= k; i++)
		for (int j = Maxk - i; j <= Maxk + i; j += 2)
			dp[i][j] = dp[i - 1][j - 1] && !eq[j - 1] || dp[i - 1][j + 1] && !eq[j + 1];
	int j;
	for (j = Maxk - k; j <= Maxk + k; j += 2)
		if (dp[k][j] && eq[j]) break;
	printf("%s\n", j <= Maxk + k? "YES": "NO");
	return 0;
}