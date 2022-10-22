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

int n, k;
int ans, comp;
map<int, int> m;

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k;
}

int gao(int l, int r, int k)
{
//dbgg(l); dbgg(r); dbg(k); MEOW 
	int mid = (l + r + 1) / 2;
	if ((r - l + 1 == ans || r - l + 1 == comp) && k == 1) return mid;
	if (m[mid - l] >= k) return gao(l, mid - 1, k);
	else return gao(mid, r, k - m[mid - l] - ((mid == l + 1) ? 1 : 0));
}

void solve()
{
	if (k == 1) { cout << "1\n"; return; }
	if (k == 2) { cout << n << '\n'; return; }
	--n;
	k -= 2;
	m.clear();
	m[n] = 1;
	queue<int> pq;
	pq.push(n);
	int kk = k, fnd;
	while (!pq.empty())
	{
		int cur = pq.front();
		pq.pop();
		int num = m[cur];
		if (cur > 2)
			if (!m.count((cur + 1) / 2)) 
			{
				pq.push((cur + 1) / 2);
				m[(cur + 1) / 2] = num; 
			} else m[(cur + 1) / 2] += num;
		if (cur > 3)
			if (!m.count(cur / 2)) 
			{
				pq.push(cur / 2);
				m[cur / 2] = num; 
			} else m[cur / 2] += num;
			
//dbgg(cur); dbg(num);	
			
		if (kk > 0) ans = cur, fnd = kk;
		kk -= num;
	}

	comp = ans;
	if (ans & 1) --comp;
	else ++comp;
	if (m.count(comp) && (comp & 1)) fnd += m[comp];
	
//dbg(ans);
//dbg(fnd);
	
	for (auto x : m)
	{
		if (x.fi == ans) m[x.fi] = 1;
		else if (x.fi == comp) m[x.fi] = 1;
		else m[x.fi] = 0;
		m[x.fi] += m[(x.fi + 1) / 2] + m[x.fi / 2];

//dbgg(x.fi); dbg(m[x.fi]);		

	}
	cout << gao(1, n, fnd) << '\n';
}

main()
{
	input();
	solve();
}