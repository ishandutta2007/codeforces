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

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	scanf("%d", &n);
	vector<int> v;
	REP(i, 0, n * n)
	{
		int x;
		scanf("%d", &x);
		v.pb(x);
	}
	sort(ALL(v), greater<int>());
	vector<int> ans;
	map<int, int> all;
	for (auto it : v)
	{
		if (!all[it]) 
		{
			for (auto it0 : ans) all[__gcd(it0, it)] += 2;
			ans.pb(it);
			++all[it];
		}
		else --all[it];
	}
	for (auto it : ans) printf("%d ", it);
	return 0;
}