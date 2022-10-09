#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost {ios_base::sync_with_stdio(false);}
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define FOR(i, a, b) for(int i=(a); i<=(b); ++i)
#define scanf(...) scanf(__VA_ARGS__)?:0
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PII, PII> PP;
typedef pair <PII, int> PPI;
typedef pair <int, PII> PIP;
typedef pair <ll, int> PLI;
typedef unsigned int ui;
typedef vector <int> vi;
const int mod = 1e9+7;
const int inf = 1e9+10;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
const int W = 1e9;
#define maxn 1000100

int n, m, k, a, b, c;
int tab[maxn];
ll N, M, K, P, Q;

int main()
{
	boost;
	cin >> n;
	FOR(i, 1, n) cin >> tab[i];
	sort(tab+1, tab+n+1);
	if (tab[1] == tab[n]) OUT(0);
	int wsk = 1;
	while (tab[wsk] == tab[1]) ++wsk;
	int el = n;
	while (tab[el] == tab[n]) --el;
	cout << el - wsk + 1;
}