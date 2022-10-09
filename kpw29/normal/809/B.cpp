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
const ll mod = 1e9+7;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
#define maxn 1001000
int n, k;
bool local = 0;
int tab[maxn];

bool askQuestion(int a, int b)
{
	cout << "1 " << a << ' ' << b << "\n";
	cout.flush();
	string ans;
	if (local)
	{
		int xmax = inf, ymax = inf;
		FOR(i, 1, n)
		if (tab[i]) 
		{
			xmax = min(xmax, abs(a - i));
			ymax = min(ymax, abs(b - i));
		}
		return xmax <= ymax;
	}
	else
	{
		cin >> ans;
		if (ans == "TAK") return 1;
		return 0;
	}
}

void output(int a, int b)
{
	assert(a != b);
	cout << "2 " << a << ' ' << b << "\n";
	cout.flush();
	exit(0);
}

int firstSearch(int x, int y)
{
	while (x < y)
	{
		//cout << "FS: " << x << ' ' << y << endl;
		int sr = (x + y)/2;
		if (askQuestion(sr, sr+1)) y = sr;
		else x = sr + 1;
	}
	return x;
}

int secondSearch(int x, int y)
{
	int initx = x;
	while (x < y)
	{
		int sr = (x + y)/2;
		if (initx == 1)
		{
			if (askQuestion(sr, sr+1)) y = sr;
			else x = sr+1;
		}
		else
		{
			if (askQuestion(sr, sr+1)) y = sr;
			else x = sr+1;
		}
	}
	return x;
}
inline bool checkValid(int x, int y)
{
	if (x == y) return 0;
	if (askQuestion(x, y)) return 1;
	return 0;
}
int kulka, druga;

int main()
{
	ios_base::sync_with_stdio(0);
	cin >> n >> k;
	if (local)
	FOR(i, 1, k)
	{
		int a;
		cin >> a;
		tab[a] = 1;
	}
	kulka = firstSearch(1, n), druga = kulka;
	//kulka na pewno jest dobra kulka
	if (kulka != 1) druga = secondSearch(1, kulka - 1);
	if (!checkValid(druga, kulka)) druga = secondSearch(kulka + 1, n);
	assert(checkValid(druga, kulka));
	output(druga, kulka);
}