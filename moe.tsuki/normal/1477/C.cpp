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
int n;
int x[maxn], y[maxn];
int vis[maxn];
int a[maxn];

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	F1 (i, n) cin >> x[i] >> y[i];
}

void solve()
{
	int cur = 0;
	F1 (i, n)
		F1 (j, n)
		{
			if ((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j])
				> cur)
			{
				cur = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
				a[1] = i; a[2] = j;
			}
		}
	vis[a[1]] = vis[a[2]] = true;
	for (int i = 2; i <= n - 1; ++i)
	{
		cur = 0;
		F1 (j, n) if (!vis[j])
			if ((x[a[i]] - x[j]) * (x[a[i]] - x[j]) + (y[a[i]] - y[j]) * (y[a[i]] - y[j])
				> cur)
			{
				cur = (x[a[i]] - x[j]) * (x[a[i]] - x[j]) + (y[a[i]] - y[j]) * (y[a[i]] - y[j]);
				a[i + 1] = j;
			}
		vis[a[i + 1]] = true;
	}
	F1 (i, n) cout << a[i] << ' ';
}

main()
{
	input();
	solve();
}