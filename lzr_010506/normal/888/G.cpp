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
#define pll pair<ll, ll>
#define X first
#define Y second
#define py pair<char, char>
#define vi vector<int>
#define vl vector<ll>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define rep0(i, n) for(int i = 0; i < (n); i ++)
#define per0(i, n) for(int i = (n) - 1; i >= 0; i --)
#define ept 1e-9
#define INF 0x3f3f3f3f
#define sz(x) (int)(x).size()
#define ALL(x) (x).begin(), (x).end()
#define lowbit(x) ((x) & -(x))
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
const int N = 2e5 + 10;

int a[N];
ll ans;
int rt[N * 30][2];
int cnt;
void Insert(int x) 
{
	int k = 0;
	rrep(i, 29, 0)
	{
		int id = 1 & (x >> i);
		if (rt[k][id] == 0) 
		{
			rt[k][id] = cnt ++;
			k = rt[k][id];
			rt[k][0] = rt[k][1] = 0;
		}
		else k = rt[k][id];
	}
}

int find_val(int x)
{
	int val = 0, k = 0;
	rrep(i, 29, 0)
	{
		int id = 1 & (x >> i);
		if (rt[k][id] == 0) id ^= 1;
		if (id) val |= (1 << i);
		k = rt[k][id];
	}
	return val;
}

void dfs(int id, int l, int r) 
{
	if (id < 0) return ;
	int mid = l;
	rep(i, l, r - 1)
		if ((a[i] >> id) & 1) 
		{
			mid = i;
			break;
		}
	
	if (mid < r) dfs(id - 1, mid, r);
	if (l < mid) dfs(id - 1, l, mid);
	if (l < mid && mid < r)
	{
		cnt = 0;
		rt[cnt][0] = rt[cnt][1] = 0; 
		cnt ++;
		rep(i, l, mid - 1) Insert(a[i]);
		int val = (1 << 30);
		rep(i, mid, r - 1) val = min(val, a[i] ^ find_val(a[i]));
		ans += val;
	}
}
int main() 
{
	int n = read();
	rep0(i, n) a[i] = read();
	sort(a, a + n);
	dfs(29, 0, n);
	cout << ans;
	return 0;
}