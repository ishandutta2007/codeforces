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

const int maxn = 567890;
int n, k;
int a[maxn];
int sz[maxn];
int pre[maxn];
int pp[maxn];
int mpre[maxn];
int npre[maxn];

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k;
	F1 (i, n) cin >> a[i];
}

void solve()
{
	sort(a + 1, a + n + 1);
	int sum = 0;
	int cur = 0;
	int ans = -1234567890123456789ll;
	if (k == 0)
	{
		int fu = 0;
		F1 (i, n) fu += a[i] * (i - 1);
		cout << fu << '\n';
		return;
	}
	for (int i = n; i >= 1; --i)
		if (a[i] >= 0)
		{ 
			cur += sum;
			sum += a[i];
			--n;
		}
	for (int i = 1; i <= n; ++i)
	{
		//pre[i % k][(i + k - 1) / k] = pre[i % k][(i - 1) / k] + a[i] * (i - 1) / k;
		pre[i] = pre[max(i - k - 1, 0ll)] + a[i] * ((i - 1) / (k + 1));
	}
	//F1 (i, n) dbg(pre[i]);
	for (int i = 1; i <= n; ++i)
	{
		pp[i] = pp[i - 1] + pre[i];
		pp[i] -= pre[max(i - k - 1, 0ll)];
	}
	//F1 (i, n) dbg(pp[i]);
	for (int i = 1; i <= n; ++i)
		mpre[i] = mpre[i - 1] + i * a[i];
	for (int i = 1; i <= n; ++i)
		npre[i] = npre[i - 1] + a[i];
	for (int i = n; i >= 0; --i)
	{
		int now = cur + sum * i;
		int lft = n - i;
		if ((lft + k - 1) / k > i) continue;
		int bot = lft + (lft + k - 1) / k;
		//dbg(lft);
		//dbg(bot);
		now += pp[bot];
		//for (int j = bot + 1; j <= bot + i - (lft + k - 1) / k; ++j)
		//	now += a[j] * (j);
		now += mpre[bot + i - (lft + k - 1) / k] - mpre[bot];
		now += (npre[bot + i - (lft + k - 1) / k] - npre[bot])
		 * (-bot + (lft + k - 1) / k - 1);
		ans = max(ans, now);	
	}
	cout << ans << '\n';
}

main()
{
	input();
	solve();
}