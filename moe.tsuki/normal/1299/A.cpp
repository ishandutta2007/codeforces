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
int cnt[34];

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	F1 (i, n) cin >> a[i];
}

void solve()
{
	F1 (i, n)
	{
		F (j, 31)
		{
			if (a[i] & (1 << j)) ++cnt[j]; 
		}
	}
	F1 (i, n) b[i] = a[i];
	int mx = 0;
	int cur = 0;
	F1 (i, n)
	{
		F (j, 31)
		{
			if (cnt[j] >= 2 && (a[i] & (1 << j)))
				a[i] -= 1 << j;
		}
		if (a[i] >= mx)
		{
			mx = a[i];
			cur = i;
		}
	}
	cout << b[cur] << ' ';
	F1 (i, n)
		if (i != cur) cout << b[i] << ' ';
}

main()
{
	input();
	solve();
}