#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(x) begin(x),end(x)
#define F(i,n) for (int i = 0; i < n; ++i)
#define F1(i,n) for (int i = 1; i <= n; ++i)
#define dbg(x) cerr << #x << " = " << x << endl
#define dbgg(x) cerr << #x << " = " << x << ' '
#define T(x) x[pool]
#define mineq(x,y) { if ((x) > (y)) (x) = (y); }
#define maxeq(x,y) { if ((x) < (y)) (x) = (y); }
#define MEOW cout << "meowwwww" << '\n'; system("pause");
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;

template<typename T>
ostream& operator <<(ostream &s, const vector<T> &c)
{
	s << "[ "; for (auto it : c) s << it << " "; s << "\b]\n";
	return s;
}

template<typename T>
ostream& operator <<(ostream &s, const pair<int, T> &c)
{
	s << "[ "; cout << c.fi << " , " << c.se << " ] ";
	return s;
}

int q;

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> q;
}

const int maxn = 234567;
int k;
int x, A, y, B;
int pre[3][maxn];
int Pre[maxn];
int a[maxn];

bool ok(int cur)
{
	//dbg(cur);
	int ab = pre[2][cur], b = pre[1][cur], a = pre[0][cur];
	b += ab; a += b;
	//dbgg(ab); dbgg(b); dbg(a);
	int res = Pre[ab] * (A + B) + (Pre[b] - Pre[ab]) * B + (Pre[a] - Pre[b]) * A;
	//dbg(cur);
	//dbg(res);
	return res >= k;
}

void solve()
{
	while (q --> 0)
	{
		int n; cin >> n;
		F1 (i, n) cin >> a[i];
		cin >> A >> x >> B >> y;
		cin >> k;
		F1 (i, n) a[i] = -a[i] / 100;
		sort(a + 1, a + n + 1);
		F1 (i, n) a[i] = -a[i];
		F1 (i, n) Pre[i] = 0;
		F1 (i, n) Pre[i] = Pre[i - 1] + a[i];
		if (A > B) swap(x, y), swap(A, B);
		F1 (i, n) pre[0][i] = pre[1][i] = pre[2][i] = 0;
		for (int i = x; i <= n; i += x) pre[0][i] += 1;
		for (int i = y; i <= n; i += y) pre[1][i] += 1;
//F1 (i, n) dbg(a[i]);
		int l = x * y / __gcd(x, y);
		//dbg(l);
		for (int i = l ; i <= n; i += l) 
			pre[0][i] -= 1, pre[1][i] -= 1, pre[2][i] += 1;
		F1 (i, n) pre[0][i] += pre[0][i - 1];
		F1 (i, n) pre[1][i] += pre[1][i - 1];
		F1 (i, n) pre[2][i] += pre[2][i - 1];
//F1 (i, n) dbgg(pre[0][i]);
//dbg("");F1 (i, n) dbgg(pre[1][i]);
//dbg("");F1 (i, n) dbgg(pre[2][i]);
//dbg("");
		int d = 1;
		while (d <= n) d <<= 1;
		int ans = 0;
		while (d >>= 1)
		{
			if (ans + d <= n && !ok(ans + d)) ans += d;
		}
		if (ans == n) cout << "-1\n";
		else cout << ans + 1 << '\n';
	}
}

main()
{
	input();
	solve();
}