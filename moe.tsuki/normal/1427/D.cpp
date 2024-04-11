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

int n;
int a[56], b[56];

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n; 
	F1 (i, n)
		cin >> a[i]; 
}

vector<vi> ANS;

void solve()
{
	a[0] = 123;
	int fu = 0;
	while (true)
	{
		fu ^= 1;
		//F1 (i, n) dbg(a[i]);
		vi ans;
		int cur = 0;
	 	for (int i = n; i >= 1; --i)
	 	{
	 		++cur;
	 		if (i != 1 && ((a[i - 1] < a[i]) ^ fu))
			{
			} else 
			{
				ans.pb(cur);
				cur = 0;
			}
		}
		int suf = n;
		int ptr = 0;
		for (auto x : ans)
		{
			int pos = suf - x + 1;
			F1 (i, x)
				b[++ptr] = a[pos + i - 1];
			suf -= x;
		}
		F1 (i, n) a[i] = b[i];
		if (ans.size() > 1) 
			ANS.pb(ans);
		bool ok = true;
		F1 (i, n) if (a[i] != i) ok = false;
		if (ok) break;
		ok = true;
		F1 (i, n) if (a[i] + i != n + 1) ok = false;
		if (ok)
		{
			ans.clear();
			F1 (i, n) ans.pb(1);
			ANS.pb(ans);
			break;
		}
		//dbg(ans);
	}
	cout << ANS.size() << '\n';
	for (auto ans : ANS)
	{
		cout << ans.size();
		for (int i = ans.size() - 1; i >= 0; --i)
		{
			cout << ' ' << ans[i];
		}
		cout << '\n';
	}
}

main()
{
	input();
	solve();
}