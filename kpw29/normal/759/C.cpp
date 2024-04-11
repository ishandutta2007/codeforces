#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define FOR(i, a, b) for(int i=(a); i<=(b); ++i)
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, PLL> PP;
typedef pair <PII, int> PPI;
typedef pair <ll, int> PLI;
typedef unsigned int ui;
typedef vector<int> vi;
typedef bitset<51> bset;
const int inf = 1e9+9;
const int mod = 1e9+7;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
#define maxn 1001000
int T, n, m, a, b, c, type, place;

const int R = (1 << 17);
PII dr[2 * R + 5];

void push(int x) {
	dr[2 * x + 1].e2 += dr[x].e2;
	dr[2 * x].e2 += dr[x].e2;
	//max sie tutaj nie zmienia
	dr[2 * x + 1].e1 += dr[x].e2;
	dr[2 * x].e1 += dr[x].e2;
	dr[x].e2  = 0;
}

void insert(int gdzie, int pocz, int kon, int x, int y, ll v) 
{
	if (x <= pocz && y >= kon) {
		//cout << gdzie << ' ' << pocz << ' ' << kon << ' ' << endl;
		dr[gdzie].e1 += v;
		dr[gdzie].e2 += v;
		return;
	}
	push(gdzie);
	int sr = (pocz + kon) >> 1;
	if (x <= sr) insert(gdzie << 1, pocz, sr, x , y, v);
	if (y > sr) insert((gdzie << 1) + 1, sr + 1, kon, x, y, v);
	dr[gdzie].e1 = max(dr[gdzie << 1].e1, dr[(gdzie << 1) + 1].e1) + dr[gdzie].e2;
}

int wyszukaj(int gdzie)
{
	if (gdzie >= R) return gdzie - R + 1;
	push(gdzie);
	dr[gdzie].e1 = max(dr[gdzie << 1].e1, dr[(gdzie << 1) + 1].e1) + dr[gdzie].e2;
	int dwa = 2 * gdzie + 1;
	int wal = 0;
	if (dr[dwa].e1 > 0) wal = wyszukaj(dwa);
	else wal = wyszukaj(dwa - 1);
	dr[gdzie].e1 = max(dr[gdzie << 1].e1, dr[(gdzie << 1) + 1].e1) + dr[gdzie].e2;
	return wal;
}

int tab[maxn];
set <int> miejsca;

int main()
{
	boost;
	miejsca.insert(inf);
	cin >> n;
	FOR(i, 1, n)
	{
		cin >> place >> type;
		if (type == 1) 
		{
			cin >> a;
			tab[place] = a;
			miejsca.insert(place);
			insert(1, 1, R, 1, place, 1);
		}
		if (type == 0)
		{
			insert(1, 1, R, 1, place, -1);
		}

		if (dr[1].e1 <= 0) cout << "-1\n";
		else
		{
			int gdzie = wyszukaj(1);
			//znalezlismy ostatnie miejsce, w ktorym wyn > 0
			//niekoniecznie musi to byc miejsce z tablicy
			//trzeba je teraz znalezc
			set <int>::iterator it = miejsca.upper_bound(gdzie);
			--it;
			cout << tab[*it] << "\n";
		}
	}
}