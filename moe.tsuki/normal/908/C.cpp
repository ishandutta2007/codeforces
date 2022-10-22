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
const double eps = 1e-3;
int n, r;
double x[maxn], ans[maxn];

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> r;
	F1 (i, n) cin >> x[i];
}

double dist(double a, double b, double c, double d)
{
	return (a - c) * (a - c) + (b - d) * (b - d);
}

void solve()
{
	F1 (i, n)
	{
	/*	int iter = 50;
		double step = 1e8;
		double best = 1e7;
		while (iter --> 0)
		{
			dbgg(step); dbg(best);
			bool flag = true;
			best -= step;
			F1 (j, i - 1)
			{
				if (dist(x[j], ans[j], x[i], best) <= 4 * r * r + eps) flag = false; 
				if (j == 4 && i == 6) dbg(dist(x[j], ans[j], x[i], best));
			}
			if (!flag || best < r) best += step;
			step /= 2;
		}
		ans[i] = best;*/
		vector<double> ha;
		double ma = r;
		F1 (j, i - 1)
		{
			if (abs(x[j] - x[i]) <= r + r + eps)
			{
				ma = max(ma, ans[j] + sqrt(4 * r * r - (x[j] - x[i]) * (x[j] - x[i])));
			}
		}
		ans[i] = ma;
		
	}
	F1 (i, n) cout << setprecision(20) << ans[i] << ' ';
}

main()
{
	input();
	solve();
}