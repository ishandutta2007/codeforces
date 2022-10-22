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

const int maxn = 34;
int n, l;
int c[maxn], del[maxn];

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> l;
	F1 (i, n) cin >> c[i];
}

void solve()
{
	for (int i = n; i >= 2; --i)
		for (int j = i - 1; j >= 1; --j)
			if (c[i] << j >= c[j] << i) del[i] = true;
	for (int i = n - 1; i >= 1; --i) c[i] = min(c[i], c[i + 1]);
	int ans = 0;
	int ANS = 1000000000000000000ll;
	for (int i = n; i >= 1; --i)
	{
		// dbg(l);
		if (!del[i])
		{
			
			ans += c[i] * (l / (1 << (i - 1)));
			l %= 1 << (i - 1);
			if (l) ANS = min(ANS, ans + c[i]);
		}
	}
	cout << min(ANS, ans) << '\n';
}

main()
{
	input();
	solve();
}