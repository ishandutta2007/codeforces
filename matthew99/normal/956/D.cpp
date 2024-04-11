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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace __gnu_pbds; 

template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template<typename T> inline bool chkmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const double pi = acos(-1.);

const int oo = 0x3f3f3f3f;

const int maxn = 200100;

const double eps = 1e-12;

int n, w;
int x[maxn + 5], v[maxn + 5];
pair<double, double> ang[maxn + 5];

LL ans;

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &w);
	REP(i, 0, n)
	{
		scanf("%d%d", x + i, v + i);
		ang[i] = mp(atan2(v[i] + w, x[i]), atan2(v[i] - w, x[i]));
	}
	ans = 0;
	{
		vector<double> a;
		REP(i, 0, n) a.pb((double)x[i] / (v[i] + w));
		sort(ALL(a));
		for (int i = 0; i < n; )
		{
			int j = i;
			while (j < n && abs(a[j] - a[i]) < eps) ++j;
			ans += LL(j - i) * (j - i - 1) >> 1;
			i = j;
		}
	}
	sort(ang, ang + n);
	REP(i, 0, n) ang[i + n] = mp(ang[i].x + 2 * pi, ang[i].y);
	vector<double> v;
	REP(i, 0, n) v.pb(ang[i].y), v.pb(ang[i].y + 2 * pi);
	sort(ALL(v));
	ordered_set<pair<int, int> > all;
	int ptr = 0;
	REP(i, 0, n) 
	{
		all.insert(mp(lower_bound(ALL(v), ang[i].y - eps) - v.begin(), i));
		all.insert(mp(lower_bound(ALL(v), ang[i].y + 2 * pi - eps) - v.begin(), i));
	}
	for (int i = n; i < (n << 1); )
	{
		int j = i;
		while (j < (n << 1) && abs(ang[j].x - ang[i].x) < eps) ++j;
		while (ang[i].x - ang[ptr].x > pi - eps) 
		{
			all.erase(mp(lower_bound(ALL(v), ang[ptr].y - eps) - v.begin(), ptr));
			all.erase(mp(lower_bound(ALL(v), ang[ptr].y + 2 * pi - eps) - v.begin(), ptr));
			++ptr;
		}
		REP(k, i, j)
		{
			ans += all.order_of_key(mp(upper_bound(ALL(v), ang[k].y + pi + eps) - v.begin(), -1)) - all.order_of_key(mp(lower_bound(ALL(v), ang[k].y - eps) - v.begin(), -1));
		}
		REP(k, i, j)
		{
			all.insert(mp(lower_bound(ALL(v), ang[k].y - eps) - v.begin(), k));
			all.insert(mp(lower_bound(ALL(v), ang[k].y + 2 * pi - eps) - v.begin(), k));
		}
		i = j;
	}
	cout << ans << endl;
	return 0;
}