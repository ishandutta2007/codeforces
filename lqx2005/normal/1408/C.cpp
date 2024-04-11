#include<bits/stdc++.h>
#define rep(x, L, R) for(int x = (L), _x = (R); x <= _x; x++)
#define per(x, R, L) for(int x = (R), _x = (L); x >= _x; x--)
#define mpr make_pair
#define x(v) (v).first
#define y(v) (v).second
#define siz(v) (int)(v).size()
#define pb push_back
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef double db;
const db eps = 1e-7;
const int N = 1e5 + 10;
int t, n;
db l;
db a[N];
int check(db t)
{
	db sp = 1, lp = a[n + 1], rp = a[0], r = t;
	rep(i, 1, n + 1)
	{
		db p = (a[i] - a[i - 1]) / sp;
		if(t >= p) t -= p;
		else
		{
			lp = a[i - 1] + sp * t;
			break;
		}
		sp += 1;
	}
	sp = 1;
	t = r;
	per(i, n, 0)
	{
		db p = (a[i + 1] - a[i]) / sp;
		if(t >= p) t -= p;
		else
		{
			rp = a[i + 1] - sp * t;
			break;
		}
		sp += 1;
	}
	if(lp > rp) return 0;
	return 1;
	
}
int main()
{
	scanf("%d", &t);
	rep(amo, 1, t)
	{
		scanf("%d%lf", &n, &l);
		rep(i, 1, n) scanf("%lf", &a[i]);
		a[0] = 0;
		a[n + 1] = l;
		db L = 0, R = l, best = -1;
		while(R - L > eps)
		{
			db mid = (L + R) / 2;
			if(check(mid)) best = mid, L = mid;
			else R = mid;
		}
		printf("%.10lf\n", best);
	}
	return 0;
}