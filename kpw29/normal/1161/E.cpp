#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define REYNA(i,a,b) for(int i=(a);i<(b);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define scanf(...) scanf(__VA_ARGS__)?:0
typedef long long int ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, int> PLLI;
typedef pair <PLL, pair <int, ll> > PP;
typedef pair <PII, int> PPI;
typedef pair <int, PII> PIP;
typedef pair <ll, int> PLI;
typedef unsigned int ui;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const long long INF = 1e18+3;
const int maxn = 200100;

vector<int> ask(vector <PII> v) {
	cout << "Q " << (int)v.size() << ' ';
	int sz = v.size();
	for (int i=0; i+1<sz; ++i) cout << v[i].e1 << ' ' << v[i].e2 << ' ';
	cout << v[sz-1].e1 << ' ' << v[sz-1].e2 << endl;
	vector <int> ret;
	string s;
	cin >> s;
	for (int i=0; i<sz; ++i)
		if (s[i] == '1') ret.pb(1);
		else ret.pb(0);
	
	return ret;
}

int par[maxn];
int color[maxn], n;
int REL1[maxn], REL2[maxn];

vector <int> vec[4];

void printVec(int i)
{
	int sz = vec[i].size();
	if (sz == 0) {
		cout << endl;
		return;
	}
	
	FOR(a, 0, sz-2) cout << vec[i][a] << ' ';
	cout << vec[i][sz-1] << endl;
}
int T;

void solveOne()
{
	cin >> n;
	FOR(i, 0, 100000) par[i] = color[i] = REL1[i] = REL2[i] = 0;
	vector <int> sciezka;
	
	vector <PII> xd;
	vector <PII> sec;
	FOR(i, 2, n)
	{
		if (i % 2) xd.pb({i-1, i});
		else sec.pb({i-1, i});
	}
	
	vector <int> jed = {};
	if (xd.size()) jed = ask(xd);
	vector <int> dwa = {};
	if (sec.size()) dwa = ask(sec);
	
	for (int i=n; i>=2; --i)
	{
		if (i % 2) REL1[i] = jed.back(), jed.pop_back();
		else REL1[i] = dwa.back(), dwa.pop_back();
	}
	
	sciezka.pb(1);
	FOR(i, 2, n) {
		if (REL1[i] == 1) par[i] = sciezka.back();
		else sciezka.pb(i);
	}
	//cout << "SCIE\n";
	//for (auto u : sciezka) cout << u << ' ';
	xd = {}; sec = {};
	dwa = {}; jed = {};
	int sz = sciezka.size();
	FOR(i, 2, sz-1) {
		int r = i % 4;
		if (r < 2) xd.pb({sciezka[i], sciezka[i-2]});
		else sec.pb({sciezka[i], sciezka[i-2]});
	}
	
	if (xd.size()) jed = ask(xd);
	if (sec.size()) dwa = ask(sec);
	for (int i=sz-1; i>=2; --i) {
		int r = i % 4;
		if (r < 2) REL2[i] = jed.back(), jed.pop_back();
		else REL2[i] = dwa.back(), dwa.pop_back();
	}
	
	color[sciezka[0]] = 1;
	if (sz > 1) color[sciezka[1]] = 2;
	FOR(i, 2, sz-1)
	{
		if (REL2[i]) color[sciezka[i]] = color[sciezka[i-2]];
		else color[sciezka[i]] = (color[sciezka[i-1]] ^ color[sciezka[i-2]]);
	}
	
	FOR(i, 1, n)
		if (par[i]) color[i] = color[par[i]];
	
	FOR(i, 1, 3) vec[i].clear();
	FOR(i, 1, n) vec[color[i]].pb(i);
	cout << "A " << vec[1].size() << ' ' << vec[2].size() << ' ' << vec[3].size() << endl;
	FOR(i, 1, 3)printVec(i);
}
//5
//RRRGGGRRBRRBRGGBRBRRRRGGRBRRGBRRRGGRRRRBGGRGGBGGRR
//1100
//10110
int main()
{
	boost;
	cin >> T;
	for (int i=1; i<=T; ++i) solveOne();
}