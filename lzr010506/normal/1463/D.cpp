#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define il inline
#define db double
#define ls rt << 1
#define rs rt << 1 | 1
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define X first
#define Y second
#define pcc pair<char, char>
#define vi vector<int>
#define vl vector<ll>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define rep0(i, n) for(int i = 0; i < (n); i ++)
#define per0(i, n) for(int i = (n) - 1; i >= 0; i --)
#define ept 1e-9
#define INF 0x3f3f3f3f
#define sz(x) (x).size()
#define All(x) (x).begin(), (x).end()
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
inline ll read1()
{
	ll x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
const int N = 400010;
int a[N];
int b[N], n;

bool check(int x)
{
	int cnt = 0;
	int now = 0;
	for(int i = 2 * n; i >= 1; i --)
	{
		if(now == x) return 1;
		if(b[i] == 1) continue;
		now ++;
		if(a[x + 1 - now] > i) return 0;
	}
	return 1;
}


bool check1(int x)
{
	int cnt = 0;
	int now = n + 1;
	int p = 0;
	for(int i = 1; i <= 2 * n; i ++)
	{
		if(p == x) return 1;
		if(b[i] == 1) continue;
		now --;
		p ++;
		if(a[n + 1 - (x + 1 - (n + 1 - now))] < i) return 0;
	}
	return 1;
}

int main()
{
	int T = read();
	while(T --)
	{
		n = read();
		rep(i, 1, 2 * n) b[i] = 0;
		rep(i, 1, n)
			a[i] = read(), b[a[i]] = 1;
		sort(a + 1, a + n + 1);
		int l = 1, r = n, L = 0;
		while(l <= r)
		{
			int mid = l + r >> 1;
			if(check(mid) == 1) L = mid, l = mid + 1;
			else r = mid - 1;
		}
		l = 1, r = n;
		int R = 0;
		while(l <= r)
		{
			int mid = l + r >> 1;
			if(check1(mid) == 1) R = mid, l = mid + 1;
			else r = mid - 1;
		}
		//	L = n - L;
		R = n - R;
		//cout << L << " " << R << endl;
		printf("%d\n", max(0, L - R + 1));
	}
}