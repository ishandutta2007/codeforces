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

const int maxn = 234567;
int n;
string s;
int pre[maxn];
int nxt[maxn];

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> s;
}

void solve()
{
	n = s.length();
	F1 (i, n) if (s[i - 1] == '1')
		pre[i] = 1;
	F1 (i, n) pre[i] += pre[i - 1];
	int ans = 0;
	int sqr = 200;
	F1 (i, sqr)
	{
		vi v;
		F (j, n + 1) v.pb(i * pre[j] - j);
		/*F (j, n + 1)
		{
			ans += cnt[i * pre[j] - j + maxn] * (cnt[i * pre[j] - j + maxn] - 1) / 2;
			cnt[i * pre[j] - j + maxn] = 0;
		}*/
		sort(all(v));
		int last = -1000000007;
		for (auto x : v)
		{
			if (x == last) continue;
			int cur = upper_bound(all(v), x) - lower_bound(all(v), x);
			ans += cur * (cur - 1) / 2;
			last = x;
		}
	}
	//dbg(ans);
	int cur = n + 1;
	for (int i = n; i >= 1; --i)
	{
		nxt[i] = cur;
		if (pre[i] > pre[i - 1]) cur = i;
	}
	//F1 (i, n) dbg(nxt[i]);
	F1 (i, n)
	{
		int pos = i;
		while (pos <= n)
		{
			int cnt = pre[pos] - pre[i - 1];
			if (cnt * (sqr + 1) > pos - i + 1)
			{
				pos = i + cnt * (sqr + 1) - 1;
				continue;
			} 
			if (cnt)
			{
				// pos ~ nxt[pos] - 1
				int l = pos - i + 1, r = nxt[pos] - 1 - i + 1;
				l = max((l + cnt - 1) / cnt, sqr + 1); r = r / cnt;
				if (r >= l) ans += r - l + 1;
			}
			pos = nxt[pos]; 
		}
	}
	cout << ans << '\n'; 
}

main()
{
	input();
	solve();
}