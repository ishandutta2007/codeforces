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

const int maxn = 5678;
int n, ans, a[maxn], b[maxn], p[maxn], q[maxn], used[maxn];
vi v;

void input()
{
	cin >> n;
}

void solve()
{
	for (int i = 0; i < n; ++i)
	{
		cout << "? " << 0 << ' ' << i << '\n';
		fflush(stdout);
		cin >> b[i];
	}
	for (int i = 0; i < n; ++i)
	{
		cout << "? " << i << ' ' << 0 << '\n';
		fflush(stdout);
		cin >> a[i];
	}
	for (int i = 0; i < n; ++i)
	{
		// assume a[0] = i
		p[0] = i;
		for (int j = 1; j < n; ++j)
			p[j] = p[0] ^ a[0] ^ a[j];
		q[0] = a[0] ^ p[0];
		for (int j = 1; j < n; ++j)
			q[j] = q[0] ^ b[0] ^ b[j];
		
		int flag = 1;
		
		for (int j = 0; j < n; ++j)
			used[j] = 0;
		for (int j = 0; j < n; ++j)
		{
			if (used[p[j]]) flag = 0;
			used[p[j]] = 1;
		}
		
		for (int j = 0; j < n; ++j)
			used[j] = 0;
		for (int j = 0; j < n; ++j)
		{
			if (used[q[j]]) flag = 0;
			used[q[j]] = 1;
		}
		
		for (int j = 0; j < n; ++j)
			if (p[q[j]] != j) flag = 0;
			
		if (flag && !v.size()) 
			for (int i = 0; i < n; ++i) v.pb(p[i]);
			
		ans += flag;
	}
	cout << "!\n";
	cout << ans << '\n';
	for (int i = 0; i < n; ++i) cout << v[i] << ' ';
	cout << '\n';
}

main()
{
	input();
	solve();
}