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

const int N = 5001, maxn = 1000001;
int n, m, p;
int l[maxn];
int f[N][N];
int frac[N];
int P[maxn];
vi last, cur;

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m >> p;
	F1 (i, n) cin >> l[i];
}

void solve()
{
	f[1][0] = 1;
	for (int i = 2; i < N; ++i)
		for (int j = 1; j < N; ++j)
			f[i][j] = (f[i - 1][j - 1] + f[i - 1][j] * j % p) % p;
	frac[0] = 1;
	F1 (i, N - 1) frac[i] = frac[i - 1] * i % p;
	P[0] = 1;
	F1 (i, maxn - 1) P[i] = P[i - 1] * (m - i + 1) % p;
	int sum = 1;
	F1 (i, n)
	{
		cur.resize(l[i]);
		F (j, l[i])
		{
			cur[j] = f[l[i]][j] * P[j + 1] % p;
			cur[j] = cur[j] * sum % p;
			if (l[i - 1] > j)
				cur[j] = ((cur[j] - last[j] * (f[l[i]][j] * frac[j + 1] % p) % p) % p + p) % p; 
		}
		sum = 0;
		F (j, l[i]) sum = (sum + cur[j]) % p;
		last.resize(l[i]);
		F (j, l[i]) last[j] = cur[j]; 	
	} 
	cout << sum << '\n';
}
 
main()
{
	input();
	solve();
}