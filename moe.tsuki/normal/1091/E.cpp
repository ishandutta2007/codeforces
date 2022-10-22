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

const int maxn = 567891;
int n;
int a[maxn];
int r[maxn];
int sufsum[maxn];
int k[maxn];
pii pre[maxn], suf[maxn];
bool bad[maxn];
vi ans;

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	F1 (i, n) cin >> a[i];
}

pii And(pii a, pii b)
{
	return mp(max(a.fi, b.fi), min(a.se, b.se));
}

void solve()
{
	F1 (i, n) a[i] *= -1;
	sort(a + 1, a + n + 1);
	F1 (i, n) a[i] *= -1;
	a[0] = n;
	for (int i = 1; i <= n; ++i)
		r[i] = i * (i - 1);
	

	
	int cur = 0;
	for (int i = 1; i <= n; ++i)
		r[i] -= (cur += a[i]);
	
	for (int i = n; i >= 1; --i) sufsum[i] = a[i] + sufsum[i + 1];
	int parity = sufsum[1] % 2;
	
	cur = n;
	while (a[cur] == 0) --cur;
	
	for (int i = 1; i <= n; ++i)
	{
		while (a[cur] < i && cur > i) --cur;
		cur = max(cur, i);
		r[i] += sufsum[cur + 1];
		r[i] += (cur - i) * i;
	}
	
//for (int i = 1; i <= n; ++i) cout << r[i] << ' ';
//MEOW		
	
	for (int i = 1; i <= n; ++i)
	{
		if (i + r[i] >= 0) pre[i] = mp(-r[i], n);
		else bad[i] = true;
	}
	
	int p = n;
	for (int i = 1; i <= n; ++i)
	{
		while (p >= i && a[p] < i) --p;
		if (p < i) k[i] = 0;
		else k[i] = p - i + 1; 
	}
	
	for (int i = 1; i <= n; ++i)
		suf[i] = mp(0, r[i] + i + i + k[i + 1]);
	
	for (int i = 1; i <= n; ++i)
		if (bad[i - 1]) bad[i] = true;
		
	for (int i = 2; i <= n; ++i)
		pre[i] = And(pre[i], pre[i - 1]);
	for (int i = n - 1; i >= 1; --i)
		suf[i] = And(suf[i + 1], suf[i]);
	
	pre[0] = mp(0, n);
	suf[n + 1] = mp(0, n);
	
//for (int i = 0; i <= n + 1; ++i) cout << a[i] << ' ';
//MEOW	
	
	r[0] = n;
	
	for (int i = 0; i <= n; ++i)
	{
		if (bad[i]) break;
//dbg(i);
		// a[i] ~ a[i + 1]
		// k = i + 1 for own
		int R = r[i]; R += i + i;
		R += k[i + 1];
		// R += those >= k + 1 in a[k + 1] ~ a[n]
		// R - x >= 0
		pii bound = mp(a[i + 1], a[i]);
		
//dbg(bound);
		
		bound = And(bound, mp(0, R));
		
///dbg(bound);
		
		bound = And(bound, pre[i]);
		
//dbg(bound);	
		
		bound = And(bound, suf[i + 1]);
		
//dbg(bound);		
		
		for (int i = bound.fi; i <= bound.se; ++i)
			if ((i & 1) == parity) ans.pb(i);
	}
	sort(all(ans));
	auto e = unique(all(ans));
	if (ans.size())
	{
		for (auto x = ans.begin(); x != e; ++x) cout << *x << ' ';
	}
	else cout << "-1\n";
}

main()
{
	input();
	solve();
}