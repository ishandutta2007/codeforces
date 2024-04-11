#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define DB(x) cout<<#x<<"="<<x<<endl;
#define SZ(x) (int)((x).size())
#define MP make_pair

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double EPS = 1e-9;
const int MAXN = (int)1e5 + 10;

double val[110][110][110][3];
bool memo[110][110][110];

void solve(int r, int s, int p)
{
	if (memo[r][s][p]) return;
	memo[r][s][p] = true;

	vector<int> c = {r, s, p, r};
	if (r + s + p - max(r, max(s, p)) - min(r, min(s, p)) == 0){
		if (r) val[r][s][p][0] = 1;
		else if (s) val[r][s][p][1] = 1;
		else val[r][s][p][2] = 1;
		return;
	}

	int64 tot = r + s + p;
	tot = 1LL * tot * (tot - 1) / 2;
	for (int i = 0; i < 3; ++i){
		if (c[i + 1] == 0) continue;
		int r1 = r - (i == 2);
		int s1 = s - (i == 0);
		int p1 = p - (i == 1);
		solve(r1, s1, p1);

		for (int j = 0; j < 3; ++j)
			val[r][s][p][j] += 1.0 * c[i] * c[i + 1] / tot * val[r1][s1][p1][j];
	}

	double norm = val[r][s][p][0] + val[r][s][p][1] + val[r][s][p][2];
	for (int i = 0; i < 3; ++i)
		val[r][s][p][i] /= norm;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int r, s, p;
	cin >> r >> s >> p;

	solve(r, s, p);
	cout.precision(12);

	for (int i = 0; i < 3; ++i)
		cout << fixed << val[r][s][p][i] << " ";

	cout << endl;

	return 0;
}