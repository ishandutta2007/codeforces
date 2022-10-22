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

const int maxn = 123456, oo = 12345678912ll;
int n, p, q, r, a[maxn], apre[maxn], bpre[maxn], asuf[maxn], bsuf[maxn];


void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> p >> q >> r;
	F1(i, n) cin >> a[i];
}

void solve()
{
	apre[0] = oo;
	bpre[0] = -oo;
	for (int i = 1; i <= n; ++i)
	{
		apre[i] = min(apre[i - 1], a[i]);
		bpre[i] = max(bpre[i - 1], a[i]);
		//dbgg(apre[i]); dbg(bpre[i]);
	}
	asuf[n + 1] = oo;
	bsuf[n + 1] = -oo;
	for (int i = n; i >= 1; --i)
	{
		asuf[i] = min(asuf[i + 1], a[i]);
		bsuf[i] = max(bsuf[i + 1], a[i]);
		
		//dbgg(asuf[i]); dbg(bsuf[i]);
	}
	
	int ANS;
	int ans;
	for (int i = 1; i <= n; ++i)
	{
		ans = 0;
		ans += a[i] * q;
		if (p <= 0) ans += apre[i] * p;
		else ans += bpre[i] * p;
		if (r <= 0) ans += asuf[i] * r;
		else ans += bsuf[i] * r;
		if (i == 1) ANS = ans;
		else maxeq(ANS, ans); 
	}
	cout << ANS << '\n';
}
main()
{
	input();
	solve();
}