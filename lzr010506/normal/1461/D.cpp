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
#define ALL(x) (x).begin(), (x).end()
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
const int N = 2e6 + 10;
#define int long long
map<ll, int> Ans;
ll s[N];
int T, n, q, a[N], pl[N];

int find(int x, int y, int num) 
{
	int L = x, R = y + 1, ans = x;
	while (L <= R) 
	{
		int mid = (L + R) >> 1;
		if (a[mid] <= num) L = mid + 1, ans = mid;
		else R = mid - 1;
	}
	return ans;
}

void work(int x, int y) 
{
	Ans[s[y] - s[x - 1]] = 1;
	if (x == y || a[x] == a[y]) return;
	int num = (a[x] + a[y]) >> 1;
	int fen = find(x, y, num);
	work(x, fen);
	work(fen + 1, y);
}

signed main() 
{
	int T = read();
	while(T --)
	{
		Ans.clear();
		int n = read();
		int q = read();
		rep(i, 1, n) a[i] = read();
		sort(a + 1, a + n + 1);

		s[0] = 0;
		rep(i, 1, n) s[i] = s[i - 1] + a[i];

		work(1, n);
		while(q --)
		{
			int x = read();
			if (Ans[x]) puts("Yes");
			else puts("No");
		}
	}

	return 0;
}