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

int t;
int a[5678];
int f[5678];

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> t;
}

int fd(int x)
{
	if (f[x] == x) return x;
	return f[x] = fd(f[x]);
}

void solve()
{
	while (t --> 0)
	{
		int n; cin >> n;
		long long ans = 0;
		F1 (i, n) cin >> a[i];
		F1 (i, n)
		{
			if (a[i] + i > n && a[i] != 1) 
			{
				ans += a[i] - n - 1 + i;
				a[i] = n - i + 1;
			}
			F1 (i, n) f[i] = i;
			f[n + 1] = n + 1;
			while (a[i] != 1)
			{
				++ans;
				int j = i;
				while (j <= n)
				{
					//dbg(j);
					if (a[j] == 1 && f[j] != j) 
					{
						j = f[j];
						continue;
					}
					int k = j + a[j]; 
					a[j] = max(a[j] - 1, 1);
					if (a[j] == 1) f[j] = fd(j + 1);
					j = k;
				}
			}
		}
		cout << ans << '\n';
	}
}

main()
{
	input();
	solve();
}