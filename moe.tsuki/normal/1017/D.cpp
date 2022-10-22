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

const int maxn = 5678910, mmx = 4567;
int n, q, m;
int w[maxn];
string s[maxn];
int app[mmx];
int pre[mmx][123];

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m >> q;
	F1 (i, n) cin >> w[i];
	F1 (i, m) cin >> s[i];
}

void solve()
{
	F1 (i, m)
	{
		//string c = s[i];
		int val = 0;
		for (int j = 0; j < n; ++j)
		{
			val *= 2;
			val += s[i][j] - '0';
		}
		++app[val];
	}
	int mx = 1 << n;
	F (i, mx) F (j, mx)
	{
		int cur = 1 << (n - 1);
		int pos = 1;
		int now = 0;
		while (cur)
		{
			if ((cur & i) == (cur & j))
				now += w[pos]; 
			cur >>= 1;
			++pos;
		}
		if (now <= 100) pre[i][now] += app[j];
	}
	F (i, mx)
	{
		F1 (j, 100)
			pre[i][j] += pre[i][j - 1];
	}
	F1 (i, q)
	{
		string s; int k;
		cin >> s >> k;
		int val = 0;
		for (int j = 0; j < n; ++j)
		{
			val *= 2;
			val += s[j] - '0';
		}
		cout << pre[val][k] << '\n';
	}
}

main()
{
	input();
	solve();
}