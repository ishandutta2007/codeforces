#include<bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define pb push_back
#define eb emplace_back
#define rep(i,a,b) for(auto i = (a); i != (b); ++i)
#define all(v) (v).begin(), (v).end()

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

void run()
{
	int h, m, s, t1, t2;
	cin >> h >> m >> s >> t1 >> t2;
	h = h * 3600 + m * 60 + s;
	t1 = t1 * 3600;
	t2 = t2 * 3600;
	m = 12 * (m * 60 + s);
	s = 12 * 60 * s;

	const int mod = 12 * 60 * 60;
	h = h % mod;
	m = m % mod;
	s = s % mod;
	t1 = t1 % mod;
	t2 = t2 % mod;

	if (t1 > t2) swap(t1, t2);
	assert(t1 != h && t1 != m && t1 != s);
	assert(t2 != h && t2 != m && t2 != s);

	bool can1 = true, can2 = true;

	cerr << t1 << " -> " << t2 << ", " << h << " " << m << " "<< s << endl;

	can1 &= (h < t1 || t2 < h);
	can1 &= (m < t1 || t2 < m);
	can1 &= (s < t1 || t2 < s);

	can2 &= (t1 < h && h < t2);
	can2 &= (t1 < m && m < t2);
	can2 &= (t1 < s && s < t2);

	cout << (can1 || can2 ? "YES" : "NO") << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	(cout << fixed).precision(18);

	run();

	return 0;
}