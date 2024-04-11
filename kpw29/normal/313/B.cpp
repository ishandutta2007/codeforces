#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, PLL> PP;
typedef unsigned int ui;
const int mod = 1e9+7;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
#define maxn 4010
int n, m, a, b, c;
int tab[1011000];
string s;
int main()
{
	cin >> s;
	cin >> n;
	for (int i=0; i<s.length(); ++i)
	if (s[i] == s[i+1]) tab[i + 1] = 1;
	else tab[i + 1] = 0;
	for (int i=1; i<s.length(); ++i) tab[i] += tab[i-1];
	for (int i=1; i<=n; ++i)
	{
		cin >> a >> b;
		cout << tab[b-1] - tab[a-1] << '\n';
	}
}