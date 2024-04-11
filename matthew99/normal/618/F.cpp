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

const int maxn = 1000000;

int n;
int a[maxn + 5], b[maxn + 5];

LL suma[maxn + 5], sumb[maxn + 5];

int p[maxn + 5];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	suma[0] = 0;
	REP(i, 0, n) scanf("%d", a + i), suma[i + 1] = suma[i] + a[i];
	REP(i, 0, n) scanf("%d", b + i), sumb[i + 1] = sumb[i] + b[i];
	vector<int> ansa, ansb;
	bool flag = 0;
	if (suma[n] > sumb[n]) 
	{
		flag = 1;
		REP(i, 0, n) swap(a[i], b[i]);
		REP(i, 0, n + 1) swap(suma[i], sumb[i]);
	}
	int j = 0;
	static int lst[maxn + 5];
	memset(lst, -1, sizeof lst);
	REP(i, 1, n + 1)
	{
		while (suma[i] - sumb[j] >= n) ++j;
		if (suma[i] == sumb[j])
		{
			REP(k, 0, i) ansa.pb(k);
			REP(k, 0, j) ansb.pb(k);
			break;
		}
		p[i] = j;
		int &lyc = lst[suma[i] - sumb[j]];
		if (lyc != -1)
		{
			REP(k, lyc, i) ansa.pb(k);
			REP(k, p[lyc], p[i]) ansb.pb(k);
			break;
		}
		lyc = i;
	}
	if (flag) swap(ansa, ansb);
	LL sum0 = 0, sum1 = 0;
	printf("%d\n", SZ(ansa)); for (auto x : ansa) printf("%d ", x + 1), sum0 += flag ? b[x] : a[x];
	printf("\n");
	printf("%d\n", SZ(ansb)); for (auto x : ansb) printf("%d ", x + 1), sum1 += flag ? a[x] : b[x];
	assert(sum0 == sum1);
	printf("\n");
	return 0;
}