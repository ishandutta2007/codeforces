#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define FOR(i, a, b) for(int i=(a); i<=(b); ++i)
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, PLL> PP;
typedef pair <PII, int> PPI;
typedef unsigned int ui;
typedef vector <int> vi;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
#define maxn 500100
int n, m, c;
PII help[maxn];
vector <int> v[maxn];
int A[maxn], B[maxn], tab[maxn], edges;
map <PII, bool> M;
int Waga[4 * maxn];
inline bool isEdge(int a, int b) {
	return M[{a, b}] == 1;
}

void check()
{
	edges = m;
	FOR(i, 1, n) 
	{
		tab[i] += maxn;
		help[i] = mp(tab[i], i);
	}
	sort(help + 1, help + n + 1);
	FOR(i, 1, n)
	{
		for (int j = i - 1; j > 0; --j)
		{
			if (help[i].e1 - help[j].e1 > 1) break;
			if (isEdge(help[i].e2, help[j].e2)) --edges;
			else OUT("NO");
		}
	}
	if (edges != 0) OUT("NO");
	
	cout << "YES\n";
	FOR(i, 1, n) cout << tab[i] << ' ';
}

int pocz, kon, sr;

void firstPhase()
{
	if (n <= 500) {
	FOR(i, 1, n)
	{
		int mm = (int)v[i].size();
		FOR(jed, 0, mm-1)
			FOR(dwa, jed+1, mm-1)
			{
				if (!isEdge(v[i][jed], v[i][dwa]))
				{
					pocz = v[i][jed];
					sr = i;
					kon = v[i][dwa];
					return;
				}
			}
	}
	}
	else {
		FOR(i, 1, n)
		{
			int mm = (int)v[i].size();
			if (mm < 2) continue;
			FOR(steps, 1, 3 * mm)
			{
				int jed = rand()%mm;
				int dwa = rand()%mm;
				if (jed == dwa)
				{
					if (jed == 0) ++jed;
					else --jed;
				}
				
				if (!isEdge(v[i][jed], v[i][dwa]))
				{
					pocz = v[i][jed];
					sr = i;
					kon = v[i][dwa];
					return;
				}
			}
		}
	}
	
	cout << "YES\n";
	FOR(i, 1, n) cout << 1 << ' ';
	exit(0);
}
bool odw[maxn];

void insert(int x, int w)
{
	tab[x] = w;
	if (Waga[w] == 0) Waga[w] = x;
}
void przypisz(int x, int par)
{
	if (par == 0) return; //base vertex
	par = tab[par];
	if (Waga[par - 1] != 0 && Waga[par + 1] != 0)
	{
		//zostanie nam Waga z par - 1, par lub par + 1.
		if (isEdge(Waga[par - 1], x))
		{
			if (isEdge(Waga[par + 1], x)) insert(x, par);
			else insert(x, par - 1);
		}
		else insert(x, par + 1);
	}
	else if (Waga[par + 1] != 0 && Waga[par + 2] != 0)
	{
		if (isEdge(Waga[par + 1], x))
		{
			if (isEdge(Waga[par + 2], x)) insert(x, par + 1);
			else insert(x, par);
		}
		else insert(x, par - 1);
	}
	else if (Waga[par - 1] != 0 && Waga[par - 2] != 0)
	{
		if (isEdge(Waga[par - 1], x))
		{
			if (isEdge(Waga[par - 2], x)) insert(x, par -1);
			else insert(x, par);
		}
		else insert(x, par + 1);
	}
	else
	{
		assert(1 == 0);
	}
}
void secondPhase()
{
	int L = 2 * maxn;
	tab[sr] = L;
	tab[pocz] = L - 1;
	tab[kon] = L + 1;
	Waga[L] = sr;
	Waga[L - 1] = pocz;
	Waga[L + 1] = kon;
	
	queue <PII> q;
	while (!q.empty()) q.pop();
	q.push(mp(sr, 0)); q.push(mp(pocz, 0)); q.push(mp(kon, 0));
	odw[sr] = 1; odw[pocz] = 1; odw[kon] = 1;
	while (!q.empty())
	{
		int x = (q.front()).e1, par = (q.front()).e2;
		q.pop();
		przypisz(x, par);
		for (auto u : v[x])
			if (!odw[u])
			{
				odw[u] = 1;
				q.push(mp(u, x));
			}
	}
}
int main()
{
	boost;
	cin >> n >> m;
	FOR(i, 1, m)
	{
		cin >> A[i] >> B[i];
		M[{A[i], B[i]}] = 1;
		M[{B[i], A[i]}] = 1;
		v[A[i]].pb(B[i]);
		v[B[i]].pb(A[i]);
	}
	
	firstPhase();
	//cout << pocz << ' ' << sr << ' ' << kon << endl;
	secondPhase();
	check();
}