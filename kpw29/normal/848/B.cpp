#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define scanf(...) scanf(__VA_ARGS__)?:0
typedef long long int ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, int> PLLI;
typedef pair <PLL, PLL> PP;
typedef pair <PII, int> PPI;
typedef pair <ll, int> PLI;
typedef unsigned int ui;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const long long INF = 1e18+3;
int n, w, h, m, k, a, b, c, DL = 0, T;
#define maxn 1000100
PII tab[maxn];

PII ans[maxn];
map <int, vector <PII> > M;
map <int, vector <PII> > pozycje;

bool cmp(PII a, PII b) {
	return a.e1 - a.e2 < b.e1 - b.e2;
}

int main()
{
	M.clear();
	boost;
	cin >> n >> w >> h;
	FOR(i, 1, n)
	{
		int type, pi, czas;
		cin >> type >> pi >> czas;
		PII wspol = mp(0, pi);
		if (type == 1) wspol = mp(pi, -czas);
		else wspol = mp(-czas, pi);
		M[wspol.e1 + wspol.e2].push_back(mp(wspol.e1, i));
		if (type == 1) pozycje[wspol.e1 + wspol.e2].push_back(mp(wspol.e1, h));
		else if (type == 2) pozycje[wspol.e1 + wspol.e2].push_back(mp(w, wspol.e2));
	}
	
	for (auto u : M)
	{
		int suma = u.e1;
		auto vec = pozycje[suma];
		sort(vec.begin(), vec.end(), cmp);
		sort(u.e2.begin(), u.e2.end());
		//cout << (int)u.e2.size() << endl;
		
		auto it = vec.begin();
		for (auto ww : u.e2)
		{
			//cout << "Mam punkt: " << ww.e1 << ' ' << ww.e2 << endl;
			//cout << endl;
			ans[ww.e2] = *it;
			++it;
		}
		//cout << endl;
	}
	
	for (int i=1; i<=n; ++i) cout << ans[i].e1 << ' ' << ans[i].e2 << "\n";
}