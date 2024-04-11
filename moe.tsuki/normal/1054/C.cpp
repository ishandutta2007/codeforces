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

const int maxn = 1234;
int n;
int l[maxn], r[maxn];
int L[maxn], R[maxn];
int p[maxn], s[maxn];
int ans[maxn];

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	F1 (i, n) cin >> l[i];
	F1 (i, n) cin >> r[i];
}

void solve()
{
	int cur = n;
	F1 (i, n) L[i] = l[i], R[i] = r[i];
	while (true)
	{
		vi v;
		
		F1 (i, n) p[i] = s[i] = 0;
		int z = 0;
		F1 (i, n)
		{
			if (l[i] == 0 && r[i] == 0) 
			{
				p[i] = s[i] = 1;
				v.pb(i);
				l[i] = r[i] = -1;
				ans[i] = cur;
				++z;
			}
		}
		if (!z) break;
		F1 (i, n) p[i] += p[i - 1];
		F1 (i, n) s[n - i + 1] += s[n - i + 2];
		F1 (i, n) l[i] -= p[i - 1];
		F1 (i, n) r[i] -= s[i + 1];
		--cur;
	}
	int ok = 1;
	F1 (i, n)
	{
		for (int j = 0; j < i; ++j) if (ans[j] > ans[i]) --L[i];
		for (int j = i + 1; j <= n; ++j) if (ans[j] > ans[i]) --R[i];
		if (L[i] != 0 || R[i] != 0) ok = 0;
	}
	if (ok) 
	{
		cout << "YES\n";
		F1 (i, n) cout << ans[i] << ' ';
	} else cout << "NO\n";
}

main()
{
	input();
	solve();
}