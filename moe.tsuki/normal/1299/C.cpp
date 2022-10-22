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

const int maxn = 1234567;
int n;
int a[maxn];
int pre[maxn];
double b[maxn];

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	F1 (i, n) cin >> a[i];
}

pii con[maxn];

bool better(pii a, pii b, pii c)
{
	return (c.se - a.se) * (b.fi - a.fi) <= (b.se - a.se) * (c.fi - a.fi); 
}

void solve()
{
	F1 (i, n) pre[i] = pre[i - 1] + a[i];
	int cur = 1;
	F (i, n + 1)
	{
		if (cur <= 2)
		{
			con[cur++] = mp(i, pre[i]);	
		} else
		{
			while (cur > 2 && 
				better(con[cur - 2], con[cur - 1], mp(i, pre[i])))
			{
				--cur;
			}
			con[cur++] = mp(i, pre[i]);	
		}
	}
	/*F1 (i, cur - 1)
	{
		dbg(con[i]);
	}*/
	int last = 0;
	F1 (i, n) b[i] = a[i];
	for (int i = 2; i <= cur - 1; ++i)
	{
		double sum = 0;
		for (int j = last + 1; j <= con[i].fi; ++j)
			sum += b[j];
		for (int j = last + 1; j <= con[i].fi; ++j)
			b[j] = sum / (con[i].fi - last);
		last = con[i].fi;
	}
	cout << setprecision(20);
	F1 (i, n) cout << b[i] << '\n';
}

main()
{
	input();
	solve();
}