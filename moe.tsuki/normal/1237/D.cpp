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

const int maxn = 123456;
int n;
int a[maxn];
int b[maxn];
int ans[maxn];
deque<pii> deq;

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	F1 (i, n) cin >> a[i];
}

void solve()
{
	int mx = 0; 
	int pos = 0;
	F1 (i, n) if (a[i] > mx) mx = a[i], pos = i;
	F1 (i, n) b[i] = a[(pos + i - 1) % n + 1];
	/*F1 (i, n) mn[i][0] = a[i];
	F1 (i, LOG - 1)
		F1 (j, n)
			mn[j][i] = min(mn[j][i - 1], mn[min(j + (1 << i), n)][i - 1]);
	*/
	ans[n] = -1;
	for (int i = 1; i <= n; ++i)
		if (b[i] + b[i] < b[n]) { ans[n] = n + i; break; }
	if (ans[n] == -1)
	{
		F1 (i, n) cout << "-1 "; return;
	}
	//F1 (i, n) dbg(b[i]);
	for (int i = n - 1; i >= 1; --i)
	{
		ans[i] = ans[i + 1];
		int saga = b[i] / 2; if (b[i] & 1); else saga--;
		while (deq.size() && deq.front().fi <= saga)
		{
			ans[i] = deq.front().se; deq.pop_front();
		}
		while (deq.size() && deq.back().fi >= b[i])
			deq.pop_back();
		deq.push_back(mp(b[i], i));
	}
	F1 (i, n) ans[i] -= i;
	for (int i = 1; i <= n; ++i) cout << ans[(i + n - pos - 1) % n + 1] << ' ';
}

main()
{
	input();
	solve();
}