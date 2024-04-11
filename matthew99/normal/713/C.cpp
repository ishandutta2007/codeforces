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

const int maxn = 3000;

int n;
int a[maxn + 5];

LL dp[maxn + 5][maxn + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	vector<int> v;
	REP(i, 0, n) scanf("%d", a + i), a[i] -= i, v.pb(a[i]);
	sort(ALL(v));
	memset(dp, oo, sizeof dp);
	dp[0][0] = 0;
	REP(i, 0, n) 
	{
		priority_queue<int> le;
		priority_queue<int, vector<int>, greater<int> > ri;
		int bal = 0;
		LL sum = 0;
		static LL Min[maxn + 5];
		memset(Min, oo, sizeof Min);
		REP(j, 0, n) Min[j + 1] = min(Min[j], dp[i][j]);
		REP(j, i, n)
		{
			if (le.empty() || a[j] <= le.top()) le.push(a[j]), sum -= a[j], --bal;
			else ri.push(a[j]), sum += a[j], ++bal;
			if (bal < -1) sum += le.top() << 1, ri.push(le.top()), le.pop(), bal += 2;
			if (bal > 0) sum -= ri.top() << 1, le.push(ri.top()), ri.pop(), bal -= 2;
			LL val = sum;
			if (bal == -1) val += le.top();
			int p = lower_bound(ALL(v), le.top()) - v.begin();
			chkmin(dp[j + 1][p], Min[p + 1] + val);
		}
	}
	printf("%I64d\n", *min_element(dp[n], dp[n] + n));
	return 0;
}