#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const int oo = 0x3f3f3f3f;

const int maxn = 5010, maxm = 1000;

int n_v, m;
int val[maxm + 5][maxn + 5];
int op[maxn + 5], lhs[maxn + 5], rhs[maxn + 5];

map<string, int> id;

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n_v, &m);
	id["?"] = n_v;
	REP(i, 0, n_v)
	{
		string s;
		cin >> s;
		id[s] = i;
		cin >> s;
		cin >> s;
		if (isdigit(s[0]))
		{
			op[i] = -1;
			REP(j, 0, m) val[j][i] = s[j] - '0';
		}
		else
		{
			lhs[i] = id[s];
			cin >> s;
			if (s[0] == 'A') op[i] = 0;
			else if (s[0] == 'O') op[i] = 1;
			else op[i] = 2;
			cin >> s;
			rhs[i] = id[s];
		}
	}
	REP(i, 0, m)
	{
		int Min = oo, Minp = -1;
		REP(j, 0, 2)
		{
			val[i][n_v] = j;
			int ret = 0;
			REP(k, 0, n_v)
			{
				if (~op[k])
				{
					if (op[k] == 0) val[i][k] = val[i][lhs[k]] & val[i][rhs[k]];
					if (op[k] == 1) val[i][k] = val[i][lhs[k]] | val[i][rhs[k]];
					if (op[k] == 2) val[i][k] = val[i][lhs[k]] ^ val[i][rhs[k]];
				}
				ret += val[i][k];
			}
			if (chkmin(Min, ret)) Minp = j;
		}
		printf("%d", Minp);
	}
	printf("\n");
	REP(i, 0, m)
	{
		int Max = -1, Maxp = -1;
		REP(j, 0, 2)
		{
			val[i][n_v] = j;
			int ret = 0;
			REP(k, 0, n_v)
			{
				if (~op[k])
				{
					if (op[k] == 0) val[i][k] = val[i][lhs[k]] & val[i][rhs[k]];
					if (op[k] == 1) val[i][k] = val[i][lhs[k]] | val[i][rhs[k]];
					if (op[k] == 2) val[i][k] = val[i][lhs[k]] ^ val[i][rhs[k]];
				}
				ret += val[i][k];
			}
			if (chkmax(Max, ret)) Maxp = j;
		}
		printf("%d", Maxp);
	}
	return 0;
}