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

const int maxn = 2345;
int n, k;
int a[10];
int A[maxn];
int dp[maxn][maxn];

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k;
	F1 (i, n)
	{
		string s;
		cin >> s;
		int cur = 0;
		for (int i = 6; i >= 0; --i)
		{
			cur += (s[i] - '0') << (6 - i);
		}
		A[i] = cur;
		//dbg(A[i]);
	}
}

void gao(int pos, int lft)
{
	//dbgg(pos); dbg(lft);
	if (pos == n + 1) return;
	for (int x = 9; x >= 0; --x)
	{
		if ((A[pos] | a[x]) == a[x])
		{
			int cur = __builtin_popcount(a[x]) - __builtin_popcount(A[pos]);
			if (lft >= cur)
			{
				if (dp[pos + 1][lft - cur]) 
				{
					cout << (char)(x + '0');
					gao(pos + 1, lft - cur);
					return;
				}
			}
		}
	}
}

void solve()
{
	a[0] = 119; //"1110111", 
	a[1] = 18; //"0010010", 
	a[2] = 93; //"1011101", 
	a[3] = 91; //"1011011", 
	a[4] = 58; //"0111010", 
	a[5] = 107; //"1101011", 
	a[6] = 111; //"1101111", 
	a[7] = 82; //"1010010", 
	a[8] = 127; //"1111111", 
	a[9] = 123; //"1111011";
	dp[n + 1][0] = 1;
	for (int i = n; i >= 1; --i)
	{
		for (int j = 0; j <= k; ++j)
		{
			for (int x = 0; x <= 9; ++x)
			{
				if ((A[i] | a[x]) == a[x])
				{
					int cur = __builtin_popcount(a[x]) - __builtin_popcount(A[i]);
					if (j >= cur)
					{
						if (dp[i + 1][j - cur]) dp[i][j] = 1;
					}
				}
			}
		}
	}
	if (dp[1][k] == 1)
	{
		gao(1, k);
		cout << '\n';
	}
	else
	{
		cout << "-1\n";
	}
}

main()
{
	input();
	solve();
}