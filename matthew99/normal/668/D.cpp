#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = (a), _end_ = (b); i < _end_; ++i)
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

const int maxqn = 1000100;

struct data
{
	int ty, t, x, id;

	data() { }
	data(int _ty, int _t, int _x): ty(_ty), t(_t), x(_x) { }

	friend bool operator<(const data &x, const data &y)
	{
		return x.x == y.x ? x.id < y.id : x.x < y.x;
	}

};

int qn;
data q[maxqn + 5];

int ans[maxqn + 5];
bool isq[maxqn + 5];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &qn);
	vector<int> allt;
	REP(i, 0, qn) scanf("%d%d%d", &q[i].ty, &q[i].t, &q[i].x), allt.pb(q[i].t), q[i].id = i, isq[i] = q[i].ty == 3;
	sort(ALL(allt));
	int m = SZ(allt);
	REP(i, 0, qn) q[i].t = lower_bound(ALL(allt), q[i].t) - allt.begin() + 1;
	sort(q, q + qn);
	static int c[maxqn + 5];
	memset(c, 0, sizeof c);
	for (int i = 0; i < qn; )
	{
		int j = i;
		while (j < qn && q[j].x == q[i].x) ++j;
		REP(k, i, j)
		{
			if (q[k].ty <= 2) 
			{
				for (int l = q[k].t; l <= m; l += l & -l) 
					if (q[k].ty == 1) ++c[l]; 
					else --c[l]; 
			}
			else
			{
				int &ret = ans[q[k].id];
				ret = 0;
				for (int l = q[k].t; l > 0; l -= l & -l) ret += c[l];
			}
		}
		REP(k, i, j) if (q[k].ty <= 2) for (int l = q[k].t; l <= m; l += l & -l) if (q[k].ty == 1) --c[l]; else ++c[l];
		i = j;
	}
	REP(i, 0, qn) if (isq[i]) printf("%d\n", ans[i]);
	return 0;
}