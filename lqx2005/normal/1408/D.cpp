#include<bits/stdc++.h>
#define rep(x, L, R) for(int x = (L), _x = (R); x <= _x; x++)
#define per(x, R, L) for(int x = (R), _x = (L); x >= _x; x--)
#define mpr make_pair
#define siz(v) (int)(v).size()
#define pb push_back
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef double db;
const int N = 2010;
const int M = 1e6 + 10;
const int inf = 1e6;
struct poi
{
	int x, y;
	poi(int X = 0, int Y = 0) : x(X), y(Y){}
}a[N], b[N], c[N];
int mx[M];
int n, m, tot = 0;
int q(int x)
{
	if(x > inf) return 0;
	if(x < 0) return c[tot - 1].y;
	return mx[x];
}
int calc(int de)
{
	int del = 0;
	rep(i, 1, n)
	{
		del = max(del, q(a[i].x + de) + 1 - a[i].y);
	}
	return del;
}
int find(int be, int v)
{
	int l = be, r = inf, best = -1;
	if(l > r) return -1;
	while(l <= r)
	{
		int mid = (l + r) / 2;
		if(calc(mid) >= v) l = mid + 1;
		else r = mid - 1, best = mid;
	}
	return best;
}
int cmp(poi a, poi b)
{
	if(a.x != b.x) return a.x > b.x;
	return a.y > b.y;
}
int main()
{
	scanf("%d%d", &n, &m);
	rep(i, 1, n) scanf("%d%d", &a[i].x, &a[i].y);
	rep(i, 1, m) scanf("%d%d", &b[i].x, &b[i].y);
	sort(b + 1, b + m + 1, cmp);
	int  las = -1;
	c[0] = poi(inf, -1);
	rep(i, 1, m) 
	{
		if(b[i].y > las)
		{
			c[++tot] = b[i];
			las = b[i].y;
//			cout << b[i].y << endl;
		}
	}
	c[++tot] = poi(-1, inf);
	
	per(i, tot - 1, 0)
	{
		rep(j, c[i + 1].x + 1, c[i].x) mx[j] = c[i].y;
	}
	
	int be = 0;
	int ans = calc(0), pos, pre = ans;
//	cout << ans << endl;
	while((pos = find(be + 1, pre)) != -1)
	{
		pre = calc(pos);
//		cout << pos <<" "<< pre << endl;
		ans = min(ans, pre + pos);
		be = pos;
	}
	printf("%d\n", ans);
	return 0;
}