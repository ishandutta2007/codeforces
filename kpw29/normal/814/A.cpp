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
#define maxn 1000100
int tab[maxn];
ll n, m, k, a, b, c;

int main()
{
	boost;
	cin >> n >> k;
	FOR(i, 1, n) cin >> tab[i];
	if (k > 1) OUT("Yes");
	cin >> a;
	FOR(i, 1, n) 
		if (tab[i] == 0) tab[i] = a;
	
	bool ans = 1;
	FOR(i, 1, n-1)
		if (tab[i] >= tab[i+1]) ans = 0;
	
	if (ans) cout << "No";
	else cout << "Yes";
}