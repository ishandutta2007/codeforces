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

const int maxn = 345678, oo = 123456789;
int t;
int n;
int a[maxn];
map<int, int> app;
int ans[maxn];
int add[maxn];

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> t;
}

void solve()
{
	while (t --> 0)
	{
		app.clear();
		cin >> n;
		F1 (i, n) add[i] = oo;
		add[0] = oo; 
		F1 (i, n) cin >> a[i];
		F1 (i, n)
		{
			if (!app.count(a[i])) app[a[i]] = 0;
			ans[a[i]] = max(ans[a[i]], i - app[a[i]]);
			app[a[i]] = i;
		}
		for (auto x : app)
			ans[x.fi] = max(ans[x.fi], n + 1 - x.se);
		F1 (i, n)
			if (a[i])
			{
				if (ans[a[i]])
				{
					//dbgg(i);
					//dbgg(a[i]);
					//dbg(ans[a[i]]);
					add[ans[a[i]]] = min(add[ans[a[i]]], a[i]);
					ans[a[i]] = 0;
				}
			}
		
		F1 (i, n)
			add[i] = min(add[i], add[i - 1]);
		F1 (i, n)
			if (add[i] != oo)
				cout << add[i] << ' ';
			else cout << -1 << ' ';
		cout << '\n';
	}
}

main()
{
	input();
	solve();
}