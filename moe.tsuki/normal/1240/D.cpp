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
 
const int maxn = 345678;
int q;
int a[maxn];
map<int, int> m[maxn];
int rt[maxn];
int m1[maxn];

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> q;
}
 
void solve()
{
	while (q --> 0)
	{
		int n; cin >> n;
		F1 (i, n) cin >> a[i];
		for (int i = n; i >= 1; --i)
		{
			rt[i] = i;
			if (i < n)
			{
				if (m[rt[i + 1]].find(a[i]) != m[rt[i + 1]].end())
				{
					int jump = m[rt[i + 1]][a[i]] + 1;
					if (jump <= n)
						rt[i] = rt[jump];
					else rt[i] = n + 1;
				}
			}
			m[rt[i]][a[i]] = i;
		} 
		//F1 (i, n) dbg(rt[i]); 
		int ans = 0;
		++m1[n + 1];
		F1 (i, n) ++m1[rt[i]];
		F1 (i, n + 1) ans += m1[i] * (m1[i] - 1) / 2;
		F1 (i, n + 1) m[i].clear();
		F1 (i, n + 1) m1[i] = 0;
		cout << ans << '\n';
	}
}
 
main()
{
	input();
	solve();
}